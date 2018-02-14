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
: _name(name), _links({NULL, 0})
{
}

Output::~Output()
{
}

nts::Tristate	Output::compute(std::size_t pin)
{
	if (pin != 1)
		throw Err::SectionError("Output only have one pin.");
	_links.first->compute(_links.second);
}

void		Output::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin)
{
	if (pin != 1 && _links.first)
		throw Err::LinkError("You can't link the pin: it's already exist or is not equal to 1\n");
	_links.first = &other;
	_links.second = otherpin;
}

void		Output::dump() const
{
}