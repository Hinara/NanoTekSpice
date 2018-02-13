/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4094
*/

#include <sstream>
#include "../Errors.hpp"
#include "Comp4094.hpp"

Comp4094::Comp4094(const std::string &name)
: _name(name)
{

}

Comp4094::~Comp4094()
{

}

nts::Tristate	Comp4094::compute(std::size_t pin)
{
}

void		Comp4094::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin)
{
	std::stringstream	myPin;

	myPin << pin;
	if (_links.size() < pin)
		throw Err::LinkError("Pin " + myPin.str() + " doesn't exist in the component 4094");
	else if (_links[pin].first != nullptr)
		throw Err::LinkError("Pin " + myPin.str() + " already connected");
	_links[pin].first = &other;
	_links[pin].second = otherpin;
}

void		Comp4094::dump() const
{
	
}