#ifndef GAME_H
#define GAME_H

#define WINDOW_WIDTH	800
#define WINDOW_HEIGHT	800

#define BACKGROUND_COLOR sf::Color::Black

#define IM InputManager::getInstance()


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "consoleColorer.h"
#include "inputManager.h"
#include "geography.h"

class Game
{
private:
	// This is the default font we will use
	sf::Font defaultFont;

	// Geography data, this should be refactored into a World class later on
	Geography* world;

	void initialize();
	void initializeWindowSettings(sf::RenderWindow* window);
	void initializeKeyboardSettings();
	void initializeSimulationSettings();

	// All game logic
	void update(sf::RenderWindow* window, float dt);

	// All rendering
	void draw(sf::RenderWindow* window);

public:
	// We will define the constructor and destructor locally in the header file
	Game()
	{
		initialize();
	}

	~Game() {}

	void begin();
};

#endif // !GAME_H
