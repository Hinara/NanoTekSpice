/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 2716
*/

#include <sstream>
#include "../Errors.hpp"
#include "Comp2716.hpp"

Comp2716::Comp2716(const std::string &name)
: _name(name)
{

}

Comp2716::~Comp2716()
{

}

nts::Tristate	Comp2716::compute(std::size_t pin)
{
}

void		Comp2716::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin)
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

void		Comp2716::dump() const
{
	
}