/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4017
*/

#include <sstream>
#include "../Errors.hpp"
#include "Comp4017.hpp"

Comp4017::Comp4017(const std::string &name)
: _name(name)
{

}

Comp4017::~Comp4017()
{

}

nts::Tristate	Comp4017::compute(std::size_t pin)
{
}

void		Comp4017::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin)
{
	std::stringstream	myPin;

	myPin << pin;
	if (_links.size() < pin)
		throw Err::LinkError("Pin " + myPin.str() + " doesn't exist in the component 4017");
	else if (_links[pin].first != nullptr)
		throw Err::LinkError("Pin " + myPin.str() + " already connected");
	_links[pin].first = &other;
	_links[pin].second = otherpin;
}

void		Comp4017::dump() const
{
	
}