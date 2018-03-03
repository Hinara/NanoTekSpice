/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** error handling
*/

#ifndef ERRORS_HPP_
	#define ERRORS_HPP_

#include <exception>
#include <string>

namespace Err
{
	class Errors	:	public std::exception
	{
	public:
		Errors(std::string const &message);
		~Errors();
		virtual const char	*what() const noexcept;
	private:
		std::string	_message;
		std::string	_component;
	};

	class ParsingError	:	public Errors
	{
	public:
		ParsingError(std::string const &message);
	};

	class LinkError	:	public Errors
	{
	public:
		LinkError(std::string const &message);
	};

	class SectionError	:	public Errors
	{
	public:
		SectionError(std::string const &message);
	};

	class UnknowPin	:	public Errors
	{
	public:
		UnknowPin(std::string const &message);
	};

	class ArgumentError	:	public Errors
	{
	public:
		ArgumentError(std::string const &message);
	};
};

#endif /* !ERRORS_HPP_ */
