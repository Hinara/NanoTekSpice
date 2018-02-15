/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** main
*/

#include <iostream>
#include <exception>
#include <algorithm>
#include "Nano.hpp"
#include "Parser.hpp"
#include "ArgumentsParser.hpp"
#include "Cli.hpp"

int	main(int ac, char **av)
{
	if (ac < 2)
		return 84;
	try {
		Graph	g;
//		Cli	c(g);
		Parser	p(av[1]);

		p.parseFile(g);
		if (ac > 2) {
			ArgumentsParser ap(&(av[2]));

			ap.setValues(g);
		}
		std::for_each(g.getInput().begin(), g.getInput().end(), [](auto it){ 
			if (it.second->compute() == nts::UNDEFINED)
				throw Err::ArgumentError("\'" + it.first + "\': input not set.");
		});
		std::for_each(g.getClock().begin(), g.getClock().end(), [&g](std::string var){
			if (static_cast<Clock *>(g.getGraph().at(var).get())->compute() == nts::UNDEFINED)
				throw Err::ArgumentError("\'" + var + "\': input not set.");
		});
		std::for_each(g.getOutput().begin(), g.getOutput().end(), [](auto it){
			if (!(it.second->inputIsLink(1)))
				throw Err::LinkError("\'" + it.first + "\': is not linked.");
		});
//		c.start();
	} catch (std::exception ex) {
		return 84;
	}
	return 0;
}
