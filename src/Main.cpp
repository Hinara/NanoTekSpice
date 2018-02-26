/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** main
*/

#include "Kernel.hpp"

int	main(const int ac, const char **av)
{
	if (ac < 2)
		return 84;
	return Kernel::run(ac, av);
}
