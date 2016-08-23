#pragma once
#include "StateManager.hpp"

class GameState : public State {
public:
	GameState(StateManager& stateManager, sf::RenderWindow& window);

	void pause();
	void resume();

	void processEvents();
	void update(const sf::Time& dt);
	void draw();
};
