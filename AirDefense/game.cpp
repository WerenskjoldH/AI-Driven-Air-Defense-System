#include "game.h"
#include "cityObject.h"
#include "radarObject.h"
#include "MissileObject.h"
#include "projectileSpawnerObject.h"

#include <stdio.h>
#include <math.h>

void Game::initialize()
{
	// Error message is built into function
	defaultFont.loadFromFile("Fonts/slkscr.ttf");

	circle.setFillColor(sf::Color(80, 80, 80, 255));
	circle.setRadius(5);

	mousePositionText.setCharacterSize(18);
	mousePositionText.setPosition(0, 0);

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
	IM.addKey(sf::Keyboard::B);
}

void Game::initializeSimulationSettings()
{
	world = new World(WINDOW_WIDTH, WINDOW_HEIGHT);

	DefenseSystemObject* dso = new DefenseSystemObject();
	defenseSystem = dso;
	world->addObject((WorldObject*)dso);

}

void Game::reset()
{
	world->resetWorldAndRegenerateGeography();

	DefenseSystemObject* dso = new DefenseSystemObject();
	defenseSystem = dso;
	world->addObject((WorldObject*)dso);
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
		return;
	}

	// Regenerate landmasses
	if (IM.keyRelease(sf::Keyboard::R))
	{
		SET_FONT_COLOR(FONT_YELLOW);
		printf("World is currently regenerating...\n");
		SET_FONT_COLOR();

		reset();

		SET_FONT_COLOR(FONT_GREEN);
		printf("World has been generated\n");
		SET_FONT_COLOR();
	}

	// Print simulation info
	if (IM.keyPress(sf::Keyboard::I))
	{
		SET_FONT_COLOR(FONT_GREEN);
		printf("+================================================+\n");
		printf("\t\t World Information\n");
		printf("+================================================+\n\n");
		SET_FONT_COLOR();
		printf("Number of Objects: %i\n\n", world->getNumberOfLivingObjects());

		
		for (int i = 0; i < world->getNumberOfLivingObjects(); i++)
		{
			if (world->getWorldObjects().at(i)->getObjectType() != "CityObject")
				continue;
			
			CityObject* cityTemp = (CityObject*)world->getWorldObjects().at(i);

			printf("City %i: \n", i+1);
			printf("-------------------------------------------------\n");
			printf("Position: <%i, %i>\n", (int)cityTemp->getPosition().x, (int)cityTemp->getPosition().y);
			printf("Population: %i\n", cityTemp->getPopulation());
			printf("-------------------------------------------------\n");
		}

	}
	
	if (IM.keyRelease(sf::Keyboard::B))
	{
		world->addObject((WorldObject*)new ProjectileSpawnerObject());
	}

	// Left-clicking the mouse adds a radar
	if (IM.mousePress(MOUSE_LMB) && world->checkIfLandAtMouse())
	{
		defenseSystem->addRadar(IM.mousePosition().x, IM.mousePosition().y, world);
	}

	// Right-clicking the mouse adds a SAM site
	/// TODO
	
	world->update(window, dt);
}

void Game::draw(sf::RenderWindow* window)
{
	world->draw(window);

	// TODO: Migrate this code so that we only draw and don't reinstantiate each draw. This is ~super~ inefficient!

	// Draw the mouse
	circle.setPosition(float(IM.mousePosition().x - 5), float(IM.mousePosition().y - 5));
	window->draw(circle);

	// Draw mouse position
	mousePositionText.setFont(defaultFont);
	
	sprintf_s(buffer, "Mouse Position: <%i, %i>", int(IM.mousePosition().x), int(IM.mousePosition().y));

	mousePositionText.setString(buffer);
	window->draw(mousePositionText);
}

Game::Game()
{
	initialize();
}

Game::~Game()
{
}
