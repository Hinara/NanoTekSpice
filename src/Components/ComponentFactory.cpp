/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Componentfactory
*/

#include <iostream>
#include "ComponentFactory.hpp"

nts::ComponentFactory::ComponentFactory()
{
}

nts::ComponentFactory::~ComponentFactory()
{
}

const std::map<const std::string, FnctPtr>	nts::ComponentFactory::_map = {
	{ "4001", createElem<Comp4001> },
	{ "4008", createElem<Comp4008> },
	{ "4011", createElem<Comp4011> },
	{ "4013", createElem<Comp4013> },
	{ "4017", createElem<Comp4017> },
	{ "4030", createElem<Comp4030> },
	{ "4040", createElem<Comp4040> },
	{ "4069", createElem<Comp4069> },
	{ "4071", createElem<Comp4071> },
	{ "4081", createElem<Comp4081> },
	{ "4094", createElem<Comp4094> },
	{ "4514", createElem<Comp4514> },
	{ "4801", createElem<Comp4801> },
	{ "2716", createElem<Comp2716> },
	{ "input", createElem<Input> },
	{ "output", createElem<Output> },
	{ "clock", createElem<Clock> },
	{ "true", createElem<True> },
	{ "false", createElem<False> }
};
