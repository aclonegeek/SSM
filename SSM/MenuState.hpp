#pragma once
#include "StateManager.hpp"

class MenuState : public State {
public:
	MenuState(StateManager& stateManager, sf::RenderWindow& window);

	void pause();
	void resume();

	void processEvents();
	void update(const sf::Time& dt);
	void draw();
};
