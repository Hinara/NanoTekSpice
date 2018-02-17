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

ArgumentsParser::ArgumentsParser(Graph &g)
	:_g(g)
{
}

ArgumentsParser::~ArgumentsParser()
{
}

ArgumentsParser::PairNameState	ArgumentsParser::getState(std::string var)
{
	std::string suffix = var.substr(var.size() - 2, var.size());
	PairNameState res;
	res.first = var.erase(var.size() - 2);
	if (suffix == "=1")
		res.second = nts::TRUE;
	else if (suffix == "=0")
		res.second = nts::FALSE;
	else
		throw Err::ArgumentError("Bad value in arguments line: a value is equal to 1 or 0.");
	return (res);
}

void	ArgumentsParser::setVal(std::string var)
{
	PairNameState p = getState(var);
	Input *elem = nullptr;
	const Graph::InputMap &inputs = _g.getInputs();
	std::unordered_map<std::string, Input *>::const_iterator it;
	it = inputs.find(p.first);
	if (it != inputs.cend())
		elem = it->second;
	if (elem == nullptr) {
		const Graph::ClockMap &clocks = _g.getClocks();
		auto it2 = clocks.find(p.first);
		if (it2 != clocks.cend())
			elem = it->second;
	}
	if (elem != nullptr)
		elem->setState(p.second);
}

void	ArgumentsParser::setValues(const int ac, const char **av)
{
	for (int i = 0; i < ac; i++)
		setVal(av[i]);
}
