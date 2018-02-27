/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4094
*/

#include "../Errors.hpp"
#include "Comp4094.hpp"

Comp4094::Comp4094(const std::string &)
: SuperComponent(_pins)
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

nts::Tristate	Comp4094::internalCompute(PinNumber pin)
{
}