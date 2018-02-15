/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4514
*/

#include <sstream>
#include "../Errors.hpp"
#include "Comp4514.hpp"

Comp4514::Comp4514(const std::string &)
: SuperComponent(pins)
{
}

Comp4514::~Comp4514()
{
}

const SuperComponent::PinMap	Comp4514::pins = {
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

nts::Tristate	Comp4514::internalCompute(PinNumber pin)
{
}