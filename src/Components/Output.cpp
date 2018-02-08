/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Output
*/

#include <iostream>
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
	if (pin != 1)
		throw std::exception();
}

void		Output::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin)
{
	if (pin != 1 && _links[1].first)
		throw std::exception();
	_links[1].first = &other;
	_links[1].second = otherpin;
}

void		Output::dump() const
{
}