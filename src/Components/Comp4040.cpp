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
		 {1, PinStatus::OUTPUT},
		 {2, PinStatus::OUTPUT},
		 {3, PinStatus::OUTPUT},
		 {4, PinStatus::OUTPUT},
		 {5, PinStatus::OUTPUT},
		 {6, PinStatus::OUTPUT},
		 {7, PinStatus::OUTPUT},
		 {9, PinStatus::OUTPUT},
		 {10, PinStatus::INPUT},
		 {11, PinStatus::INPUT},
		 {12, PinStatus::OUTPUT},
		 {13, PinStatus::OUTPUT},
		 {14, PinStatus::OUTPUT},
		 {15, PinStatus::OUTPUT} };

	return pins;
}

nts::Tristate	Comp4040::internalCompute(std::size_t pin)
{
}