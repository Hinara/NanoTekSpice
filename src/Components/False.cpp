/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** False
*/

#include <iostream>
#include "../Errors.hpp"
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
	return nts::FALSE;
}

void		False::setLink([[gnu::unused]] std::size_t pin, [[gnu::unused]] nts::IComponent &other, [[gnu::unused]] std::size_t otherpin)
{
	throw Err::LinkError("You can't link the \'False\' component\n");
}

void		False::dump() const
{
	std::cout << _name << " = 0" << std::endl;
}