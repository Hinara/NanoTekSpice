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
		 {1, PinStatus::OUTPUT},
		 {2, PinStatus::OUTPUT},
		 {3, PinStatus::OUTPUT},
		 {4, PinStatus::OUTPUT},
		 {5, PinStatus::OUTPUT},
		 {6, PinStatus::OUTPUT},
		 {7, PinStatus::OUTPUT},
		 {9, PinStatus::OUTPUT},
		 {10, PinStatus::OUTPUT},
		 {11, PinStatus::OUTPUT},
		 {12, PinStatus::OUTPUT},
		 {13, PinStatus::INPUT},
		 {14, PinStatus::INPUT},
		 {15, PinStatus::INPUT} };

	return pins;
}

nts::Tristate	Comp4017::internalCompute(std::size_t pin)
{
}