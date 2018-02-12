/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** main
*/

#include <iostream>
#include <exception>
#include "Graph.hpp"
#include "Parser.hpp"
#include "Cli/Cli.hpp"

int	main(int ac, char **av)
{
	if (ac == 0)
		return 84;
	try {
		Parser	p(av[1]);
		Graph	g;
		p.parseFile();
		g.createGraph(p.getChipsets(), p.getLinks());
		Cli	c(g);
		c.start();
	} catch (std::exception ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}
