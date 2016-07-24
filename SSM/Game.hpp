#pragma once
#include <SFML/Graphics.hpp>

#include "StateManager.hpp"
#include "MenuState.hpp"

class Game {
public:
	Game() {}
	void run();
private:
	static const sf::Time TimePerFrame;

	StateManager m_stateManager;
	sf::RenderWindow m_window;
};