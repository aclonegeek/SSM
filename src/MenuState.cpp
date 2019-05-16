#include <SFML/Window/Event.hpp>
#include <iostream>

#include "MenuState.hpp"
#include "GameState.hpp"

MenuState::MenuState(StateManager& stateManager, sf::RenderWindow& window)
: State{ stateManager, window } {
    std::cout << "[MenuState] Initialized\n";
}

MenuState::~MenuState() {
    std::cout << "[MenuState] Destroyed\n";
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
                    case sf::Keyboard::Space: {
                        std::unique_ptr<State> gameState(new GameState(m_stateManager, m_window));
                        m_stateManager.changeState(std::move(gameState));
                        return;
                    }
                    case sf::Keyboard::Escape:
                        m_stateManager.quit();
                        return;
                }
        }
    }
}

void MenuState::update(const sf::Time& dt) {

}

void MenuState::draw() {
    m_window.clear(sf::Color::Black);
    m_window.display();
}