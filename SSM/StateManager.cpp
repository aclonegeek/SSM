#include <iostream>

#include "StateManager.hpp"

StateManager::StateManager() 
	: m_running{ true } {
	std::cout << "[StateManager] Initialized" << std::endl;
}

StateManager::~StateManager() {
	std::cout << "[StateManager] Destroyed" << std::endl;

	while (!m_states.empty())
		popState();
}

void StateManager::pushState(std::unique_ptr<State> state) {
	m_states.push(std::move(state));
}

void StateManager::popState() {
	m_states.pop();
}

void StateManager::changeState(std::unique_ptr<State> state) {
	if (!m_states.empty())
		popState();
	pushState(std::move(state));

	m_changingState = false;
}

void StateManager::stateToChangeTo(std::unique_ptr<State> state) {
	m_newState = std::move(state);
	m_changingState = true;
}

void StateManager::processEvents() {
	m_states.top()->processEvents();
}

void StateManager::update(sf::Time dt) {
	m_states.top()->update(dt);
}

void StateManager::draw() {
	m_states.top()->draw();
}