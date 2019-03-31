#include "game.h"

#include "worldObjectFactory.h"

void Game::initialize()
{
	// Error message is built into function
	defaultFont.loadFromFile("Fonts/slkscr.ttf");

	initializeKeyboardSettings();
	initializeSimulationSettings();
}

void Game::initializeWindowSettings(sf::RenderWindow* window)
{
	window->create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Air Defense - Carson Wilber and Hunter Werenskjold", sf::Style::Titlebar | sf::Style::Close);
	
	window->setMouseCursorVisible(IS_MOUSE_VISIBLE);

	// It's best to restrict framerate incase any physics gets tied to it
	window->setFramerateLimit(60);
}

void Game::initializeKeyboardSettings()
{
	IM.addKey(sf::Keyboard::Space);
	IM.addKey(sf::Keyboard::R);
	IM.addKey(sf::Keyboard::I);
}

void Game::initializeSimulationSettings()
{
	//world = new Geography(WINDOW_WIDTH, WINDOW_HEIGHT, 6, 0.9, 1, 0.4);
	world = new World(WINDOW_WIDTH, WINDOW_HEIGHT);
}

void Game::begin()
{
	/// Initializations

	// The render window that all data will be written to
	sf::RenderWindow window;

	initializeWindowSettings(&window);

	// This will be used to track delta time between frames
	sf::Clock clock;

	/// Game Loop Logic

	// This is the Game Loop
	while (window.isOpen())
	{
		sf::Event e;

		// While there are events in queue
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				window.close();
			}

			IM.krUpdate(e);
		}

		sf::Time elapsed = clock.restart();

		update(&window, elapsed.asSeconds());
		
		window.clear(BACKGROUND_COLOR);

		draw(&window);

		window.display();

		IM.stateUpdate(&window);
	}
}

void Game::update(sf::RenderWindow* window, float dt)
{
	// Close the game
	if (IM.keyRelease(sf::Keyboard::Escape))
	{
		printf("\n\n+================================================+\n");
		printf("\t\t  Closing Game\n");
		printf("+================================================+\n\n");
		window->close();
	}

	// Regenerate landmasses
	if (IM.keyRelease(sf::Keyboard::Space))
	{
		srand(std::time(0));
		world->regenerateGeography(rand() % 10000);
		SET_FONT_COLOR(FONT_GREEN);
		printf("Land has been regenerated\n");
		SET_FONT_COLOR();
	}

	if (IM.keyPress(sf::Keyboard::I))
	{
		SET_FONT_COLOR(FONT_GREEN);
		printf("+================================================+\n");
		printf("\t\t World Information\n");
		printf("+================================================+\n\n");
		SET_FONT_COLOR();
		printf("Number of Objects: %i\n\n", world->getNumberOfLivingObjects());
	}

	if (IM.keyRelease(sf::Keyboard::R))
	{
		world->resetWorld();
	}

	if (IM.mousePress(MOUSE_LMB))
	{
		if (world->checkIfLandAtMouse())
			printf("You clicked land!\n");
		else
			printf("You clicked water!\n");
	}

	if (IM.mousePress(MOUSE_RMB))
	{
		world->addObject(createTestObject(IM.mousePosition().x, IM.mousePosition().y));
	}
	
	world->update(window, dt);
}

void Game::draw(sf::RenderWindow* window)
{
	world->draw(window);

	sf::CircleShape circle(5);
	circle.setFillColor(sf::Color(80,80,80,255));
	circle.setPosition(float(IM.mousePosition().x - 5), float(IM.mousePosition().y - 5));

	window->draw(circle);
}