/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4040
*/

#include "../Errors.hpp"
#include "Comp4040.hpp"

Comp4040::Comp4040(const std::string &)
: SuperComponent(_pins), _value(0), _lastState(nts::TRUE)
{
}

Comp4040::~Comp4040()
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

nts::Tristate	Comp4040::internalCompute(PinNumber pin)
{
	nts::Tristate state = getInputPin(10);

	if (state == nts::TRUE && _lastState != nts::TRUE) {
		_value += ((_value + 1) % 12);
	}
	_lastState = state;
	if (getInputPin(11) == nts::TRUE) {
		_value = 0;
	}
	return _value == _valuesTab.at(pin) ? nts::TRUE : nts::FALSE;
}