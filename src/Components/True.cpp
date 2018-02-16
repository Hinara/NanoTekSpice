/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** true
*/

#include "../Errors.hpp"
#include "True.hpp"

True::True(const std::string &)
: SuperComponent(pins)
{
}

True::~True()
{
}

const SuperComponent::PinMap True::pins = {
	{1, PinStatus::OUTPUT}
};

nts::Tristate	True::internalCompute(PinNumber pin)
{
	if (pin != 1)
		throw Err::UnknowPin("\'True\''s pin can only be equal to 1.");
	return nts::TRUE;
}