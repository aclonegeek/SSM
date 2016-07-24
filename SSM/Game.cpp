#include "Game.hpp"

const sf::Time Game::TimePerFrame = sf::seconds(1.0f / 60.0f);

void Game::run() {
	m_window.create(sf::VideoMode{ 1280, 720 }, "Dodaren", sf::Style::Titlebar | sf::Style::Close);

	std::unique_ptr<State> menuState(new MenuState(m_stateManager, m_window));
	m_stateManager.pushState(std::move(menuState));

	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (m_stateManager.running()) {
		if (!m_stateManager.isChangingState()) {
			sf::Time elapsedTime = clock.restart();
			timeSinceLastUpdate += elapsedTime;

			while (timeSinceLastUpdate > TimePerFrame) {
				timeSinceLastUpdate -= TimePerFrame;

				m_stateManager.processEvents();
				m_stateManager.update(TimePerFrame);
			}
			m_stateManager.draw();
		} else {
			m_stateManager.changeState(m_stateManager.getNewState());
		}
	}
}