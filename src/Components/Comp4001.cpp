/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4001
*/

#include <sstream>
#include "../Errors.hpp"
#include "Comp4001.hpp"

Comp4001::Comp4001(const std::string &name)
: _name(name)
{

}

Comp4001::~Comp4001()
{

}

nts::Tristate	Comp4001::compute(std::size_t pin)
{
}

void		Comp4001::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin)
{
	std::stringstream	myPin;

	myPin << pin;
	if (_links.size() < pin)
		throw Err::LinkError("Pin " + myPin.str() + " doesn't exist in the component 4001");
	else if (_links[pin].first != nullptr)
		throw Err::LinkError("Pin " + myPin.str() + " already connected");
	_links[pin].first = &other;
	_links[pin].second = otherpin;
}

void		Comp4001::dump() const
{
	
}