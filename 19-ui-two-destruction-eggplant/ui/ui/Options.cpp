#include "Options.h"
Options::Options(Game& game) :
	m_game(&game)
{
	optionCounterUp = 0;
	optionCounterDown = 0;

	setupText();
}

Options::~Options()
{
}

void Options::setupText()
{

	overallText.loadFromFile("ASSETS/FONTS/ariblk.ttf");
	titleText.setString("Options");
	titleText.setFont(overallText);
	titleText.setFillColor(sf::Color::Red);
	titleText.setCharacterSize(40);
	titleText.setOrigin(titleText.getGlobalBounds().width / 2, titleText.getGlobalBounds().height / 2);
	titleText.setPosition(400.0f, 50.0f);

	if (!m_texturePointer.loadFromFile("ASSETS\\IMAGES\\pointer.png"))
	{
		std::cout << "problem loading pointer" << std::endl;
	}
	m_pointerSprite.setTexture(m_texturePointer);
	m_pointerSprite.setOrigin(m_pointerSprite.getGlobalBounds().width / 2, m_pointerSprite.getGlobalBounds().height / 2);
	m_pointerSprite.setPosition({ 220.0f, 285.0f });
	m_pointerSprite.scale(3, 3);


	if (!m_backgroundTexture.loadFromFile("ASSETS\\IMAGES\\mainmenubackground.png"))

	{
		std::cout << "problem loading pointer" << std::endl;
	}
	m_backgroundSprite.setTexture(m_backgroundTexture);
	m_backgroundSprite.setOrigin(m_backgroundSprite.getGlobalBounds().width / 2, m_backgroundSprite.getGlobalBounds().height / 2);
	m_backgroundSprite.setPosition({ 400.0f, 300.0f });


	for (int i = 0; i < 3; i++)
	{
		menuText[i].setFont(overallText);
		menuText[i].setCharacterSize(30);


		if (!m_radio.loadFromFile("ASSETS\\IMAGES\\unslectedRadioButton.png"))

		{
			// simple error message if previous call fails
			std::cout << "problem loading main menu" << std::endl;
		}
 if (!m_radio2.loadFromFile("ASSETS\\IMAGES\\unslectedRadioButton.png"))
		{
			// simple error message if previous call fails
			std::cout << "problem loading main menu" << std::endl;
		}
		if (!m_radio3.loadFromFile("ASSETS\\IMAGES\\unslectedRadioButton.png"))
		{
			// simple error message if previous call fails
			std::cout << "problem loading main menu" << std::endl;
		}
		if (!m_check.loadFromFile("ASSETS\\IMAGES\\checkbox.png"))
		{
			// simple error message if previous call fails
			std::cout << "problem loading main menu" << std::endl;
		}
		if (!m_tick.loadFromFile("ASSETS\\IMAGES\\tick.png"))
		{
			// simple error message if previous call fails
			std::cout << "problem loading main menu" << std::endl;
		}
		if (!m_slide.loadFromFile("ASSETS\\IMAGES\\slider.png"))
		{
			// simple error message if previous call fails
			std::cout << "problem loading main menu" << std::endl;
		}
		if (!m_slideButt.loadFromFile("ASSETS\\IMAGES\\unslectedRadioButton.png"))
		{
			// simple error message if previous call fails
			std::cout << "problem loading main menu" << std::endl;
		}
		
		m_OptionsSprite[i].setOrigin(m_OptionsSprite[i].getGlobalBounds().width / 2, m_OptionsSprite[i].getGlobalBounds().height / 2);
		m_OptionsSprite[i].scale(2,2);
	
		sizeIncrease[i] = 4.0f;






		menuText[i].setFillColor(sf::Color::White);
		switch (i)
		{
		case 0:

			m_OptionsSprite[i].setPosition(310, 300 );
			m_OptionsSprite[i].setTexture(m_radio);
			menuText[i].setPosition({ 200.0f,300.0f });

			menuText[i].setString("Dificulty");

			break;
		case 1:

			m_OptionsSprite[i].setPosition(310, 400 );
			m_OptionsSprite[i].setTexture(m_check);
			menuText[i].setPosition({ 200.0f,400.0f });

			menuText[i].setString("Sounds");

			break;
		case 2:

			m_OptionsSprite[i].setPosition(310, 500);
			m_OptionsSprite[i].setTexture(m_slide);
			menuText[i].setPosition({ 200.0f,500.0f });

			menuText[i].setString("Volume");

			break;
		}

		menuText[i].setOrigin(menuText[i].getGlobalBounds().width / 2, menuText[i].getGlobalBounds().height / 2);
	}



}

void Options::update(Xbox360Controller& t_control, sf::RenderWindow& t_window)
{

	movePointer(t_control);
	buttonsHovered(t_control, t_window);
}


bool Options::getExisting()
{
	return existing;
}

void Options::setExisting(bool t_showing)
{
	existing = t_showing;
}

void Options::advanceToNewGame()
{
	if (m_pointerSprite.getPosition().y == 300.0f)
	{
		newGame = true;
		existing = false;

	}
}

void Options::advanceToOptions()
{

	if (m_pointerSprite.getPosition().y == 450.0f)
	{
		optionsMenu = true;
		existing = false;
	}
}

void  Options::exitGame()
{
	if (m_pointerSprite.getPosition().y == 600.0f)
	{
		closeGame = true;
		existing = false;
	}
}

void Options::buttonsHovered(Xbox360Controller& t_control, sf::RenderWindow& t_window)
{
	for (int i = 0; i < 3; i++)
	{
		if (optionCounterDown == i)
		{
			if (t_control.m_currentState.A && i == 0)
			{

				m_OptionsSprite[i].setScale(2, 2);
				
			}
			else if (t_control.m_currentState.A && i == 1)
			{
				m_OptionsSprite[i].setScale(2, 2);
				m_OptionsSprite[i].setTexture(m_tick);
			}
			else if (t_control.m_currentState.A && i == 2)
			{
				m_OptionsSprite[i].setScale(2, 2);
			
			}

			if (sizeIncrease[i] < 2.0f)
			{
				sizeIncrease[i] = sizeIncrease[i] + 0.10f;
				m_OptionsSprite[i].setScale(sizeIncrease[i], sizeIncrease[i]);
			}
		}
		else
		{

			sizeIncrease[i] = 2;
			m_OptionsSprite[i].setScale(sizeIncrease[i], sizeIncrease[i]);
		}
		if (t_control.m_currentState.B)
		{
			m_game->setGameState(s_GameStates::s_titleScreen);
		}


	}
}
void Options::movePointer(Xbox360Controller& t_control)
{

	if (t_control.m_currentState.DpadDown)
	{
		if (!t_control.m_previousState.DpadDown)
		{
			optionCounterDown++;
		}
	}

	if (t_control.m_currentState.DpadUp)
	{
		if (!t_control.m_previousState.DpadUp)
		{
			optionCounterDown--;
		}
	}
	if (optionCounterDown < 0)
	{
		optionCounterDown = 2;
	}
	else if (optionCounterDown > 2)
	{
		optionCounterDown = 0;
	}
	switch (optionCounterDown)
	{
	case 0:
		m_pointerSprite.setPosition(m_pointerSprite.getPosition().x, menuText[optionCounterDown].getPosition().y);
		break;
	case 1:
		m_pointerSprite.setPosition(m_pointerSprite.getPosition().x, menuText[optionCounterDown].getPosition().y);
		break;
	case 2:
		m_pointerSprite.setPosition(m_pointerSprite.getPosition().x, menuText[optionCounterDown].getPosition().y);
		break;
	}

}
void Options::Draw(sf::RenderWindow& t_window)
{
	t_window.clear();
	t_window.draw(m_backgroundSprite);
	t_window.draw(titleText);
	t_window.draw(m_pointerSprite);
	for (int i = 0; i < 3; i++)
	{
		t_window.draw(m_OptionsSprite[i]);
		t_window.draw(menuText[i]);
		t_window.draw(options[i]);
	}

	t_window.display();
}

bool Options::getNewGame()
{
	return newGame;
}

bool Options::getOptionsMenu()
{
	return optionsMenu;
}

bool Options::getExitGame()
{
	return closeGame;
}
void Options::returnToOptions()
{
	if (newGame == false)
	{
		existing = true;
	}
}

