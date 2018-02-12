/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Input
*/

#include <iostream>
#include "../Errors.hpp"
#include "Input.hpp"

Input::Input(const std::string &name)
: _name(name), _value(nts::UNDEFINED)
{
}

Input::~Input()
{
}

nts::Tristate	Input::compute(std::size_t pin)
{
	if (pin != 1)
		throw Err::UnknowPin("Input pin can only be equal to 1");
	return _value;
}

void		Input::setLink([[gnu::unused]] std::size_t pin, [[gnu::unused]] nts::IComponent &other, [[gnu::unused]] std::size_t otherpin)
{
	throw Err::LinkError("You can't link the \'Input\' component\n");
}

void		Input::dump() const
{
}