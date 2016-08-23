#include <SFML/Window/Event.hpp>
#include <iostream>

#include "GameState.hpp"

GameState::GameState(StateManager& stateManager, sf::RenderWindow& window)
	: State{ stateManager, window } {
	std::cout << "[GameState] Initialized" << std::endl;
}

void GameState::pause() {

}

void GameState::resume() {

}

void GameState::processEvents() {
	sf::Event event;

	while (m_window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			m_stateManager.quit();
			break;
		case sf::Event::KeyPressed:
			switch (event.key.code) {
				case sf::Keyboard::Escape:
					m_stateManager.quit();
					break;
			}
		}
	}
}

void GameState::update(const sf::Time& dt) {

}

void GameState::draw() {
	m_window.clear(sf::Color::Black);
	m_window.display();
}