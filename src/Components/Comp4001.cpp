/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4001
*/

#include "../Errors.hpp"
#include "SimpleElec.hpp"
#include "Comp4001.hpp"

Comp4001::Comp4001(const std::string &)
: SuperComponent(pins)
{
}

Comp4001::~Comp4001()
{
}

const SuperComponent::PinMap	Comp4001::pins = {
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
			return (SimpleElec::norGate(getInputPin(1), getInputPin(2)));
			break;
		case 4:
			return (SimpleElec::norGate(getInputPin(5), getInputPin(6)));
			break;
		case 10:
			return (SimpleElec::norGate(getInputPin(8), getInputPin(9)));
			break;
		case 11:
			return (SimpleElec::norGate(getInputPin(12), getInputPin(13)));
			break;
		default:
			throw Err::UnknowPin("Comp4001 can't compute this pin.");
	}
}