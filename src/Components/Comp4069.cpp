/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4069
*/

#include <sstream>
#include "../Errors.hpp"
#include "Comp4069.hpp"

Comp4069::Comp4069(const std::string &name)
: _name(name)
{

}

Comp4069::~Comp4069()
{

}

nts::Tristate	Comp4069::compute(std::size_t pin)
{
}

void		Comp4069::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin)
{
	std::stringstream	myPin;

	myPin << pin;
	if (_links.size() < pin)
		throw Err::LinkError("Pin " + myPin.str() + " doesn't exist in the component 4069");
	else if (_links[pin].first != nullptr)
		throw Err::LinkError("Pin " + myPin.str() + " already connected");
	_links[pin].first = &other;
	_links[pin].second = otherpin;
}

void		Comp4069::dump() const
{
	
}