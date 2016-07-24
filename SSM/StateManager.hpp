#pragma once
#include <stack>

#include "State.hpp"

class StateManager {
public:
	StateManager();
	~StateManager();

	void pushState(State* state);
	void popState();
	void changeState(State* state);

	void processEvents();
	void update(sf::Time dt);
	void draw();

	void stateToChangeTo(State* state);
	State* getCurrentState() { return m_states.top(); }

	bool running()	{ return m_running; }
	void quit()		{ m_running = false; }

	bool isChangingState()	{ return m_changingState; }
	State* getNewState()	{ return m_newState; }
private:
	std::stack<State*> m_states;
	State* m_newState;
	bool m_running;
	bool m_changingState;
};