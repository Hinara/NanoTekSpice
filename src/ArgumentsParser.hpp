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
	#include <algorithm>
	#include "Graph.hpp"

class ArgumentsParser {
	public:
		ArgumentsParser(char **);
		~ArgumentsParser();
		void	setValues(Graph &) const;
	private:
		std::vector<std::string>	_args;
	private:
		bool	setInputVal(Graph &, std::string) const;
		bool	setClockVal(Graph &, std::string) const;
		void	setVal(Graph &, std::string) const;
};

#endif /* !ARGUMENTSPARSER_HPP_ */
