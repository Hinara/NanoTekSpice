/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** main
*/

#include <iostream>
#include <exception>
#include "Parser.hpp"
#include "Cli/Cli.hpp"

int	main(int ac, char **av)
{
	if (ac == 0)
		return 84;
	try {
		Parser	p(av[1]);
		p.parseFile();
		//Cli	c(g);
		//c.start();
	} catch (std::exception ex) {
		return 84;
	}
	return 0;
}
