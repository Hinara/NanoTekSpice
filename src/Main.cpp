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
	if (ac < 2)
		return 84;
	try {
		Graph	g;
//		Cli	c(g);
		Parser	p(av[1]);

		p.parseFile(g);
//		c.start();
	} catch (std::exception ex) {
		std::cerr << ex.what() << std::endl;
		return 84;
	}
	return 0;
}
