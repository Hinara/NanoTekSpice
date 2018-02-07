/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Output
*/

#include "Output.hpp"

Output::Output(const std::string &name)
: _name(name), _value(nts::Tristate::UNDEFINED)
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

}

void		Output::dump() const
{
	
}