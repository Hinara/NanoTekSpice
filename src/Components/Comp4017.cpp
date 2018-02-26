/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4017
*/

#include "../Errors.hpp"
#include "Comp4017.hpp"

Comp4017::Comp4017(const std::string &)
: SuperComponent(_pins), _value(0), _lastState(nts::TRUE)
{
}

Comp4017::~Comp4017()
{
}

const SuperComponent::PinMap	Comp4017::_pins = {
	{1, PinStatus::OUTPUT},
	{2, PinStatus::OUTPUT},
	{3, PinStatus::OUTPUT},
	{4, PinStatus::OUTPUT},
	{5, PinStatus::OUTPUT},
	{6, PinStatus::OUTPUT},
	{7, PinStatus::OUTPUT},
	{9, PinStatus::OUTPUT},
	{10, PinStatus::OUTPUT},
	{11, PinStatus::OUTPUT},
	{12, PinStatus::OUTPUT},
	{13, PinStatus::INPUT},
	{14, PinStatus::INPUT},
	{15, PinStatus::INPUT}
};

nts::Tristate	Comp4017::internalCompute(PinNumber pin)
{
	nts::Tristate	state = LogicGate::andGate(LogicGate::notGate(getInputPin(13)), getInputPin(14));
	nts::Tristate	ret = nts::UNDEFINED;

	if (state == nts::TRUE && _lastState != nts::TRUE)
		_value += ((_value + 1) % 10);
	_lastState = state;
	if (getInputPin(15) == nts::TRUE)
		_value = 0;
	if (pin == 12)
		ret = (_value < 5 ? nts::TRUE : nts::FALSE);
	else
		ret = (_value == _valuesTab.at(pin) ? nts::TRUE : nts::FALSE);
	return ret;
}