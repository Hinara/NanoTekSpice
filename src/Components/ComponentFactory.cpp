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
	{ "4001", create_elem<Comp4001> },
	{ "4008", create_elem<Comp4008> },
	{ "4011", create_elem<Comp4011> },
	{ "4013", create_elem<Comp4013> },
	{ "4017", create_elem<Comp4017> },
	{ "4030", create_elem<Comp4030> },
	{ "4040", create_elem<Comp4040> },
	{ "4069", create_elem<Comp4069> },
	{ "4071", create_elem<Comp4071> },
	{ "4081", create_elem<Comp4081> },
	{ "4094", create_elem<Comp4094> },
	{ "4514", create_elem<Comp4514> },
	{ "4801", create_elem<Comp4801> },
	{ "2716", create_elem<Comp2716> },
	{ "input", create_elem<Input> },
	{ "output", create_elem<Output> },
	{ "clock", create_elem<Clock> },
	{ "true", create_elem<True> },
	{ "false", create_elem<False> }
};

std::unique_ptr<nts::IComponent>	nts::ComponentFactory::createComponent(const std::string &type, const std::string &value)
{
	return ((_map.at(type))(value));
}
