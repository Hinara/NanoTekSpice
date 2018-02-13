/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4071
*/

#include <sstream>
#include "../Errors.hpp"
#include "Comp4071.hpp"

Comp4071::Comp4071(const std::string &name)
: _name(name)
{

}

Comp4071::~Comp4071()
{

}

nts::Tristate	Comp4071::compute(std::size_t pin)
{
}

void		Comp4071::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin)
{
	std::stringstream	myPin;

	myPin << pin;
	if (_links.size() < pin)
		throw Err::LinkError("Pin " + myPin.str() + " doesn't exist in the component 4071");
	else if (_links[pin].first != nullptr)
		throw Err::LinkError("Pin " + myPin.str() + " already connected");
	_links[pin].first = &other;
	_links[pin].second = otherpin;
}

void		Comp4071::dump() const
{
	
}