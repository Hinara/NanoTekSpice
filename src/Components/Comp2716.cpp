/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 2716
*/

#include "../Errors.hpp"
#include "Comp2716.hpp"

Comp2716::Comp2716(const std::string &)
: SuperComponent(_pins)
{
}

const SuperComponent::PinMap	Comp2716::_pins = {
	{1, PinStatus::INPUT},
	{2, PinStatus::INPUT},
	{3, PinStatus::INPUT},
	{4, PinStatus::INPUT},
	{5, PinStatus::INPUT},
	{6, PinStatus::INPUT},
	{7, PinStatus::INPUT},
	{8, PinStatus::INPUT},
	{9, PinStatus::OUTPUT},
	{10, PinStatus::OUTPUT},
	{11, PinStatus::OUTPUT},
	{13, PinStatus::OUTPUT},
	{14, PinStatus::OUTPUT},
	{15, PinStatus::OUTPUT},
	{16, PinStatus::OUTPUT},
	{17, PinStatus::OUTPUT},
	{18, PinStatus::INPUT},
	{19, PinStatus::INPUT},
	{20, PinStatus::INPUT},
	{21, PinStatus::INPUT},
	{22, PinStatus::INPUT},
	{23, PinStatus::INPUT}
};

nts::Tristate	Comp2716::internalCompute(PinNumber)
{
	return nts::UNDEFINED;
}