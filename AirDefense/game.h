#ifndef GAME_H
#define GAME_H

#define WINDOW_WIDTH	800
#define WINDOW_HEIGHT	800

#define IS_MOUSE_VISIBLE false

#define BACKGROUND_COLOR sf::Color::Black

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include "world.h"
#include "defenseSystemObject.h"

class Game
{
private:
	// This is the default font we will use
	sf::Font defaultFont;

	// This is where we will print the mouse X,Y Coordinates
	sf::Text mousePositionText;

	// When smart pointers are implemented, this might also benefit from becoming an std::string instead
	char buffer[100];

	// This will be used to replace the mouse pointer
	sf::CircleShape circle;

	World *world;

	DefenseSystemObject* defenseSystem;

	// Handles initilization of internal objects and dependencies
	void initialize();

	/*
		Initializes all settings relating to the RenderWindow
		@param window The RenderWindow that will be initialized
	*/
	void initializeWindowSettings(sf::RenderWindow* window);
	void initializeKeyboardSettings();
	void initializeSimulationSettings();

	void reset();

	/*
		Contains all update logic
		@param window The RenderWindow we will be referencing, do NOT put draw calls here
		@param dt the delta time between frames -- this can be static or dynamic
	*/
	void update(sf::RenderWindow* window, float dt);

	/*
		Contains all rendering logic
		@param window The RenderWindow that we will be drawing to
	*/
	void draw(sf::RenderWindow* window);

public:
	Game();

	~Game();

	// Call this on the Game object to begin the simulation
	void begin();
};

#endif // !GAME_H
