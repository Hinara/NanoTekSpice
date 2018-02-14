/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4001
*/

#include "Comp4001.hpp"

Comp4001::Comp4001(const std::string &name)
: SuperComponent(getPin()), _name(name)
{
}

Comp4001::~Comp4001()
{

}

std::unordered_map<size_t,  SuperComponent::PinStatus>	Comp4001::getPin()
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

nts::Tristate	Comp4001::internalCompute(std::size_t pin)
{
	const auto &ptr = [] (nts::Tristate first, nts::Tristate second)-> nts::Tristate { return static_cast<nts::Tristate>(~first | ~second); };

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