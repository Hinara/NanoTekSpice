/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
** Command Line Interface Header
*/

#include <csignal>
#include <iostream>
#include <string>
#include <algorithm>
#include <memory>
#include "Graph.hpp"
#include "Components/Input.hpp"
#include "Components/Clock.hpp"
#include "Components/Output.hpp"
#include "Components/IComponent.hpp"
#include "Components/True.hpp"
#include "Cli.hpp"

static bool	g_loop;

Cli::Cli(Graph &g)
	: _g(g)
{
}

Cli::~Cli()
{
}

void	Cli::display()
{
	const Graph::OutputMap &outputs = _g.getOutputs();

	for (const auto it : outputs) {
		nts::Tristate state = it.second->getValue();
		std::string str = "U";
		if (state == nts::TRUE) {
			str = "1";
		} else if (state == nts::FALSE) {
			str = "0";
		}
		std::cout << it.first << "=" << str << std::endl;
	}
}

void	Cli::dump()
{
	const Graph::CompMap	&components = _g.getGraph();
	for (const auto &pair: components)
		pair.second->dump();
}

void	Cli::input(const std::string &s, nts::Tristate state)
{
	try {
		this->_g.getInputs().at(s)->setState(state);
	} catch (std::exception e) {
		std::cout << s << " is not an input" << std::endl;
	}
}

void	Cli::simulate()
{
	const Graph::OutputMap &outputs = _g.getOutputs();
	for (auto it : outputs)
		it.second->simulate();
	const Graph::ClockMap &clocks = _g.getClocks();
	for (auto it : clocks)
		it.second->swapState();
}

void	Cli::loop()
{
	g_loop = true;
	auto oldHandler = std::signal(SIGINT, [](int){ g_loop = false; });
	while (!g_loop)
		this->simulate();
	std::signal(SIGINT, oldHandler);
}

void	Cli::simulateAndDisplay()
{
	this->simulate();
	this->display();
}

void	Cli::executeCommand(const std::string &s)
{
	const static std::map<const std::string, void (Cli::*)()> m = {
		{ "simulate", &Cli::simulate },
		{ "loop", &Cli::loop },
		{ "display", &Cli::display },
		{ "dump", &Cli::dump },
		{ "sd", &Cli::simulateAndDisplay }
	};
	try {
		(this->*m.at(s))();
	} catch (std::out_of_range e) {
		if (s.find("=1") == s.length() - 2 && s.length() >= 2) {
			this->input(s.substr(0, s.length() - 2), nts::TRUE);
		} else if (s.find("=0") == s.length() - 2 && s.length() >= 2) {
			this->input(s.substr(0, s.length() - 2), nts::FALSE);
		} else {
			std::cout << "Command not found\n";
		}
	}
}

void	Cli::start()
{
	std::string	line;

	simulate();
	display();
	while (!std::cin.eof() && line != "exit") {
		std::cout << "> ";
		std::getline(std::cin, line);
		if (line != "" && line != "exit")
			executeCommand(line);
	}
}
