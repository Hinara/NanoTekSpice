/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** true
*/

#include <iostream>
#include "../Errors.hpp"
#include "True.hpp"

True::True(const std::string &name)
: SuperComponent(pins), _name(name)
{
}

True::~True()
{
}

const std::unordered_map<size_t,  SuperComponent::PinStatus> True::pins = {
	{1, PinStatus::OUTPUT}
};

nts::Tristate	True::internalCompute(std::size_t pin)
{
	if (pin != 1)
		throw Err::UnknowPin("\'True\''s pin can only be equal to 1.");
	return nts::TRUE;
}