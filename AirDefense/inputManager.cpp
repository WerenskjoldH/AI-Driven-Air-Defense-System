#include "inputManager.h"

bool InputManager::isBound(int key)
{
	if (InputManager::keys.find(key) != InputManager::keys.end())
		return true;
	return false;
}

void InputManager::addKey(sf::Keyboard::Key key)
{
	if (!InputManager::isBound(key))
		InputManager::keys.insert(std::make_pair(int(key), new Key()));
}

bool InputManager::keyDown(int key)
{
	if (!InputManager::isBound(key))
		return false;

	if (InputManager::keys.find(key)->second->curState)
		return true;

	return false;
}

bool InputManager::keyUp(int key)
{
	if (!InputManager::isBound(key))
		return false;

	if (!InputManager::keys.find(key)->second->curState)
		return true;

	return false;
}

bool InputManager::keyPress(int key)
{
	if (!InputManager::isBound(key))
		return false;

	if (InputManager::keys.find(key)->second->prevState == 0 && InputManager::keys.find(key)->second->curState == 1)
		return true;

	return false;
}

bool InputManager::keyRelease(int key)
{
	if (!InputManager::isBound(key))
		return false;

	if (InputManager::keys.find(key)->second->prevState == 1 && InputManager::keys.find(key)->second->curState == 0)
		return true;

	return false;
}

void InputManager::stateUpdate()
{
	std::map<int, Key*>::iterator it;

	// Update previous state with current state at end up update
	for (it = keys.begin(); it != keys.end(); it++)
	{
		Key* k = it->second;
		k->prevState = k->curState;
	}
}

void InputManager::krUpdate(sf::Event e)
{
	if (e.type == sf::Event::KeyReleased)
		keys.find(e.key.code)->second->curState = 0;

	if (e.type == sf::Event::KeyPressed)
		keys.find(e.key.code)->second->curState = 1;
}
