/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4013
*/

#include "../Errors.hpp"
#include "Comp4013.hpp"

Comp4013::Comp4013(const std::string &)
: SuperComponent(_pins)
{
}

Comp4013::~Comp4013()
{
}

const SuperComponent::PinMap	Comp4013::_pins = {
	{1, PinStatus::OUTPUT},
	{2, PinStatus::OUTPUT},
	{3, PinStatus::INPUT},
	{4, PinStatus::INPUT},
	{5, PinStatus::INPUT},
	{6, PinStatus::INPUT},
	{8, PinStatus::INPUT},
	{9, PinStatus::INPUT},
	{10, PinStatus::INPUT},
	{11, PinStatus::INPUT},
	{12, PinStatus::OUTPUT},
	{13, PinStatus::OUTPUT}
};

std::pair<nts::Tristate, nts::Tristate>	Comp4013::flipFlop(nts::Tristate in1, nts::Tristate in2, nts::Tristate clock)
{
	std::pair<nts::Tristate, nts::Tristate>	res;
	nts::Tristate	val1 = LogicGate::andGate(in1, clock);
	nts::Tristate	val2 = LogicGate::andGate(in2, clock);
}

nts::Tristate	Comp4013::internalCompute(PinNumber pin)
{

}