/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** error handling
*/

#include "Errors.hpp"

Err::Errors::Errors(std::string const &message, std::string const &component)
: _message(message), _component(component)
{
}

Err::Errors::~Errors()
{
}

const std::string	&Err::Errors::getComponent() const noexcept
{
	return _component;
}

const char		*Err::Errors::what() const noexcept
{
	return _message.data();
}

Err::ParsingError::ParsingError(std::string const &message, std::string const &component)
: Errors(message, component)
{
}

Err::LinkError::LinkError(std::string const &message, std::string const &component)
: Errors(message, component)
{
}

Err::UnknowPin::UnknowPin(std::string const &message, std::string const &component)
: Errors(message, component)
{
}

Err::ArgumentError::ArgumentError(std::string const &message, std::string const &component)
	: Errors(message, component)
{
}