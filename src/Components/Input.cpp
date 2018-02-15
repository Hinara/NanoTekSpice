/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Input
*/

#include <iostream>
#include "../Errors.hpp"
#include "Input.hpp"

Input::Input(const std::string &name)
: SuperComponent(pins) , _name(name), _state(nts::UNDEFINED)
{
}

Input::~Input()
{
}
const std::unordered_map<size_t,  SuperComponent::PinStatus> Input::pins = {
		 {1, PinStatus::OUTPUT} };

nts::Tristate	Input::internalCompute(std::size_t pin)
{
	if (pin != 1)
		throw;
	return this->_state;
}

void	Input::setState(nts::Tristate state)
{
	this->_state = state;
}