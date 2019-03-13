#include "game.h"

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
	
	// It's best to restrict framerate incase any physics gets tied to it
	window->setFramerateLimit(60);
}

void Game::initializeKeyboardSettings()
{
	IM.addKey(sf::Keyboard::Space);
}

void Game::initializeSimulationSettings()
{
	world = new Geography(WINDOW_WIDTH, WINDOW_HEIGHT, 6, 1, 1, 0.4);
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

	if (IM.keyPress(sf::Keyboard::Space))
	{
		SET_FONT_COLOR(FONT_BLUE);
		printf("Land is regenerating...\n");
		SET_FONT_COLOR();
	}

	// Regenerate landmasses
	if (IM.keyRelease(sf::Keyboard::Space))
	{
		srand(std::time(0));
		world->regenerate(rand() % 10000);
		SET_FONT_COLOR(FONT_GREEN);
		printf("Land has been regenerated\n");
		SET_FONT_COLOR();
	}

	if (IM.mousePress(MOUSE_LMB))
	{
		if (world->checkIfLand(IM.mousePosition().x, IM.mousePosition().y))
			printf("You clicked land!\n");
		else
			printf("You clicked water!\n");
	}
	
}

void Game::draw(sf::RenderWindow* window)
{
	world->drawLand(window);

	sf::CircleShape circle(10);
	circle.setFillColor(sf::Color(0,0,255,255));
	circle.setPosition(float(IM.mousePosition().x - 10), float(IM.mousePosition().y - 10));

	window->draw(circle);
}