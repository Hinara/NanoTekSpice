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
		Errors(std::string const &message, std::string const &component = "Unknown");
		~Errors();
		const std::string	&getComponent() const noexcept;
		virtual const char	*what() const noexcept;
	private:
		std::string	_message;
		std::string	_component;
	};

	class LexicalError	:	public Errors
	{
	public:
		LexicalError(std::string const &message, std::string const &component = "Unknown");
	};

	class UnknowType	:	public Errors
	{
	public:
		UnknowType(std::string const &message, std::string const &component = "Unknown");
	};

	class LinkError	:	public Errors
	{
	public:
		LinkError(std::string const &message, std::string const &component = "Unknown");
	};

	class SectionError	:	public Errors
	{
	public:
		SectionError(std::string const &message, std::string const &component = "Unknown");
	};

	class SegFault	:	public Errors
	{
	public:
		SegFault(std::string const &message, std::string const &component = "Unknown");
	};

	class InfiniteLoop	:	public Errors
	{
	public:
		InfiniteLoop(std::string const &message, std::string const &component = "Unknown");
	};

	class UnknowPin	:	public Errors
	{
	public:
		UnknowPin(std::string const &message, std::string const &component = "Unknown");
	};
	class DuplicatedSectionHeader :	public Errors
	{
	public:
		DuplicatedSectionHeader(std::string const &message, std::string const &component = "Unknown");
	};
};

#endif /* !ERRORS_HPP_ */
