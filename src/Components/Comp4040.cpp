/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4040
*/

#include <sstream>
#include "../Errors.hpp"
#include "Comp4040.hpp"

Comp4040::Comp4040(const std::string &name)
: SuperComponent(getPin()), _name(name)
{

}

Comp4040::~Comp4040()
{

}

std::unordered_map<size_t,  SuperComponent::PinStatus>	Comp4040::getPin()
{
	const std::unordered_map<size_t,  PinStatus>	&pins = {
		 {1, PinStatus::Output},
		 {2, PinStatus::Output},
		 {3, PinStatus::Output},
		 {4, PinStatus::Output},
		 {5, PinStatus::Output},
		 {6, PinStatus::Output},
		 {7, PinStatus::Output},
		 {9, PinStatus::Output},
		 {10, PinStatus::Input},
		 {11, PinStatus::Input},
		 {12, PinStatus::Output},
		 {13, PinStatus::Output},
		 {14, PinStatus::Output},
		 {15, PinStatus::Output} };

	return pins;
}

nts::Tristate	Comp4040::internalCompute(std::size_t pin)
{
}