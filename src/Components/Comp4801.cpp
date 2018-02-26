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

Comp4801::~Comp4801()
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

nts::Tristate	Comp4801::internalCompute(PinNumber pin)
{
}