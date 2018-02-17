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
		ArgumentsParser(Graph &);
		~ArgumentsParser();
		void		setValues(const int ac, const char **av);
	private:
		using PairNameState = std::pair<std::string, nts::Tristate>;
		Graph		&_g;
		void		setVal(std::string);
		PairNameState	getState(std::string var);
};

#endif /* !ARGUMENTSPARSER_HPP_ */
