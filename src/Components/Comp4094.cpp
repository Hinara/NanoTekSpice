/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4094
*/

#include "../Errors.hpp"
#include "Comp4094.hpp"

Comp4094::Comp4094(const std::string &)
: SuperComponent(_pins)
{
}

Comp4094::~Comp4094()
{
}

const SuperComponent::PinMap	Comp4094::_pins = {};

nts::Tristate	Comp4094::internalCompute(PinNumber pin)
{
}