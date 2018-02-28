/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** main
*/

#include <stdio.h>
#include "Kernel.hpp"

int	main(const int ac, const char **av)
{
	if (ac < 2) {
		std::cerr << "Bad number of arguments" << std::endl
			<< "Usage: " << av[0] << " file.nts [input=1|0 ...]"
			<< std::endl;
		return 84;
	}
	return Kernel::run(ac, av);
}
