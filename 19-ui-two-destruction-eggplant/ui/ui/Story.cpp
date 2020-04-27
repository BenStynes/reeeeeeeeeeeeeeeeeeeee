#include "Story.h"

#include "Story.h"

Story::Story(Game& game, sf::Font font) :
	m_game(&game),
	m_comicSans(font),
	endlineCount{ 0 }
{

	/*m_backgroundTexture1.loadFromFile("image1.jpg");
	m_backgroundTexture2.loadFromFile("image2.jpg");
	m_backgroundTexture3.loadFromFile("image3.jpg");*/
	m_textureBox.loadFromFile("TextBox.png");
	m_background.setTexture(m_backgroundTexture1);

	m_cumulativeTime.Zero;
	m_textbox.setTexture(m_textureBox);
	m_spriteTexture.loadFromFile("Sprite.png");
	m_Sprite.setTexture(m_spriteTexture);
	m_Sprite.setPosition(20, 120);
	m_Sprite.setScale(1, 1);

	m_textbox.setPosition(0, 240);

	m_textMessage.setFont(m_comicSans);
	m_textMessage.setPosition(20, 310);
	m_textMessage.setCharacterSize(16);
	m_textMessage.setFillColor(sf::Color::White);
	m_textMessage.setOutlineColor(sf::Color::Black);
	m_textMessage.setOutlineThickness(2);

	m_textMessage2.setFont(m_comicSans);
	m_textMessage2.setPosition(30, 320);
	m_textMessage2.setCharacterSize(16);
	m_textMessage2.setFillColor(sf::Color::Red);
	m_textMessage2.setOutlineColor(sf::Color::Black);
	m_textMessage2.setOutlineThickness(2);


	m_name.setCharacterSize(12);
	m_name.setFillColor(sf::Color::White);
	m_name.setOutlineColor(sf::Color::Black);
	m_name.setOutlineThickness(2);
	m_name.setFont(m_comicSans);
	m_nameTimer.restart();
	m_clock.restart();
}

Story::~Story()
{


}

void Story::update(sf::Time deltaTime, Xbox360Controller &t_controlor)
{
	
	advanceText();
	///switches on a space press
	if (t_controlor.m_currentState.Start)
	{
		advanceToGameplay();
	}
	if (t_controlor.m_currentState.A && textFinished == true)
	{
		//m_nameString = "Vanilla";
		m_textMessage.setString("");
		m_textMessage2.setString("");
		m_textMessage3.setString("");

		switch (spacePressedCount)
		{

		case 0:

			m_story1 = "You must gather the resources and stop the clock to prevent the war?\n Wait you have the resources and the clock, what are you waiting for!\n Praise the Overlord! Praise pete!\n Praise the Overlord! Praise pete!\n Praise the Overlord! Praise pete!\n Ah, Sorry went on a tangent can't help it petes too cool. My names Vanilla! ";
			m_clock.restart();

			break;
		case 1:

			m_story1 = "Pete is so cool...\n We all aspire to be like him.\n So why did he create this watchn that can kill us all if stopped at the wrong time.";
			m_clock.restart();
			break;


		case 2:

			m_story1 = "What are you doing!\n You should be Stoping the watch as sooon as you can dew it now!";
			m_clock.restart();
			break;
		case 3:
			draw = !draw;
			

			break;
		case 4:
			advanceToGameplay();
			break;
		}
		textFinished = false;


		spacePressedCount++;
	}
}
///story ren
void Story::render(sf::RenderWindow& window)
{
	window.clear();
	if (draw)
	{
		window.draw(m_background);
		window.draw(m_Sprite);
		window.draw(m_textbox);
		window.draw(m_textMessage);

		if (redDraw)
		{
			window.draw(m_textMessage2);
		}
	}
	window.display();
}

void Story::advanceText()
{
	if (textFinished == false)
	{
		if (m_clock.getElapsedTime().asSeconds() > time)
		{///in sumaarry is used to add char by char and rotate the text object 
			m_textMessage2.rotate(10);

			m_textMessage.setString(m_textMessage.getString() + m_textMessage2.getString());

			if (m_textMessage.getString().getSize() + 1 < m_story1.size())
			{




				char currentChar = m_story1.at(m_textMessage.getString().getSize());

				m_textMessage2.setPosition(m_textMessage.findCharacterPos(m_textMessage.getString().getSize()) + sf::Vector2f{ 10.0f, 10.0f });
				m_textMessage2.setString(currentChar);
				m_textMessage2.setOrigin(m_textMessage2.getGlobalBounds().width / 2, m_textMessage2.getGlobalBounds().height / 2);



			}
			else
			{
				textFinished = true;
			}


			m_clock.restart();

		}
	}

}

void Story::advanceToGameplay()
{
m_game->setGameState(s_GameStates::s_gameplay);

}


