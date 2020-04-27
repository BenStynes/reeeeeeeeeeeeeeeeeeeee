#ifndef LICENSE
#define LICENSE
#include <SFML\Graphics.hpp>

class Game;

class License
{
public:


	License(Game& game, sf::Font font);

	~License();

	void update(sf::Time deltaTime);
	void render(sf::RenderWindow& window);

private:
	Game* m_game;
	sf::Time m_cumulativeTime;
	sf::Font m_comicSans;
	sf::Text m_textMessage;
	sf::Text m_textMessage2;
	sf::Text m_textMessage3;
	sf::Text m_textMessage4;
	bool rotating = true;
	double i = 0;
};
#include "Game.h"
#endif // !SPLASH