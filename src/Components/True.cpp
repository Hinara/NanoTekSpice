/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** true
*/

#include "../Errors.hpp"
#include "True.hpp"

True::True(const std::string &)
: SuperComponent(_pins)
{
}

const SuperComponent::PinMap True::_pins = {
	{1, PinStatus::OUTPUT}
};

nts::Tristate	True::internalCompute(PinNumber pin)
{
	if (pin != 1)
		throw Err::UnknowPin("\'True\''s pin can only be equal to 1.");
	return nts::TRUE;
}