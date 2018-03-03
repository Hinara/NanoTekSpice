/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** error handling
*/

#include "Errors.hpp"

Err::Errors::Errors(std::string const &message)
: _message(message)
{
}

Err::Errors::~Errors()
{
}

const char		*Err::Errors::what() const noexcept
{
	return _message.data();
}

Err::ParsingError::ParsingError(std::string const &message)
: Errors(message)
{
}

Err::LinkError::LinkError(std::string const &message)
: Errors(message)
{
}

Err::UnknowPin::UnknowPin(std::string const &message)
: Errors(message)
{
}

Err::ArgumentError::ArgumentError(std::string const &message)
	: Errors(message)
{
}