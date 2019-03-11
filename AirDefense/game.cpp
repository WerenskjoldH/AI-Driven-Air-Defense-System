#include "game.h"

void Game::initialize()
{
	// Error message is built into function
	font.loadFromFile("Fonts/slkscr.ttf");

	initializeSimulationSettings();

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
		}

		sf::Time elapsed = clock.restart();

		update(elapsed.asSeconds());
		
		draw(&window);
	}
}

void Game::draw(sf::RenderWindow* window)
{
	// Example drawing code

}

void Game::update(float dt)
{
	
}