/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4008
*/

#include <sstream>
#include "../Errors.hpp"
#include "Comp4008.hpp"

Comp4008::Comp4008(const std::string &name)
: SuperComponent(getPin()), _name(name)
{

}

Comp4008::~Comp4008()
{

}

std::unordered_map<size_t,  SuperComponent::PinStatus>	Comp4008::getPin()
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

nts::Tristate	Comp4008::internalCompute(std::size_t pin)
{
}