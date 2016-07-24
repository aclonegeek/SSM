#pragma once
#include <stack>
#include <memory>

#include "State.hpp"

class StateManager {
public:
	StateManager();
	~StateManager();

	void pushState(std::unique_ptr<State> state);
	void popState();
	void changeState(std::unique_ptr<State> state);

	void processEvents();
	void update(sf::Time dt);
	void draw();

	void stateToChangeTo(std::unique_ptr<State> state);
	std::unique_ptr<State> getCurrentState()				{ return std::move(m_states.top()); }

	bool running()											{ return m_running; }
	void quit()												{ m_running = false; }

	bool isChangingState()									{ return m_changingState; }
	std::unique_ptr<State> getNewState()					{ return std::move(m_newState); }
private:
	std::stack<std::unique_ptr<State>> m_states;
	std::unique_ptr<State> m_newState;
	bool m_running;
	bool m_changingState;
};