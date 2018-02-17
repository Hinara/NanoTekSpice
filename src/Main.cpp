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

int	main(const int ac, const char **av)
{
	if (ac < 2)
		return 84;
	try {
		Graph	g;
		Cli	c(g);
		Parser	p(av[1]);

		p.parseFile(g);
		if (ac > 2) {
			ArgumentsParser ap(g);

			ap.setValues(ac - 2, &(av[2]));
		}/*
		std::for_each(g.getInput().begin(), g.getInputs().end(), [](auto it){ 
			if (it.second->compute() == nts::UNDEFINED)
				throw Err::ArgumentError("\'" + it.first + "\': input not set.");
		});
		std::for_each(g.getClock().begin(), g.getClocks().end(), [&g](std::string var){
			if (static_cast<Clock *>(g.getGraph().at(var).get())->compute() == nts::UNDEFINED)
				throw Err::ArgumentError("\'" + var + "\': input not set.");
		});*/
		std::for_each(g.getOutputs().begin(), g.getOutputs().end(), [](auto it){
			if (!(it.second->isInputLinked(1)))
				throw Err::LinkError("\'" + it.first + "\': is not linked.");
		});
		c.start();
	}catch (Err::Errors ex) {
		std::cerr << ex.what() <<std::endl;
		return 84;
	} catch (std::exception ex) {
		return 84;
	}
	return 0;
}
