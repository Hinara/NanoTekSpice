/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4011
*/

#include <sstream>
#include "../Errors.hpp"
#include "Comp4011.hpp"

Comp4011::Comp4011(const std::string &name)
: _name(name)
{

}

Comp4011::~Comp4011()
{

}

nts::Tristate	Comp4011::compute(std::size_t pin)
{
}

void		Comp4011::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin)
{
	std::stringstream	myPin;

	myPin << pin;
	if (_links.size() < pin)
		throw Err::LinkError("Pin " + myPin.str() + " doesn't exist in the component 4011");
	else if (_links[pin].first != nullptr)
		throw Err::LinkError("Pin " + myPin.str() + " already connected");
	_links[pin].first = &other;
	_links[pin].second = otherpin;
}

void		Comp4011::dump() const
{
	
}