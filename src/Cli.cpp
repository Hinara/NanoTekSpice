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
#include "Cli.hpp"

static bool	*stop;

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
	std::for_each(outputs.cbegin(), outputs.cend(),
		[this](const Graph::OutputPair &p)
		{
			nts::Tristate state = p.second->getValue();
			std::string str = "U";
			if (state == nts::TRUE) {
				str = "1";
			} else if (state == nts::FALSE) {
				str = "0";
			}
			std::cout << p.first << ":" << str << std::endl;
		}
	);
}

void	Cli::dump()
{
	const Graph::CompMap	&components = _g.getGraph();
	std::for_each(components.begin(), components.end(),
			[](const std::pair<const std::string, std::unique_ptr<nts::IComponent> > &pair)
			{ pair.second->dump(); }
		);
	(void) components;
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
	std::for_each(outputs.cbegin(), outputs.cend(),
		[this](const Graph::OutputPair &p)
		{ p.second->simulate(); }
	);
	const Graph::ClockMap &clocks = _g.getClocks();
	std::for_each(clocks.cbegin(), clocks.cend(),
		[this](const Graph::ClockPair &p)
		{ p.second->swapState(); }
	);
}

void	Cli::loop()
{
	bool	exit = false;
	stop = &exit;
	auto oldHandler = std::signal(SIGINT, [](int){ *stop = true; });
	while (!exit)
		this->simulate();
	std::signal(SIGINT, oldHandler);
}

void	Cli::executeCommand(const std::string &s)
{
	const static std::map<const std::string, void (Cli::*)()> m = {
		{ "simulate", &Cli::simulate },
		{ "loop", &Cli::loop },
		{ "display", &Cli::display },
		{ "dump", &Cli::dump },
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
		std::cout << ">";
		std::getline(std::cin, line);
		if (std::cin.eof())
			std::cout << "\n";
		if (line != "" && line != "exit")
			executeCommand(line);
	}
}
