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

bool InputManager::mouseDown(int mouseButton)
{
	if (mouseButton)
	{
		if (mouse.curLMB)
			return true;
	}
	else {
		if (mouse.curRMB)
			return true;
	}
	return false;
}

bool InputManager::mouseUp(int mouseButton)
{
	if (mouseButton)
	{
		if (!mouse.curLMB)
			return true;
	}
	else {
		if (!mouse.curRMB)
			return true;
	}
	return false;
}

bool InputManager::mousePress(int mouseButton)
{
	if (mouseButton)
	{
		if (mouse.curLMB && !mouse.prevLMB)
			return true;
	}
	else {
		if (mouse.curRMB && !mouse.prevRMB)
			return true;
	}
	return false;
}

bool InputManager::mouseRelease(int mouseButton)
{
	if (mouseButton)
	{
		if (!mouse.curLMB && mouse.prevLMB)
			return true;
	}
	else {
		if (!mouse.curRMB && mouse.prevRMB)
			return true;
	}

	return false;
}

sf::Vector2i InputManager::mousePosition()
{
	return mouse.position;
}

void InputManager::stateUpdate(sf::RenderWindow* window)
{
	std::map<int, Key*>::iterator it;

	// Update previous state with current state at end up update
	for (it = keys.begin(); it != keys.end(); it++)
	{
		Key* k = it->second;
		k->prevState = k->curState;
	}

	mouse.position = sf::Mouse::getPosition(*window);

	mouse.prevLMB = mouse.curLMB;
	mouse.prevRMB = mouse.curRMB;
}

void InputManager::krUpdate(sf::Event e)
{
	if (e.type == sf::Event::KeyReleased)
		keys.find(e.key.code)->second->curState = 0;

	if (e.type == sf::Event::KeyPressed)
		keys.find(e.key.code)->second->curState = 1;

	if (e.mouseButton.button == sf::Mouse::Right)
		if (e.type == sf::Event::MouseButtonPressed)
			mouse.curRMB = 1;
		else
			mouse.curRMB = 0;
	
	if (e.mouseButton.button == sf::Mouse::Left)
		if (e.type == sf::Event::MouseButtonPressed)
			mouse.curLMB = 1;
		else
			mouse.curLMB = 0;
}
