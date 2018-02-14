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
#include "Components/ComponentFactory.hpp"
#include "Components/IComponent.hpp"

class Parser {
public:
	Parser(const std::string &);
	~Parser();
	void	parseFile(graph_s &);
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
	void	verifChipset(const std::string, graph_s &);
	void	verifLink(std::string, graph_s &);
	void	putInGraph(chipset_s, graph_s &);
	void	LinkGraph(link_s, graph_s &);
	void	parseLine(std::string, parseState &, graph_s &);
	bool	isKeyWord(const std::string, parseState &);
	bool	epurLine(std::string &line);
};

#endif /* !PARSER_HPP_ */
