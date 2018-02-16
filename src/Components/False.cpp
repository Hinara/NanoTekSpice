/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** False
*/

#include "../Errors.hpp"
#include "False.hpp"


False::False(const std::string &)
: SuperComponent(_pins)
{
}

False::~False()
{
}
const SuperComponent::PinMap False::_pins = {
	{1, PinStatus::OUTPUT}
};

nts::Tristate	False::internalCompute(PinNumber pin)
{
	return nts::FALSE;
}