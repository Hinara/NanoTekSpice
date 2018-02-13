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
	void	parseFile();
	//std::map<const std::string, std::unique_ptr<nts::IComponent>>	getGraph() const;
private:
	const std::string	_filename;
	std::map<const std::string, std::unique_ptr<nts::IComponent>>	_graph;
	std::map<const std::string, std::unique_ptr<nts::IComponent>>	_output;
	std::map<const std::string, std::unique_ptr<nts::IComponent>>	_component;
	const std::vector<std::string>	_comp = {
		"input", "output", "2716", "4001", "4008",
		"4011", "4013", "4017", "4030", "4040", "4069",
		"4071", "4081", "4094", "4514", "4801", "clock", "true", "false"
	};
private:
	void	verifChipset(const std::string);
	void	verifLink(std::string);
	void	putInControler(chipset_s);
	void	LinkGraph(link_s);
	void	parseLine(std::string, int &, int &);
	char	isKeyWord(const std::string, int &, int &);
	char	epurLine(std::string &line);
};

#endif /* !PARSER_HPP_ */
