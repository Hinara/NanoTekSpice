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
#include "Components/Input.hpp"
#include "Components/Clock.hpp"
#include "Components/Output.hpp"
#include "Components/IComponent.hpp"
#include "Cli.hpp"

static bool	*stop;

Cli::Cli(graph_s &g)
	: _g(g)
{
}

Cli::~Cli()
{
}

void	Cli::display()
{
	std::for_each(_g._output.begin(), _g._output.end(),
		[this](const std::string &s)
		{
			nts::Tristate state = static_cast<Output *>(_g._graph.at(s).get())->getValue();
			std::string str;
			if (state == nts::TRUE) {
				str = "true";
			} else if (state == nts::FALSE) {
				str = "false";
			} else {
				str = "undefined";
			}
			std::cout << s << ":" << str << std::endl;
		}
	);
}

void	Cli::dump()
{
	const std::map<const std::string, std::unique_ptr<nts::IComponent> >	&components = _g._graph;
	std::for_each(components.begin(), components.end(),
			[](const std::pair<const std::string, std::unique_ptr<nts::IComponent> > &pair)
			{ pair.second->dump(); }
		);
	(void) components;
}

void	Cli::input(const std::string &s, nts::Tristate state)
{
	if (std::find(_g._input.cbegin(),
		_g._input.cend(), s) == _g._input.cend()) {
		std::cout << s << " is not an input" << std::endl;
	} else {
		static_cast<Input *>(_g._graph.at(s).get())->setState(state);
	}
}

void	Cli::simulate()
{
	std::for_each(_g._output.begin(), _g._output.end(),
		[this](const std::string &s)
		{ static_cast<Output *>(_g._graph.at(s).get())->simulate(); }
	);
	std::for_each(_g._input.begin(), _g._input.end(),
		[this](const std::string &s)
		{ static_cast<Clock *>(_g._graph.at(s).get())->swapState(); }
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
