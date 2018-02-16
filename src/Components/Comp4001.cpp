/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4001
*/

#include "../Errors.hpp"
#include "LogicGates.hpp"
#include "Comp4001.hpp"

Comp4001::Comp4001(const std::string &)
: SuperComponent(_pins)
{
}

Comp4001::~Comp4001()
{
}

const SuperComponent::PinMap	Comp4001::_pins = {
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
	{13, PinStatus::INPUT}
};

nts::Tristate	Comp4001::internalCompute(PinNumber pin)
{
	switch (pin)
	{
	case 3:
		return (LogicGate::norGate(getInputPin(1), getInputPin(2)));
	case 4:
		return (LogicGate::norGate(getInputPin(5), getInputPin(6)));
	case 10:
		return (LogicGate::norGate(getInputPin(8), getInputPin(9)));
	case 11:
		return (LogicGate::norGate(getInputPin(12), getInputPin(13)));
	default:
		throw Err::UnknowPin("Comp4001 can't compute this pin.");
	}
}