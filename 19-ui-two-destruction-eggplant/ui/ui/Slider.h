#ifndef SLIDER_H
#define SLIDER_H

#include "GUI.h"
#include <iostream>

class Slider : public GUI
{
public:
	Slider();
	Slider(sf::Vector2f t_position, std::string t_text);

private:
	float* m_valueToChange;
	float m_minValue;
	float m_maxValue;
	float m_currentValue;
	sf::Sprite m_sliderBar;
	sf::Sprite m_movingBar;
public:
	virtual void initialise(GUI* t_up,
		GUI* t_down,
		GUI* t_left,
		GUI* t_right) override;
	virtual void setOnClick(void(*t_onClick)()) override;
	virtual void onClick() override;
	virtual void left(GUI** t_selectedButton) override;
	virtual void right(GUI** t_selectedButton) override;
	virtual void up(GUI** t_selectedButton) override;
	virtual void down(GUI** t_selectedButton) override;
	virtual void highlighted() override;
	void drawButton(sf::RenderWindow& t_window);

	float getCurrentValue() { return m_currentValue; }
};


#endif