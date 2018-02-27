/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4040
*/

#include "../Errors.hpp"
#include "LogicGates.hpp"
#include "Comp4040.hpp"

Comp4040::Comp4040(const std::string &)
: SuperComponent(_pins), _value(0), _lastState(nts::TRUE)
{
}

const SuperComponent::PinMap	Comp4040::_pins = {
	{1, PinStatus::OUTPUT},
	{2, PinStatus::OUTPUT},
	{3, PinStatus::OUTPUT},
	{4, PinStatus::OUTPUT},
	{5, PinStatus::OUTPUT},
	{6, PinStatus::OUTPUT},
	{7, PinStatus::OUTPUT},
	{9, PinStatus::OUTPUT},
	{10, PinStatus::INPUT},
	{11, PinStatus::INPUT},
	{12, PinStatus::OUTPUT},
	{13, PinStatus::OUTPUT},
	{14, PinStatus::OUTPUT},
	{15, PinStatus::OUTPUT}
};

const Comp4040::CorrespondanceMap	Comp4040::_valuesTab = {
	{9, 1 << 0},
	{7, 1 << 1},
	{6, 1 << 2},
	{5, 1 << 3},
	{3, 1 << 4},
	{2, 1 << 5},
	{4, 1 << 6},
	{13, 1 << 7},
	{12, 1 << 8},
	{14, 1 << 9},
	{15, 1 << 10},
	{1, 1 << 11}
};

nts::Tristate	Comp4040::internalCompute(PinNumber pin)
{
	nts::Tristate state = LogicGates::notGate(getInputPin(10));

	if (state == nts::TRUE && _lastState != nts::TRUE) {
		_value = ((_value + 1) % (1 << 12));
	}
	_lastState = state;
	if (getInputPin(11) == nts::TRUE) {
		_value = 0;
	}
	return ((_value & _valuesTab.at(pin)) ? nts::TRUE : nts::FALSE);
}