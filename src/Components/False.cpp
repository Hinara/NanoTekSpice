/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** False
*/

#include <iostream>
#include "False.hpp"


False::False(const std::string &name)
: _name(name)
{
}

False::~False()
{
}

nts::Tristate	False::compute(std::size_t pin)
{
	return nts::Tristate::FALSE;
}

void		False::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin)
{
	throw std::exception();
}

void		False::dump() const
{
	std::cout << _name << " = 1" << std::endl;
}