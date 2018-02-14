/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Output
*/

#include <iostream>
#include "../Errors.hpp"
#include "Output.hpp"

Output::Output(const std::string &name)
: SuperComponent(pins), _name(name)
{
}

Output::~Output()
{
}
const std::unordered_map<size_t,  SuperComponent::PinStatus> Output::pins = {
		{1, PinStatus::INPUT} };

nts::Tristate	Output::internalCompute(std::size_t pin)
{
	return getInputPin(1);
}