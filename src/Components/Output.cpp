/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Output
*/

#include <iostream>
#include "../Errors.hpp"
#include "Output.hpp"

Output::Output([[gnu::unused]] const std::string &value)
: SuperComponent(pins), _state(nts::UNDEFINED)
{
}

Output::~Output()
{
}
const std::unordered_map<size_t,  SuperComponent::PinStatus> Output::pins = {
		{1, PinStatus::INPUT} };

nts::Tristate	Output::internalCompute([[gnu::unused]] std::size_t pin)
{
	throw;
}

void	Output::simulate()
{
	this->_state = getInputPin(1);
}

nts::Tristate	Output::getValue()
{
	return this->_state;
}