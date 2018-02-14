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
		 {1, PinStatus::Input},
		 {2, PinStatus::Output},
		 {3, PinStatus::Input},
		 {4, PinStatus::Output},
		 {5, PinStatus::Input},
		 {6, PinStatus::Output},
		 {8, PinStatus::Output},
		 {9, PinStatus::Input},
		 {10, PinStatus::Output},
		 {11, PinStatus::Input},
		 {12, PinStatus::Output},
		 {13, PinStatus::Input} };

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