#include "game.h"
#include "noiseGenerator.h"

sf::Image world;
void Game::initialize()
{
	// Error message is built into function
	font.loadFromFile("Fonts/slkscr.ttf");

	initializeSimulationSettings();

	// Setup Keyboard
	IM.addKey(sf::Keyboard::Space);

	world.create(WINDOW_WIDTH, WINDOW_HEIGHT, sf::Color::White);
	setHeightfield(&world, WINDOW_WIDTH, WINDOW_HEIGHT);

	
	

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
	if (IM.keyRelease(sf::Keyboard::Escape))
	{
		printf("\n\n+================================================+\n");
		printf("\t\t  Closing Game\n");
		printf("+================================================+\n\n");
		window->close();
	}

	// Input Testing - Will be removed
	if (IM.keyPress(sf::Keyboard::Space))
		printf("Space was pressed\n");
	if (IM.keyRelease(sf::Keyboard::Space))
		printf("Space is released\n");
	
	if (IM.mousePress(MOUSE_LMB))
		printf("Mouse LMB was pressed at location <%i, %i>\n", IM.mousePosition().x, IM.mousePosition().y);

	if (IM.mousePress(MOUSE_RMB))
		printf("Mouse RMB was pressed at location <%i, %i>\n", IM.mousePosition().x, IM.mousePosition().y);

	if (IM.mouseRelease(MOUSE_LMB))
		printf("Mouse LMB was released at location <%i, %i>\n", IM.mousePosition().x, IM.mousePosition().y);

	if (IM.mouseRelease(MOUSE_RMB))
		printf("Mouse RMB was released at location <%i, %i>\n", IM.mousePosition().x, IM.mousePosition().y);
	
}

void Game::draw(sf::RenderWindow* window)
{

	// Remove the texture and sprite initializations from here as soon as possible, just here for testing
	sf::Texture texture;
	texture.create(WINDOW_WIDTH, WINDOW_HEIGHT);
	texture.update(world);

	sf::Sprite sprite;
	sprite.setTexture(texture);

	window->draw(sprite);

	sf::CircleShape circle(10);
	circle.setFillColor(sf::Color(0,0,255,255));
	circle.setPosition(float(IM.mousePosition().x - 10), float(IM.mousePosition().y - 10));

	window->draw(circle);
}