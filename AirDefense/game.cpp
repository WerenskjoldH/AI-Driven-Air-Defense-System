#include "game.h"

void Game::initialize()
{
	// Error message is built into function
	font.loadFromFile("Fonts/slkscr.ttf");

	initializeSimulationSettings();

	// Setup Keyboard
	InputManager::getInstance().addKey(sf::Keyboard::Space);

}

void Game::initializeWindowSettings(sf::RenderWindow* window)
{
	window->create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Air Defense - Carson Wilber and Hunter Werenskjold", sf::Style::Titlebar | sf::Style::Close);
	
	// It's best to restrict framerate incase any physics gets tied to it
	window->setFramerateLimit(60);
}

void Game::initializeSimulationSettings()
{

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

			InputManager::getInstance().krUpdate(e);
		}

		sf::Time elapsed = clock.restart();

		update(&window, elapsed.asSeconds());
		
		draw(&window);

		InputManager::getInstance().stateUpdate();
	}
}

void Game::update(sf::RenderWindow* window, float dt)
{
	if (InputManager::getInstance().keyRelease(sf::Keyboard::Escape))
	{
		printf("\n\n+================================================+\n");
		printf("\t\t  Closing Game\n");
		printf("+================================================+\n\n");
		window->close();
	}

	if (InputManager::getInstance().keyPress(sf::Keyboard::Space))
		printf("Space was pressed\n");
	if (InputManager::getInstance().keyRelease(sf::Keyboard::Space))
		printf("Space is released\n");

	
}

void Game::draw(sf::RenderWindow* window)
{

}