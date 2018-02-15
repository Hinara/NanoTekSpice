/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4094
*/

#include <sstream>
#include "../Errors.hpp"
#include "Comp4094.hpp"

Comp4094::Comp4094(const std::string &)
: SuperComponent(pins)
{
}

Comp4094::~Comp4094()
{
}

const SuperComponent::PinMap	Comp4094::pins = {};

nts::Tristate	Comp4094::internalCompute(PinNumber pin)
{
}