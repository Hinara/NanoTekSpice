/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Input
*/

#include "../Errors.hpp"
#include "Input.hpp"

Input::Input(const std::string &)
: SuperComponent(_pins), _state(nts::UNDEFINED)
{
}

Input::~Input()
{
}
const SuperComponent::PinMap Input::_pins = {
	{1, PinStatus::OUTPUT}
};

nts::Tristate	Input::internalCompute(PinNumber)
{
	return this->_state;
}

void	Input::setState(nts::Tristate state)
{
	this->_state = state;
}