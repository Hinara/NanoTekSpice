/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** False
*/

#include <iostream>
#include "../Errors.hpp"
#include "False.hpp"


False::False(const std::string &name)
: SuperComponent(pins), _name(name)
{
}

False::~False()
{
}
const std::unordered_map<size_t,  SuperComponent::PinStatus> False::pins = {
	{1, PinStatus::OUTPUT} };

nts::Tristate	False::internalCompute(std::size_t pin)
{
	if (pin != 1)
		throw Err::UnknowPin("\'False\''s pin can only be equal to 1.");
	return nts::FALSE;
}