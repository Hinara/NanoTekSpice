/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4040
*/

#include <sstream>
#include "../Errors.hpp"
#include "Comp4040.hpp"

Comp4040::Comp4040(const std::string &name)
: _name(name)
{

}

Comp4040::~Comp4040()
{

}

nts::Tristate	Comp4040::compute(std::size_t pin)
{
}

void		Comp4040::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin)
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

void		Comp4040::dump() const
{
	
}