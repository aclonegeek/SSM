#pragma once
#include "State.hpp"
#include "StateManager.hpp"

class GameState : public State {
public:
	GameState(StateManager& stateManager, sf::RenderWindow& window);

	void pause();
	void resume();

	void processEvents();
	void update(sf::Time dt);
	void draw();
};
