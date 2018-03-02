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

const Comp4001::CorrespondanceMap	Comp4001::_valuesTab = {
	{3, {1, 2}},
	{4, {5, 6}},
	{10, {8, 9}},
	{11, {12, 13}},
};

nts::Tristate	Comp4001::internalCompute(PinNumber pin)
{
	const InputPair &p = _valuesTab.at(pin);
	
	return (LogicGates::norGate(
		getInputPin(p.first), getInputPin(p.second)));
}