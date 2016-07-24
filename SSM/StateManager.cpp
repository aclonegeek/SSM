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

void StateManager::pushState(State* state) {
	m_states.push(state);
}

void StateManager::popState() {
	std::cout << "deleted: " << m_states.top();
	delete m_states.top();
	m_states.pop();
}

void StateManager::changeState(State* state) {
	if (!m_states.empty())
		popState();
	pushState(state);

	m_changingState = false;
}

void StateManager::stateToChangeTo(State* state) {
	m_newState = state;
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