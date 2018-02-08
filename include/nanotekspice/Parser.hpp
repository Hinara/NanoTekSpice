/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** parser
*/

#ifndef PARSER_HPP_
	#define PARSER_HPP_

#include <fstream>
#include <exception>
#include <map>
#include <deque>
#include <vector>
#include <string>
#include <algorithm>
#include "Nano.hpp"
#include "IComponent.hpp"

class Parser {
	public:
		Parser(const std::string &);
		~Parser();
		void	parseFile();
		std::deque<chipset_s>	getChipsets() const { return _chipsets; }
		std::deque<link_s>	getLinks() const { return _links; }
	private:
		const std::string	_filename;
		std::deque<chipset_s>	_chipsets;
		std::deque<link_s>	_links;
		const std::vector<std::string>	_comp = {
			"input", "output", "2716", "4001", "4008",
			"4011", "4013", "4017", "4030", "4040", "4069",
			"4071", "4081", "4094", "4514", "4801", "clock", "true", "false"
		};
	private:
		void	verifChipset(const std::string);
		void	verifLink(const std::string);
		void	parseLine(const std::string, int &, int &);
		char	isKeyWord(const std::string, int &, int &);
		char	epurLine(std::string &line);
};

#endif /* !PARSER_HPP_ */
