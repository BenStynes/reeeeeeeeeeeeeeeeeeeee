#ifndef GUI_H
#define GUI_H
#include <SFML/Graphics.hpp>
#include <functional>
class GUI
{
protected:
	sf::Sprite m_body;
	sf::Texture m_hovered;
	sf::Texture m_normal;

	std::string m_text;
	sf::Font m_font;

	GUI* m_down;
	GUI* m_up;
	GUI* m_left;
	GUI* m_right;

public:
	sf::Text m_buttonsText;
	bool m_highlighted;
	std::function<void()> m_onClick{ nullptr };
	virtual void onClick() = 0;
	virtual void initialise(GUI* t_up,
		GUI* t_down,
		GUI* t_left,
		GUI* t_right) = 0;
	virtual void setOnClick(void (*t_onClick)()) = 0;
	virtual void up(GUI** t_selectedButton) = 0;
	virtual void left(GUI** t_selectedButton) = 0;
	virtual void right(GUI** t_selectedButton) = 0;
	virtual void down(GUI** t_selectedButton) = 0;
	virtual void highlighted() = 0;
	void setLeft(GUI* t_button) { m_left = t_button; };
	void setRight(GUI* t_button) { m_right = t_button; };
	void setUp(GUI* t_button) { m_up = t_button; };
	void setDown(GUI* t_button) { m_down = t_button; };

}; 
#endif
