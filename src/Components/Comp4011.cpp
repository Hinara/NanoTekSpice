/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4011
*/

#include <sstream>
#include "../Errors.hpp"
#include "Comp4011.hpp"

Comp4011::Comp4011(const std::string &name)
: SuperComponent(getPin()), _name(name)
{

}

Comp4011::~Comp4011()
{

}

std::unordered_map<size_t,  SuperComponent::PinStatus>	Comp4011::getPin()
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

nts::Tristate	Comp4011::internalCompute(std::size_t pin)
{
	const auto &ptr = [] (nts::Tristate first, nts::Tristate second)-> nts::Tristate { return static_cast<nts::Tristate>(~first & ~second); };

	switch (pin)
	{
		case 3:
			return ptr(getInputPin(1), getInputPin(2));
			break;
		case 4:
			return ptr(getInputPin(5), getInputPin(6));
			break;
		case 10:
			return ptr(getInputPin(8), getInputPin(9));
			break;
		case 11:
			return ptr(getInputPin(12), getInputPin(13));
			break;
		default:
			throw ;
	}
}