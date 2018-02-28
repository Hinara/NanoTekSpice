/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Kernel
*/

#include "Kernel.hpp"

int	Kernel::run(const int ac, const char **av)
{
	try {
		Graph	graph;
		Cli	comLine(graph);
		Parser	parse(av[1]);

		parse.parseFile(graph);
		if (ac > 2) {
			ArgumentsParser argParse(graph);
			argParse.setValues(ac - 2, &(av[2]));
		}
		Kernel::verifValueInputsComp(graph);
		comLine.start();
	} catch (Err::Errors ex) {
		std::cerr << ex.what() <<std::endl;
		return 84;
	} catch (std::exception ex) {
		return 84;
	}
	return 0;
}

void	Kernel::verifValueInputsComp(Graph &g)
{
	for (auto it : g.getInputs()) {
		if (it.second->compute() == nts::UNDEFINED)
			throw Err::ArgumentError("\'" + it.first +
				"\': input not set.");
	}
	for (auto it : g.getClocks()) {
		if (it.second->compute() == nts::UNDEFINED)
			throw Err::ArgumentError("\'" + it.first +
				"\': clock not set.");
	}
	for (auto it : g.getOutputs()) {
		if (!(it.second->isInputLinked(1)))
			throw Err::LinkError("\'" + it.first +
				"\': output not linked.");
	}
}