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

nts::Tristate	Comp4013::internalCompute(PinNumber pin)
{
}