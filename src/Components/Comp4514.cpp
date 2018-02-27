/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4514
*/

#include "../Errors.hpp"
#include "Comp4514.hpp"

Comp4514::Comp4514(const std::string &)
: SuperComponent(_pins), _value(nts::FALSE)
{
}

const SuperComponent::PinMap	Comp4514::_pins = {
	{1, PinStatus::INPUT},
	{2, PinStatus::INPUT},
	{3, PinStatus::INPUT},
	{4, PinStatus::OUTPUT},
	{5, PinStatus::OUTPUT},
	{6, PinStatus::OUTPUT},
	{7, PinStatus::OUTPUT},
	{8, PinStatus::OUTPUT},
	{9, PinStatus::OUTPUT},
	{10, PinStatus::OUTPUT},
	{11, PinStatus::OUTPUT},
	{13, PinStatus::OUTPUT},
	{14, PinStatus::OUTPUT},
	{15, PinStatus::OUTPUT},
	{16, PinStatus::OUTPUT},
	{17, PinStatus::OUTPUT},
	{18, PinStatus::OUTPUT},
	{19, PinStatus::OUTPUT},
	{20, PinStatus::OUTPUT},
	{21, PinStatus::INPUT},
	{22, PinStatus::INPUT},
	{23, PinStatus::INPUT}
};

const Comp4514::CorrespondanceMap	Comp4514::_valuesTab = {
	{11, 0},
	{9, 1},
	{10, 2},
	{8, 3},
	{7, 4},
	{6, 5},
	{5, 6},
	{4, 7},
	{18, 8},
	{17, 9},
	{20, 10},
	{19, 11},
	{14, 12},
	{13, 13},
	{16, 14},
	{15, 15}
};

nts::Tristate	Comp4514::internalCompute(PinNumber pin)
{
	if (getInputPin(1) == nts::TRUE) {
		_value = ((getInputPin(2) == nts::TRUE) << 3) |
			((getInputPin(3) == nts::TRUE) << 2) |
			((getInputPin(21) == nts::TRUE) << 1) |
			((getInputPin(22) == nts::TRUE) << 0);
	}
	if (getInputPin(23) == nts::TRUE)
		return nts::FALSE;
	return (_valuesTab.at(pin) == _value) ? nts::TRUE : nts::FALSE;
}