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
	Parser a(av[1]);
	a.parseFile();
	} catch (std::exception ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}