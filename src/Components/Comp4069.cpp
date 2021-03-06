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

const Comp4069::CorrespondanceMap	Comp4069::_valuesTab = {
	{2, 1},
	{4, 3},
	{6, 5},
	{8, 9},
	{10, 11},
	{12, 13},
};

nts::Tristate	Comp4069::internalCompute(PinNumber pin)
{
	return (LogicGates::notGate(getInputPin(_valuesTab.at(pin))));
}