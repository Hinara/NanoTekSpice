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

nts::Tristate	Comp4013::internalCompute(PinNumber pin)
{
	bool		part = (pin > 7);
	bool		q = (pin % 2);
	nts::Tristate	set = getInputPin(part ? 8 : 6);
	nts::Tristate	data = getInputPin(part ? 9 : 5);
	nts::Tristate	reset = getInputPin(part ? 10 : 4);
	nts::Tristate	clock = getInputPin(part ? 11 : 3);

	if (_lastState[part] != nts::TRUE && clock == nts::TRUE)
		_value[part] = (data == nts::TRUE) ? nts::TRUE : nts::FALSE;
	_lastState[part] = clock;
	if (set == nts::TRUE)
		_value[part] = nts::TRUE;
	if (reset == nts::TRUE)
		_value[part] = nts::FALSE;
	if (q)
		return ((set == nts::TRUE) ? nts::TRUE : _value[part]);
	return ((reset == nts::TRUE) ? nts::TRUE : _value[part]);
}