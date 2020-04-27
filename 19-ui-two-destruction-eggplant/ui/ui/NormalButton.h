
#pragma once
#include "GUI.h"
#include "SFML/Graphics.hpp"
class NormalButton : public GUI
{
private:

public:
	NormalButton() = delete;
	NormalButton(sf::Vector2f t_pos, std::string t_text);

	virtual void onClick() override;
	virtual void initialise(GUI* t_up,
		GUI* t_down,
		GUI* t_left,
		GUI* t_right) override;
	virtual void setOnClick(void(*t_onClick)()) override;
	virtual void left(GUI** t_selectedButton) override;
	virtual void right(GUI** t_selectedButton) override;
	virtual void up(GUI** t_selectedButton) override;
	virtual void down(GUI** t_selectedButton) override;
	virtual void highlighted() override;
	virtual void render(sf::RenderWindow& t_window);

};