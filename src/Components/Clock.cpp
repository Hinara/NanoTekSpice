/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** clock
*/

#include "../Errors.hpp"
#include "Clock.hpp"

Clock::Clock(const std::string &name)
: SuperComponent(pins), _name(name)
{
}

Clock::~Clock()
{
}
const std::unordered_map<size_t,  SuperComponent::PinStatus> Clock::pins = {
	{1, PinStatus::OUTPUT} };

nts::Tristate	Clock::internalCompute(std::size_t pin)
{
}