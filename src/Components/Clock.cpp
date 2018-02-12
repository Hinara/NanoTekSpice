/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** clock
*/

#include "../Errors.hpp"
#include "Clock.hpp"

Clock::Clock(const std::string &name)
: _name(name)
{
}

Clock::~Clock()
{
}

nts::Tristate	Clock::compute(std::size_t pin)
{
	if (pin != 1)
		throw Err::UnknowPin("This pin doesn't exist.\n");
	_value = static_cast<nts::Tristate>(-_value);
	return static_cast<nts::Tristate>(-_value);
}

void		Clock::setLink([[gnu::unused]] std::size_t pin, [[gnu::unused]] nts::IComponent &other, [[gnu::unused]] std::size_t otherpin)
{
	throw Err::LinkError("Clock can't link.\n");
}

void		Clock::dump() const
{
	
}