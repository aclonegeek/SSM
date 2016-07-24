#include <SFML/Graphics.hpp>
#include <iostream>

#include "MenuState.hpp"
#include "GameState.hpp"


MenuState::MenuState(StateManager& stateManager, sf::RenderWindow& window)
	: State{ stateManager, window } {
	std::cout << this << " [MenuState] Initialized" << std::endl;
}

MenuState::~MenuState() {
	std::cout << "[MenuState] Destroyed" << std::endl;
}

void MenuState::pause() {

}

void MenuState::resume() {

}

void MenuState::processEvents() {
	sf::Event event;

	while (m_window.pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed:
				m_stateManager.quit();
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code) {
					case sf::Keyboard::Space:
						m_stateManager.stateToChangeTo(new GameState(m_stateManager, m_window));
						break;
					case sf::Keyboard::Escape:
						m_stateManager.quit();
						break;
				}
		}
	}
}

void MenuState::update(sf::Time dt) {

}

void MenuState::draw() {
	m_window.clear(sf::Color::Black);
	m_window.display();
}