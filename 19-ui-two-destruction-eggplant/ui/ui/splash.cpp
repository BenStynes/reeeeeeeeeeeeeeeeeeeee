#include "Splash.h"



Splash::Splash(Game& game) :
	m_game(&game)
{
	init();
}
Splash::~Splash()
{

}

void Splash::render(sf::RenderWindow& window)
{
	window.clear();
	window.draw(m_splashText);
	window.draw(sheildSprite);
	window.display();
}

void Splash::init()
{
	if (!m_shieldTexture.loadFromFile("ASSETS\\IMAGES\\shield.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading logo" << std::endl;
	}
	
	sheildSprite.setTexture(m_shieldTexture);
	sheildSprite.scale(3, 3);
	sheildSprite.setPosition(-1000, -1000);
	sheildSprite.setOrigin(sheildSprite.getGlobalBounds().width / 2, sheildSprite.getGlobalBounds().height / 2);
	

	m_splashFont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf");
	m_splashText.setFont(m_splashFont);
	m_splashText.setCharacterSize(40);
	m_splashText.setPosition(m_splashPosition);
	m_splashText.setFillColor(sf::Color::Red);
}

void Splash::movement()
{
	if(m_letter < m_splashString.length()&& onscreen == true)
	{
		
		if(m_textOn.getElapsedTime() >= sf::seconds(0.10f))
		{
			char m_currentLetter = m_splashString[m_letter];
			m_splashText.setString(m_splashText.getString() + m_currentLetter);
			m_letter++;
			sheildSprite.setPosition(m_sheildPosition.x, m_sheildPosition.y);
			m_sheildPosition.x = m_sheildPosition.x + m_sheildMovement;
			
			m_textOn.restart();
			
		}
	}
	else if (m_letter == m_splashString.length()  || onscreen == false)
	{
		
		
			if (onscreen == true)
			{
				sheildSprite.setPosition(m_sheildPosition.x += 10, m_sheildPosition.y);
			}
			else
			{
				
			
				sheildSprite.setPosition(m_sheildPosition.x -= 10, m_sheildPosition.y);
				if (m_splashText.getGlobalBounds().width + 200 < sheildSprite.getPosition().x )
				{
					if (m_splashText.getPosition().y > 200 & m_splashText.getPosition().y < 150)
					{
						m_splashText.setPosition(m_splashPosition.x, m_splashPosition.y -= 10);
					}
					
					else
					{
						m_splashText.setPosition(m_splashPosition.x, m_splashPosition.y += 10);
					}
					
				}
			}
			if (sheildSprite.getPosition().x > 800)
			{
				onscreen = false;
			}

			if (sheildSprite.getPosition().x < 0 && m_splashText.getPosition().y > 600 )
			{
				m_game->setGameState(s_GameStates::s_titleScreen);
			}
		
	}
}

void Splash::update()
{
	movement();
}
