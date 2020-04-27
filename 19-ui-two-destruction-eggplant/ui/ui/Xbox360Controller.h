/// <summary>
/// @author Ben Stynes
/// @date Septemper 2019
/// </summary>
#ifndef XBOX360CONTROLLER
#define XBOX360CONTROLLER

#include<SFML/Graphics.hpp>
#include<iostream>
struct GamePadState
{
	bool A = false; //controls A
	bool B = false; //controls B
	bool X = false; //controls X
	bool Y = false; //controls y
	bool RB = false;//controls RB
	bool LB = false;//controls LB
	float LT = false;//Float for LT
	float RT = false;//float for RT
	bool LeftThumbStickClick = false; // controls left click
	bool RightThumbStickClick = false;//controls riht click
	bool DpadUp = false;//dpad up control
	bool DpadDown = false;//dpad down control 
	bool DpadLeft = false;//dpad left control
	bool DpadRight = false; //dapd right control
	bool Back = false; // back control
	bool Start = false; //start control
	bool Xbox = false; //xbox controll not applicable to actual code
	sf::Vector2f LeftThumbStick; // vector for thumbstick left
	sf::Vector2f RightThumbStick; // vector fot thumbstick right

};


class Xbox360Controller
{
private: 
	const int DPAD_TRESHOLD= 50; // condt for for dpad treshold
public:


	static int s_noOfControllers; //controler numbers

	int m_joystickIndex; //number of joysticks(controls)

	GamePadState m_currentState;//the here and now state 

	GamePadState m_previousState;//the gone and passed state

	Xbox360Controller();//constructor
	~Xbox360Controller();//decounstructor
	void update();//uodate method
	bool isCoonected();//conected
	bool connect();//conect
};

#endif