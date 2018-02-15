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
#include "Cli.hpp"

int	main(int ac, char **av)
{
	if (ac == 0)
		return 84;
	try {
		graph_s	g;
		Cli	c(g);
		Parser	p(av[1]);

		p.parseFile(g);
		std::sort(g._output.begin(), g._output.end());
		c.start();
	} catch (std::exception ex) {
		std::cerr << ex.what() << std::endl;
		return 84;
	}
	return 0;
}
