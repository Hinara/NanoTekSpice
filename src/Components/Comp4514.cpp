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
		 {1, PinStatus::Input},
		 {2, PinStatus::Input},
		 {3, PinStatus::Output},
		 {4, PinStatus::Output},
		 {5, PinStatus::Input},
		 {6, PinStatus::Input},
		 {8, PinStatus::Input},
		 {9, PinStatus::Input},
		 {10, PinStatus::Output},
		 {11, PinStatus::Output},
		 {12, PinStatus::Input},
		 {13, PinStatus::Input} };

	return pins;
}

nts::Tristate	Comp4514::internalCompute(std::size_t pin)
{
}