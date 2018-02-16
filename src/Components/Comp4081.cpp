/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4081
*/

#include "../Errors.hpp"
#include "LogicGates.hpp"
#include "Comp4081.hpp"

Comp4081::Comp4081(const std::string &)
: SuperComponent(_pins)
{
}

Comp4081::~Comp4081()
{
}

const SuperComponent::PinMap	Comp4081::_pins = {
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

nts::Tristate	Comp4081::internalCompute(PinNumber pin)
{
	switch (pin)
	{
		case 3:
			return (SimpleElec::andGate(getInputPin(1), getInputPin(2)));
			break;
		case 4:
			return (SimpleElec::andGate(getInputPin(5), getInputPin(6)));
			break;
		case 10:
			return (SimpleElec::andGate(getInputPin(8), getInputPin(9)));
			break;
		case 11:
			return (SimpleElec::andGate(getInputPin(12), getInputPin(13)));
			break;
		default:
			throw Err::UnknowPin("Comp4081 can't compute this pin.");
	}
}