/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4069
*/

#include <sstream>
#include "../Errors.hpp"
#include "SimpleElec.hpp"
#include "Comp4069.hpp"

Comp4069::Comp4069(const std::string &name)
: SuperComponent(pins),_name(name)
{

}

Comp4069::~Comp4069()
{

}

const std::unordered_map<size_t,  SuperComponent::PinStatus>	Comp4069::pins = {
	{1, PinStatus::INPUT},
	{2, PinStatus::OUTPUT},
	{3, PinStatus::INPUT},
	{4, PinStatus::OUTPUT},
	{5, PinStatus::INPUT},
	{6, PinStatus::OUTPUT},
	{8, PinStatus::OUTPUT},
	{9, PinStatus::INPUT},
	{10, PinStatus::OUTPUT},
	{11, PinStatus::INPUT},
	{12, PinStatus::OUTPUT},
	{13, PinStatus::INPUT}
};

nts::Tristate	Comp4069::internalCompute(std::size_t pin)
{
	switch (pin)
	{
		case 2:
			return (SimpleElec::notGate(getInputPin(1)));
			break;
		case 4:
			return (SimpleElec::notGate(getInputPin(3)));
			break;
		case 6:
			return (SimpleElec::notGate(getInputPin(5)));
			break;
		case 8:
			return (SimpleElec::notGate(getInputPin(9)));
			break;
		case 10:
			return (SimpleElec::notGate(getInputPin(11)));
			break;
		case 12:
			return (SimpleElec::notGate(getInputPin(13)));
			break;
		default:
			throw Err::UnknowPin("Comp4069 can't compute this pin.");
	}
}