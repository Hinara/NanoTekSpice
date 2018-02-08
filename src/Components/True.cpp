/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** true
*/

#include <iostream>
#include "True.hpp"

True::True(const std::string &name)
: _name(name)
{
}

True::~True()
{
}

nts::Tristate	True::compute(std::size_t pin)
{
	return nts::Tristate::TRUE;
}

void		True::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin)
{
	throw std::exception();
}

void		True::dump() const
{
	std::cout << _name << " = 1" << std::endl;
}