/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4514
*/

#include "../Errors.hpp"
#include "Comp4514.hpp"

Comp4514::Comp4514(const std::string &)
: SuperComponent(_pins)
{
}

Comp4514::~Comp4514()
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

nts::Tristate	Comp4514::internalCompute(PinNumber pin)
{
}