/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** main
*/

#include <iostream>
#include <exception>
#include "Parser.hpp"

int	main(int ac, char **av)
{
	if (ac == 0)
		return 84;
	try {
		Parser	p(av[1]);
		p.parseFile();
	} catch (std::exception ex) {
		std::cerr << ex.what() << std::endl;
		return 84;
	}
	return 0;
}
