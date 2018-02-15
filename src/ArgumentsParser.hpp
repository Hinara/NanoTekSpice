/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** argument parser
*/

#ifndef ARGUMENTSPARSER_HPP_
	#define ARGUMENTSPARSER_HPP_

#include <string>
#include <vector>

class ArgumentsParser {
	public:
		ArgumentsParser(const char **);
		~ArgumentsParser();
	private:
		std::vector<std::string>	_args;
};

#endif /* !ARGUMENTSPARSER_HPP_ */
