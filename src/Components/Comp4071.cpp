/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4071
*/

#include "../Errors.hpp"
#include "LogicGates.hpp"
#include "Comp4071.hpp"

Comp4071::Comp4071(const std::string &)
: SuperComponent(_pins)
{
}

const SuperComponent::PinMap	Comp4071::_pins = {
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

const Comp4071::CorrespondanceMap	Comp4071::_valuesTab = {
	{3, {1, 2}},
	{4, {5, 6}},
	{10, {8, 9}},
	{11, {12, 13}},
};

nts::Tristate	Comp4071::internalCompute(PinNumber pin)
{
	const InputPair &p = _valuesTab.at(pin);
	
	return (LogicGates::orGate(
		getInputPin(p.first), getInputPin(p.second)));
}