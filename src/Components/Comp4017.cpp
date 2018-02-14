/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4017
*/

#include <sstream>
#include "../Errors.hpp"
#include "Comp4017.hpp"

Comp4017::Comp4017(const std::string &name)
: SuperComponent(getPin()), _name(name)
{

}

Comp4017::~Comp4017()
{

}

std::unordered_map<size_t,  SuperComponent::PinStatus>	Comp4017::getPin()
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
		 {10, PinStatus::Output},
		 {11, PinStatus::Output},
		 {12, PinStatus::Output},
		 {13, PinStatus::Input},
		 {14, PinStatus::Input},
		 {15, PinStatus::Input} };

	return pins;
}

nts::Tristate	Comp4017::internalCompute(std::size_t pin)
{
}