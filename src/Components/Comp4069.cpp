/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4069
*/

#include "../Errors.hpp"
#include "LogicGates.hpp"
#include "Comp4069.hpp"

Comp4069::Comp4069(const std::string &)
: SuperComponent(_pins)
{
}

const SuperComponent::PinMap	Comp4069::_pins = {
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
	{13, PinStatus::INPUT}
};

nts::Tristate	Comp4069::internalCompute(PinNumber pin)
{
	switch (pin)
	{
	case 2:
		return (LogicGates::notGate(getInputPin(1)));
	case 4:
		return (LogicGates::notGate(getInputPin(3)));
	case 6:
		return (LogicGates::notGate(getInputPin(5)));
	case 8:
		return (LogicGates::notGate(getInputPin(9)));
	case 10:
		return (LogicGates::notGate(getInputPin(11)));
	case 12:
		return (LogicGates::notGate(getInputPin(13)));
	default:
		throw Err::UnknowPin("Comp4069 can't compute this pin.");
	}
}