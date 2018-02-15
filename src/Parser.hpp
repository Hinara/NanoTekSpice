/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** parser
*/

#ifndef PARSER_HPP_
	#define PARSER_HPP_

#include <fstream>
#include <map>
#include <deque>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include "Nano.hpp"
#include "Errors.hpp"
#include "Graph.hpp"
#include "Components/ComponentFactory.hpp"
#include "Components/IComponent.hpp"

class Parser {
public:
	Parser(const std::string &);
	~Parser();
	void	parseFile(Graph &);
private:
	enum parseState {
		NONE,
		CHIPSET,
		LINK
	};
	const std::string	_filename;
	const std::vector<std::string>	_comp = {
		"input", "output", "2716", "4001", "4008",
		"4011", "4013", "4017", "4030", "4040", "4069",
		"4071", "4081", "4094", "4514", "4801", "clock", "true", "false"
	};
private:
	void	verifChipset(const std::string, Graph &);
	void	verifLink(std::string, Graph &);
	void	parseLine(std::string, parseState &, Graph &);
	bool	isKeyWord(const std::string, parseState &);
	bool	epurLine(std::string &line);
};

#endif /* !PARSER_HPP_ */
