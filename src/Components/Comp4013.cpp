/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4013
*/

#include <sstream>
#include "../Errors.hpp"
#include "Comp4013.hpp"

Comp4013::Comp4013(const std::string &name)
: SuperComponent(getPin()), _name(name)
{

}

Comp4013::~Comp4013()
{

}

std::unordered_map<size_t,  SuperComponent::PinStatus>	Comp4013::getPin()
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

nts::Tristate	Comp4013::internalCompute(std::size_t pin)
{
}