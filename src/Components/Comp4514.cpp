/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4514
*/

#include <sstream>
#include "../Errors.hpp"
#include "Comp4514.hpp"

Comp4514::Comp4514(const std::string &name)
: _name(name)
{

}

Comp4514::~Comp4514()
{

}

nts::Tristate	Comp4514::compute(std::size_t pin)
{
}

void		Comp4514::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin)
{
	std::stringstream	myPin;

	myPin << pin;
	if (_links.size() < pin)
		throw Err::LinkError("Pin " + myPin.str() + " doesn't exist in the component 2716\n");
	else if (_links[pin].first != nullptr)
		throw Err::LinkError("Pin " + myPin.str() + " already connected\n");
	_links[pin].first = &other;
	_links[pin].second = otherpin;
}

void		Comp4514::dump() const
{
	
}