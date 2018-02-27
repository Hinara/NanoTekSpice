/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4011
*/

#include "../Errors.hpp"
#include "LogicGates.hpp"
#include "Comp4011.hpp"

Comp4011::Comp4011(const std::string &)
: SuperComponent(_pins)
{
}

Comp4011::~Comp4011()
{
}

const SuperComponent::PinMap	Comp4011::_pins = {
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

nts::Tristate	Comp4011::internalCompute(PinNumber pin)
{
	switch (pin)
	{
	case 3:
		return (LogicGates::nandGate(getInputPin(1), getInputPin(2)));
	case 4:
		return (LogicGates::nandGate(getInputPin(5), getInputPin(6)));
	case 10:
		return (LogicGates::nandGate(getInputPin(8), getInputPin(9)));
	case 11:
		return (LogicGates::nandGate(getInputPin(12), getInputPin(13)));
	default:
		throw Err::UnknowPin("Comp4011 can't compute this pin.");
	}
}