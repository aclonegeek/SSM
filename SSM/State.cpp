#include "State.hpp"

State::State(StateManager& stateManager, sf::RenderWindow& window)
	: m_stateManager{ stateManager }
	, m_window{ window } {}