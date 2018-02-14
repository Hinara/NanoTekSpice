/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4094
*/

#include <sstream>
#include "../Errors.hpp"
#include "Comp4094.hpp"

Comp4094::Comp4094(const std::string &name)
: SuperComponent(pins), _name(name)
{

}

Comp4094::~Comp4094()
{

}

const std::unordered_map<size_t,  SuperComponent::PinStatus>	Comp4094::pins = {};

nts::Tristate	Comp4094::internalCompute(std::size_t pin)
{
}