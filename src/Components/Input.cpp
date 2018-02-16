/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Input
*/

#include <iostream>
#include "../Errors.hpp"
#include "Input.hpp"

Input::Input(const std::string &)
: SuperComponent(pins), _state(nts::UNDEFINED)
{
}

Input::~Input()
{
}
const SuperComponent::PinMap Input::pins = {
	{1, PinStatus::OUTPUT}
};

nts::Tristate	Input::internalCompute(PinNumber pin)
{
	if (pin != 1 || _state == nts::UNDEFINED)
		throw Err::SectionError("");
	return this->_state;
}

void	Input::setState(nts::Tristate state)
{
	this->_state = state;
}