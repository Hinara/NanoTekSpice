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
: _name(name)
{

}

Comp4008::~Comp4008()
{

}

nts::Tristate	Comp4008::compute(std::size_t pin)
{
}

void		Comp4008::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin)
{
	std::stringstream	myPin;

	myPin << pin;
	if (_links.size() < pin)
		throw Err::LinkError("Pin " + myPin.str() + " doesn't exist in the component 4008");
	else if (_links[pin].first != nullptr)
		throw Err::LinkError("Pin " + myPin.str() + " already connected");
	_links[pin].first = &other;
	_links[pin].second = otherpin;
}

void		Comp4008::dump() const
{
	
}