/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Output
*/

#include "../Errors.hpp"
#include "Output.hpp"

Output::Output(const std::string &)
: SuperComponent(_pins), _state(nts::UNDEFINED)
{
}

const SuperComponent::PinMap	Output::_pins = {
	{1, PinStatus::INPUT}
};

nts::Tristate	Output::internalCompute(PinNumber)
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