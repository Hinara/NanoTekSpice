/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Input
*/

#include "Input.hpp"

Input::Input(const std::string &name)
: _name(name), _value(nts::Tristate::UNDEFINED)
{
}

Input::~Input()
{
}

nts::Tristate	Input::compute(std::size_t pin)
{
}

void		Input::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin)
{

}

void		Input::dump() const
{

}