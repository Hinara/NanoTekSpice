/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4017
*/

#include "../Errors.hpp"
#include "Comp4017.hpp"

Comp4017::Comp4017(const std::string &)
: SuperComponent(_pins)
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
}