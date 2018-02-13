/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4081
*/

#include <sstream>
#include "../Errors.hpp"
#include "Comp4081.hpp"

Comp4081::Comp4081(const std::string &name)
: _name(name)
{

}

Comp4081::~Comp4081()
{

}

nts::Tristate	Comp4081::compute(std::size_t pin)
{
}

void		Comp4081::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin)
{
	std::stringstream	myPin;

	myPin << pin;
	if (_links.size() < pin)
		throw Err::LinkError("Pin " + myPin.str() + " doesn't exist in the component 4081");
	else if (_links[pin].first != nullptr)
		throw Err::LinkError("Pin " + myPin.str() + " already connected");
	_links[pin].first = &other;
	_links[pin].second = otherpin;
}

void		Comp4081::dump() const
{
	
}