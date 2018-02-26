/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** kernel
*/

#ifndef KERNEL_HPP_
	# define KERNEL_HPP_
	# include <iostream>
	# include <exception>
	# include <algorithm>
	# include "Nano.hpp"
	# include "Parser.hpp"
	# include "ArgumentsParser.hpp"
	# include "Cli.hpp"

class Kernel {
	public:
		static int	run(const int, const char **);
	private:
		static void		verifValueInputsComp(Graph &);
};

#endif /* !KERNEL_HPP_ */
