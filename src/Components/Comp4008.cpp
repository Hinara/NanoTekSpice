/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4008
*/

#include <sstream>
#include "../Errors.hpp"
#include "Comp4008.hpp"

Comp4008::Comp4008(const std::string &name)
: SuperComponent(pins), _name(name)
{

}

Comp4008::~Comp4008()
{

}

const std::unordered_map<size_t,  SuperComponent::PinStatus>	Comp4008::pins = {
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

nts::Tristate	Comp4008::internalCompute(std::size_t pin)
{
}