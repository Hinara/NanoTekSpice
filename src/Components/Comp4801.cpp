/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4801
*/

#include "../Errors.hpp"
#include "Comp4801.hpp"

Comp4801::Comp4801(const std::string &)
: SuperComponent(_pins)
{
}

const SuperComponent::PinMap	Comp4801::_pins = {
	{1, PinStatus::INPUT},
	{2, PinStatus::INPUT},
	{3, PinStatus::INPUT},
	{4, PinStatus::INPUT},
	{5, PinStatus::INPUT},
	{6, PinStatus::INPUT},
	{7, PinStatus::INPUT},
	{8, PinStatus::INPUT},
	{9, PinStatus::BIDIRECTIONNAL},
	{10, PinStatus::BIDIRECTIONNAL},
	{11, PinStatus::BIDIRECTIONNAL},
	{13, PinStatus::BIDIRECTIONNAL},
	{14, PinStatus::BIDIRECTIONNAL},
	{15, PinStatus::BIDIRECTIONNAL},
	{16, PinStatus::BIDIRECTIONNAL},
	{17, PinStatus::BIDIRECTIONNAL},
	{18, PinStatus::INPUT},
	{19, PinStatus::INPUT},
	{20, PinStatus::INPUT},
	{21, PinStatus::INPUT},
	{22, PinStatus::INPUT},
	{23, PinStatus::INPUT},
};

const Comp4801::CorrespondanceMap	Comp4801::_valuesTab = {
	{9, 1 << 0},
	{10, 1 << 1},
	{11, 1 << 2},
	{13, 1 << 3},
	{14, 1 << 4},
	{15, 1 << 5},
	{16, 1 << 6},
	{17, 1 << 7},
};



uint16_t	Comp4801::getAddress() const
{
	return (((getInputPin(8) == nts::TRUE) << 0) |
		((getInputPin(7) == nts::TRUE) << 1) |
		((getInputPin(6) == nts::TRUE) << 2) |
		((getInputPin(5) == nts::TRUE) << 3) |
		((getInputPin(4) == nts::TRUE) << 4) |
		((getInputPin(3) == nts::TRUE) << 5) |
		((getInputPin(2) == nts::TRUE) << 6) |
		((getInputPin(1) == nts::TRUE) << 7) |
		((getInputPin(23) == nts::TRUE) << 8) |
		((getInputPin(22) == nts::TRUE) << 9)
	);
}

uint8_t	Comp4801::getValue() const
{
	return (((getInputPin(9) == nts::TRUE) << 0) |
		((getInputPin(10) == nts::TRUE) << 1) |
		((getInputPin(11) == nts::TRUE) << 2) |
		((getInputPin(13) == nts::TRUE) << 3) |
		((getInputPin(14) == nts::TRUE) << 4) |
		((getInputPin(15) == nts::TRUE) << 5) |
		((getInputPin(16) == nts::TRUE) << 6) |
		((getInputPin(17) == nts::TRUE) << 7)
	);
}

nts::Tristate	Comp4801::internalCompute(PinNumber pin)
{
	if (getInputPin(18) != nts::TRUE) {
		if (getInputPin(21) != nts::TRUE) {
			_values[getAddress()] = getValue();
		} else if (getInputPin(20) != nts::TRUE) {
			return ((_values[getAddress()] & _valuesTab.at(pin)) ? 
				nts::TRUE : nts::FALSE);
		}
	}
	return nts::UNDEFINED;
}