#include "License.h"
#include <iostream>


///splash initiailaixzer//
///has a lot of text initialization

License::License(Game& game, sf::Font font) :
	m_game(&game),
	m_comicSans(font),
	m_textMessage("Created by BJ inc\n the bull shit devs\n aka Destruction Eggplant", m_comicSans, 20),
	m_textMessage2("Created by BJ inc\n the bull shit devs\n aka Destruction Eggplant", m_comicSans, 20),
	m_textMessage3("Created by BJ inc\n the bull shit devs\n aka Destruction Eggplant", m_comicSans, 20),
	m_textMessage4("Created by BJ inc\n the bull shit devs\n aka Destruction Eggplant", m_comicSans, 20)


{
	m_textMessage.setPosition(350.0f, 350.0f);
	m_textMessage.setOrigin(m_textMessage.getGlobalBounds().width / 2, m_textMessage.getGlobalBounds().height / 2);
	m_textMessage.setLetterSpacing(5);
	m_textMessage.setOutlineColor(sf::Color::White);
	m_textMessage.setOutlineThickness(0.5);


	m_textMessage2.setFillColor(sf::Color{ 50,255,50,200 });
	m_textMessage2.setPosition(350.0f, 350.0f);
	m_textMessage2.setOrigin(m_textMessage2.getGlobalBounds().width / 2, m_textMessage2.getGlobalBounds().height / 2);
	m_textMessage2.setLetterSpacing(5);
	m_textMessage2.setOutlineColor(sf::Color::Green);
	m_textMessage2.setOutlineThickness(0.5);


	m_textMessage3.setFillColor(sf::Color{ 255,50,50,200 });
	m_textMessage3.setPosition(350.0f, 350.0f);
	m_textMessage3.setOrigin(m_textMessage3.getGlobalBounds().width / 2, m_textMessage3.getGlobalBounds().height / 2);
	m_textMessage3.setLetterSpacing(5);
	m_textMessage3.setOutlineColor(sf::Color::Blue);
	m_textMessage3.setOutlineThickness(0.5);

	m_textMessage4.setFillColor(sf::Color{ 50,50,255,200 });
	m_textMessage4.setPosition(350.0f, 350.0f);
	m_textMessage4.setOrigin(m_textMessage4.getGlobalBounds().width / 2, m_textMessage4.getGlobalBounds().height / 2);
	m_textMessage4.setLetterSpacing(5);
	m_textMessage4.setOutlineColor(sf::Color::Red);
	m_textMessage4.setOutlineThickness(0.5);
}


License::~License()
{
	std::cout << "destructing Splash" << std::endl;
}
///splash update
void License::update(sf::Time deltaTime)
{
	m_cumulativeTime += deltaTime;

	if (m_cumulativeTime.asSeconds() < 5)
	{

		m_textMessage.move(0, i);

	}

	if (m_cumulativeTime.asSeconds() > 3)
	{
		rotating = false;
	}
	if (m_cumulativeTime.asSeconds() > 5)
	{
		m_game->setGameState(s_GameStates::s_titleScreen);
	}
}
///splash render
void License::render(sf::RenderWindow& window)
{
	window.clear(sf::Color::Black);
	m_textMessage.setFillColor(sf::Color{ 200,200,0 });
	if (rotating)
	{
		m_textMessage2.setPosition(m_textMessage.getPosition().x + rand() % 5, m_textMessage.getPosition().y - rand() % 5);
		m_textMessage3.setPosition(m_textMessage.getPosition().x - rand() % 5, m_textMessage.getPosition().y + rand() % 5);
		m_textMessage4.setPosition(m_textMessage.getPosition().x - rand() % 5, m_textMessage.getPosition().y - rand() % 5);
		i -= 0.0001;
	}

	else
	{
		m_textMessage2.setPosition(m_textMessage.getPosition().x - rand() % 5, m_textMessage.getPosition().y - rand() % 5);
		m_textMessage3.setPosition(m_textMessage.getPosition().x + rand() % 5, m_textMessage.getPosition().y + rand() % 5);
		m_textMessage4.setPosition(m_textMessage.getPosition().x - rand() % 5, m_textMessage.getPosition().y + rand() % 5);
		i += 0.001;

	}
	if (m_cumulativeTime.asSeconds() > 2 && m_cumulativeTime.asSeconds() < 4)
	{

		m_textMessage2.setPosition(m_textMessage.getPosition().x + rand() % 5, m_textMessage.getPosition().y + rand() % 5);
		m_textMessage3.setPosition(m_textMessage.getPosition().x - rand() % 5, m_textMessage.getPosition().y - rand() % 5);
		m_textMessage4.setPosition(m_textMessage.getPosition().x + rand() % 5, m_textMessage.getPosition().y + rand() % 5);

	}


	window.draw(m_textMessage2);
	window.draw(m_textMessage3);
	window.draw(m_textMessage4);
	window.draw(m_textMessage);
	window.display();
}

