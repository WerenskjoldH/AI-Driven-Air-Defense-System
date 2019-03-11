#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <SFML/Graphics.hpp>

#include <map>
#include <stdio.h>
#include <iostream>

/*
	This is a singleton class that handles all user input from keyboard and mouse

	I know singletons are often discouraged, but this is an instance (aha) where it is very versatile and welcomed
*/

struct Key
{
	bool curState;
	bool prevState;

	Key() : curState{0}, prevState{0} {}
};

class InputManager
{
private:
	std::map<int, Key*> keys;

	InputManager()
	{
		// Add esc key
		addKey(sf::Keyboard::Escape);
	}

	bool isBound(int key);	

public:
	static InputManager& getInstance()
	{
		static InputManager instance;
		return instance;
	}

	InputManager(InputManager  const&) = delete;
	void operator=(InputManager const&) = delete;

	// By adding keys we are able to reduce the space used
	// i.e. if we never use the s key why have it in memory?
	void addKey(sf::Keyboard::Key key);

	// Check key state
	bool keyDown(int key);
	bool keyUp(int key);
	bool keyPress(int key);
	bool keyRelease(int key);

	// Keeps track of key states
	void stateUpdate();
	// Keeps track of key events
	void krUpdate(sf::Event e);

};

#endif