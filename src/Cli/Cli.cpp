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
#include "../Graph.hpp"
#include "Cli.hpp"

bool *stop;

Cli::Cli(const Graph &g)
	: _g(g)
{
}

Cli::~Cli()
{
}

void	Cli::display()
{
	auto components = _g.getGraph();
	std::for_each(components.begin(), components.end(),
		     [](const std::pair<std::string, nts::IComponent *> pair)
		     { pair.second->dump(); }
		);
}

void	Cli::input(const std::string &s)
{
	std::cout << s;
}

void	Cli::simulate()
{
}

void	Cli::loop()
{
	bool	exit = false;
	stop = &exit;
	auto oldHandler = std::signal(SIGINT,
				      []([[gnu::unused]] int s){ *stop = true; });
	while (!exit)
		this->simulate();
	std::signal(SIGINT, oldHandler);
}

void	Cli::executeCommand(const std::string &s)
{
        const static std::map<std::string, void (Cli::*)()> m = {
		{ "simulate", &Cli::simulate },
		{ "loop", &Cli::loop },
		{ "display", &Cli::display }
	};
	try {
		(this->*m.at(s))();
	} catch (std::exception e) {
		//TO MODIFIY
		if (s.find("input=") == 0) {
			this->input(s);
		} else {
			std::cout << "Command not found\n";
		}
	}
}

void	Cli::start()
{
	bool		exit = false;
	std::string	line;
	while (!exit) {
		std::cout << ">";
		std::getline(std::cin, line);
		if (line == "" && std::cin.eof())
			std::cout << "\n";
	        exit = (line == "" && std::cin.eof()) || line == "exit";
		if (!exit)
			executeCommand(line);
	}
}
