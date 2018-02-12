/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Output
*/

#include <iostream>
#include "../Errors.hpp"
#include "Output.hpp"

Output::Output(const std::string &name)
: _name(name), _links({{1, {NULL, 0}}})
{
}

Output::~Output()
{
}

nts::Tristate	Output::compute(std::size_t pin)
{
}

void		Output::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin)
{
	if (pin != 1 && _links[1].first)
		throw Err::LinkError("You can't link the pin: it's already exist or is not equal to 1\n");
	_links[1].first = &other;
	_links[1].second = otherpin;
}

void		Output::dump() const
{
}