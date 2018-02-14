/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4514
*/

#include <sstream>
#include "../Errors.hpp"
#include "Comp4514.hpp"

Comp4514::Comp4514(const std::string &name)
: SuperComponent(getPin()), _name(name)
{

}

Comp4514::~Comp4514()
{

}

std::unordered_map<size_t,  SuperComponent::PinStatus>	Comp4514::getPin()
{
	const std::unordered_map<size_t,  PinStatus>	&pins = {
		 {1, PinStatus::INPUT},
		 {2, PinStatus::INPUT},
		 {3, PinStatus::OUTPUT},
		 {4, PinStatus::OUTPUT},
		 {5, PinStatus::INPUT},
		 {6, PinStatus::INPUT},
		 {8, PinStatus::INPUT},
		 {9, PinStatus::INPUT},
		 {10, PinStatus::OUTPUT},
		 {11, PinStatus::OUTPUT},
		 {12, PinStatus::INPUT},
		 {13, PinStatus::INPUT} };

	return pins;
}

nts::Tristate	Comp4514::internalCompute(std::size_t pin)
{
}