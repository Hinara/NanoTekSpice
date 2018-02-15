/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** False
*/

#include <iostream>
#include "../Errors.hpp"
#include "False.hpp"


False::False(const std::string &)
: SuperComponent(pins)
{
}

False::~False()
{
}
const SuperComponent::PinMap False::pins = {
	{1, PinStatus::OUTPUT}
};

nts::Tristate	False::internalCompute(PinNumber pin)
{
	if (pin != 1)
		throw Err::UnknowPin("\'False\''s pin can only be equal to 1.");
	return nts::FALSE;
}