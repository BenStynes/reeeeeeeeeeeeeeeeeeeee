/// <summary>
/// @author Ben Stynes
/// @date Septemper 2019
/// </summary>
#include "Xbox360Controller.h"
///
///default constructor 
///
Xbox360Controller::Xbox360Controller()
{
	m_joystickIndex = 0;
}
///
///default deconstuctor unused
///
Xbox360Controller::~Xbox360Controller()
{
}
///the update that controls currebt state and prevuous state
void Xbox360Controller::update()
{
	m_previousState = m_currentState; // current state gets set to the precvious state
	
	///if the condiotion for any of these are true
	///it sets the current state of that to be true
	///or if a number value sets it to the number value at that momment 
	m_currentState.A = sf::Joystick::isButtonPressed(m_joystickIndex, 0);
	m_currentState.B = sf::Joystick::isButtonPressed(m_joystickIndex, 1);
	m_currentState.X = sf::Joystick::isButtonPressed(m_joystickIndex, 2);
	m_currentState.Y = sf::Joystick::isButtonPressed(m_joystickIndex, 3);
	m_currentState.LB = sf::Joystick::isButtonPressed(m_joystickIndex, 4);
	m_currentState.RB = sf::Joystick::isButtonPressed(m_joystickIndex, 5);
	m_currentState.Back = sf::Joystick::isButtonPressed(m_joystickIndex, 6);
	m_currentState.Start = sf::Joystick::isButtonPressed(m_joystickIndex, 7);
	m_currentState.LeftThumbStickClick = sf::Joystick::isButtonPressed(m_joystickIndex, 8);
	m_currentState.RightThumbStickClick = sf::Joystick::isButtonPressed(m_joystickIndex, 9);
	m_currentState.LeftThumbStick.x = sf::Joystick::getAxisPosition(m_joystickIndex, sf::Joystick::X);
	m_currentState.LeftThumbStick.y = sf::Joystick::getAxisPosition(m_joystickIndex, sf::Joystick::Y);
	m_currentState.RightThumbStick.x = sf::Joystick::getAxisPosition(m_joystickIndex, sf::Joystick::U);
	m_currentState.RightThumbStick.y = sf::Joystick::getAxisPosition(m_joystickIndex, sf::Joystick::V);
	m_currentState.RT = sf::Joystick::getAxisPosition(m_joystickIndex, sf::Joystick::Z);
	m_currentState.LT = sf::Joystick::getAxisPosition(m_joystickIndex, sf::Joystick::Z);
	m_currentState.DpadUp = (sf::Joystick::getAxisPosition(m_joystickIndex, sf::Joystick::PovY ) >DPAD_TRESHOLD);
	m_currentState.DpadDown = (sf::Joystick::getAxisPosition(m_joystickIndex, sf::Joystick::PovY) < -DPAD_TRESHOLD);
	m_currentState.DpadLeft =(sf::Joystick::getAxisPosition(m_joystickIndex, sf::Joystick::PovX) < -DPAD_TRESHOLD);
	m_currentState.DpadRight = (sf::Joystick::getAxisPosition(m_joystickIndex, sf::Joystick::PovX) > DPAD_TRESHOLD);
}

///
/// checks if its cinnected and returns that result when called
///
bool Xbox360Controller::isCoonected()
{
	return sf::Joystick::isConnected(m_joystickIndex);
}
///unknown what to do for here ,just left it to return the is coonected.
bool Xbox360Controller::connect()
{
	
	return isCoonected();
}
