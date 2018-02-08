/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** true
*/

#include <iostream>
#include "True.hpp"

True::True(const std::string &name)
: _name(name), _val(nts::Tristate::TRUE)
{
}

True::~True()
{
}

nts::Tristate	True::compute(std::size_t pin)
{
}

void		True::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin)
{
	if (pin != 1 && _link)
		throw std::exception();
	_link = std::make_pair(1, other);
	other.setLink(otherpin, *this, this->_link.first);
}

void		True::dump() const
{
	std::cout << _name << " = " << _val << std::endl;
}