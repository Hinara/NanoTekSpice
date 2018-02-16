/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4008
*/

#include "../Errors.hpp"
#include "SimpleElec.hpp"
#include "Comp4008.hpp"

Comp4008::Comp4008(const std::string &)
: SuperComponent(pins)
{
}

Comp4008::~Comp4008()
{
}

const SuperComponent::PinMap	Comp4008::pins = {
	{1, PinStatus::INPUT},
	{2, PinStatus::INPUT},
	{3, PinStatus::INPUT},
	{4, PinStatus::INPUT},
	{5, PinStatus::INPUT},
	{6, PinStatus::INPUT},
	{7, PinStatus::INPUT},
	{9, PinStatus::INPUT},
	{10, PinStatus::OUTPUT},
	{11, PinStatus::OUTPUT},
	{12, PinStatus::OUTPUT},
	{13, PinStatus::OUTPUT},
	{14, PinStatus::OUTPUT},
	{15, PinStatus::INPUT}
};

std::pair<nts::Tristate, nts::Tristate>	Comp4008::bitFullAdder(nts::Tristate p1,
	nts::Tristate p2, nts::Tristate p3)
{
	std::pair<nts::Tristate, nts::Tristate> pair;
	nts::Tristate tmp = SimpleElec::xorGate(p1, p2);
	pair.first = SimpleElec::xorGate(tmp, p3);
	pair.second = SimpleElec::orGate(
		SimpleElec::andGate(tmp, p3), SimpleElec::andGate(p1, p2)
	);
	return (pair);
}

nts::Tristate	Comp4008::internalCompute(PinNumber pin)
{
	if (pin < 10 || pin > 14)
		throw;
	auto p = bitFullAdder(getInputPin(7), getInputPin(6), getInputPin(9));
	if (pin >= 11)
		p = bitFullAdder(getInputPin(7), getInputPin(6), p.second);
	if (pin >= 12)
		p = bitFullAdder(getInputPin(7), getInputPin(6), p.second);
	if (pin >= 13)
		p = bitFullAdder(getInputPin(7), getInputPin(6), p.second);
	if (pin >= 14)
		return (p.second);
	return (p.first);
}