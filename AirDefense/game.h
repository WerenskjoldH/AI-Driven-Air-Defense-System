#ifndef GAME_H
#define GAME_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "consoleColorer.h"

class Game
{
private:
	// The render window that all data will be written to
	sf::RenderWindow window;

	// This is the default font we will use
	sf::Font font;

	void initialize();
	void initializeWindowSettings(sf::RenderWindow& window);

	void update();

	void draw();

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
