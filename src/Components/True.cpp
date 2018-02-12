/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** true
*/

#include <iostream>
#include "../Errors.hpp"
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
	return nts::TRUE;
}

void		True::setLink([[gnu::unused]] std::size_t pin, [[gnu::unused]] nts::IComponent &other, [[gnu::unused]] std::size_t otherpin)
{
	throw Err::LinkError("You can't link the \'True\' component\n");
}

void		True::dump() const
{
	std::cout << _name << " = 1" << std::endl;
}