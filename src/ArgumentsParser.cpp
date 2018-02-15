/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** arguments parser
*/

#include <iostream>
#include "Components/Clock.hpp"
#include "Errors.hpp"
#include "ArgumentsParser.hpp"

ArgumentsParser::ArgumentsParser(char **args)
{
	for (std::size_t i = 0; args[i] != nullptr; i++)
		_args.push_back(std::string(args[i]));
}

ArgumentsParser::~ArgumentsParser()
{
}

bool	ArgumentsParser::setInputVal(Graph &graph, std::string var) const
{
	std::unordered_map<std::string, Input *> tab = graph.getInput();
	std::string val = var.substr(var.size() - 2, var.size());

	var = var.erase(var.size() - 2);
	for (auto it = tab.cbegin(); it !=  tab.cend(); it++) {
		if (it->first == var) {
			if (val == "=1")
				tab.at(var)->setState(nts::TRUE);
			else if (val == "=0")
				tab.at(var)->setState(nts::FALSE);
			else
				throw Err::ArgumentError("Bad value in arguments line: a value is equal to 1 or 0.");
			return true;
		}
	}
	return false;
}

bool	ArgumentsParser::setClockVal(Graph &graph, std::string var) const
{
	std::vector<std::string> tab = graph.getClock();
	std::string val = var.substr(var.size() - 2, var.size());

	var = var.erase(var.size() - 2);
	if (std::find(tab.cbegin(), tab.cend(), var) != tab.cend()) {
		if (val == "=1")
			(static_cast<Input *>(graph.getGraph().at(var).get()))->setState(nts::TRUE);
		else if (val == "=0")
			(static_cast<Input *>(graph.getGraph().at(var).get()))->setState(nts::FALSE);
		else
			throw Err::ArgumentError("Bad value in arguments line: a value is equal to 1 or 0.");
		return true;
	}
	return false;
}

void	ArgumentsParser::setVal(Graph &graph, std::string var) const
{
	if (var.size() <= 2)
		throw Err::ArgumentError("\'" + var + "\': bad format ex: \'input=1\'.");
	if (setInputVal(graph, var) == false) {
		if (setClockVal(graph, var) == false)
			throw Err::ArgumentError("\'" + var + "\': this argument is not an input or a clock.");
	}
}

void	ArgumentsParser::setValues(Graph &graph) const
{
	try
	{
		std::for_each(_args.begin(), _args.end(), [&graph, this](std::string var){ setVal(graph, var); });
	} catch (Err::Errors ex) {
		std::cerr << ex.what() << std::endl;
		throw std::exception();
	}
}
