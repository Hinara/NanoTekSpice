/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4094
*/

#include "../Errors.hpp"
#include "Comp4094.hpp"
#include <iostream>
#include <bitset>

Comp4094::Comp4094(const std::string &)
: SuperComponent(_pins), _value(0), _display(0),
	_notQs(nts::FALSE), _lastState(nts::TRUE)
{
}

const SuperComponent::PinMap	Comp4094::_pins = {
	{1, PinStatus::INPUT},
	{2, PinStatus::INPUT},
	{3, PinStatus::INPUT},
	{4, PinStatus::OUTPUT},
	{5, PinStatus::OUTPUT},
	{6, PinStatus::OUTPUT},
	{7, PinStatus::OUTPUT},
	{9, PinStatus::OUTPUT},
	{10, PinStatus::OUTPUT},
	{11, PinStatus::OUTPUT},
	{12, PinStatus::OUTPUT},
	{13, PinStatus::OUTPUT},
	{14, PinStatus::OUTPUT},
	{15, PinStatus::INPUT}
};

const Comp4094::CorrespondanceMap	Comp4094::_valuesTab = {
	{4, 1 << 0},
	{5, 1 << 1},
	{6, 1 << 2},
	{7, 1 << 3},
	{14, 1 << 4},
	{13, 1 << 5},
	{12, 1 << 6},
	{11, 1 << 7}
};

nts::Tristate	Comp4094::internalCompute(PinNumber pin)
{
	nts::Tristate	clck = getInputPin(3);

	if (_lastState != nts::TRUE && clck == nts::TRUE)
		_value = (_value << 1) | (getInputPin(2) == nts::TRUE);
	if (_lastState != nts::FALSE && clck == nts::FALSE)
		_notQs = (_value & (1 << 7)) ? nts::TRUE : nts::FALSE;
	_lastState = clck;
	if (getInputPin(1) == nts::TRUE)
		_display = _value;
	if (pin == 9)
		return (_value & (1 << 7)) ? nts::TRUE : nts::FALSE;
	if (pin == 10)
		return _notQs;
	if (getInputPin(15) == nts::TRUE)
		return (_display & _valuesTab.at(pin)) ? nts::TRUE : nts::FALSE;
	return nts::UNDEFINED;
}

void 	Comp4094::dump() const
{
	std::cout << "\tInternal value: " << std::bitset<8>(
			static_cast<long long unsigned int>(_value))
		<< "\n\tDisplay value: " << std::bitset<8>(
			static_cast<long long unsigned int>(_display))
		<< "\n\tPrevious State: " << _lastState
		<< "\n\tNot Q: " << _notQs << std::endl;
}