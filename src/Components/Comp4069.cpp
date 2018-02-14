/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4069
*/

#include <sstream>
#include "../Errors.hpp"
#include "Comp4069.hpp"

Comp4069::Comp4069(const std::string &name)
: SuperComponent(getPin()),_name(name)
{

}

Comp4069::~Comp4069()
{

}

std::unordered_map<size_t,  SuperComponent::PinStatus>	Comp4069::getPin()
{
	const std::unordered_map<size_t,  PinStatus>	&pins = {
		 {1, PinStatus::INPUT},
		 {2, PinStatus::OUTPUT},
		 {3, PinStatus::INPUT},
		 {4, PinStatus::OUTPUT},
		 {5, PinStatus::INPUT},
		 {6, PinStatus::OUTPUT},
		 {8, PinStatus::OUTPUT},
		 {9, PinStatus::INPUT},
		 {10, PinStatus::OUTPUT},
		 {11, PinStatus::INPUT},
		 {12, PinStatus::OUTPUT},
		 {13, PinStatus::INPUT} };

	return pins;
}

nts::Tristate	Comp4069::internalCompute(std::size_t pin)
{
	switch (pin)
	{
		case 2:
			return static_cast<nts::Tristate>(~(getInputPin(1)));
			break;
		case 4:
			return static_cast<nts::Tristate>(~(getInputPin(3)));
			break;
		case 6:
			return static_cast<nts::Tristate>(~(getInputPin(5)));
			break;
		case 8:
			return static_cast<nts::Tristate>(~(getInputPin(9)));
			break;
		case 10:
			return static_cast<nts::Tristate>(~(getInputPin(11)));
			break;
		case 12:
			return static_cast<nts::Tristate>(~(getInputPin(13)));
			break;
		default:
			throw ;
	}
}