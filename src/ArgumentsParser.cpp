/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** arguments parser
*/

#include "ArgumentsParser.hpp"

ArgumentsParser::ArgumentsParser(const char **args)
{
	for (std::size_t i = 0; args[i] != nullptr; i++)
		_args.push_back(std::string(args[i]));
}

ArgumentsParser::~ArgumentsParser()
{
}
