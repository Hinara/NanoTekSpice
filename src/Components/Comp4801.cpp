/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4801
*/

#include <sstream>
#include "../Errors.hpp"
#include "Comp4801.hpp"

Comp4801::Comp4801(const std::string &)
: SuperComponent(pins)
{
}

Comp4801::~Comp4801()
{
}

const SuperComponent::PinMap	Comp4801::pins = {
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

nts::Tristate	Comp4801::internalCompute(PinNumber pin)
{
}