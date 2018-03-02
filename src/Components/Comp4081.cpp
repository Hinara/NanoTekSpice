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

const Comp4081::CorrespondanceMap	Comp4081::_valuesTab = {
	{3, {1, 2}},
	{4, {5, 6}},
	{10, {8, 9}},
	{11, {12, 13}},
};

nts::Tristate	Comp4081::internalCompute(PinNumber pin)
{
	const InputPair &p = _valuesTab.at(pin);
	
	return (LogicGates::andGate(
		getInputPin(p.first), getInputPin(p.second)));
}