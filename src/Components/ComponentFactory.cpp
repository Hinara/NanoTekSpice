/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Componentfactory
*/

#include "ComponentFactory.hpp"

nts::ComponentFactory::ComponentFactory()
{
}

nts::ComponentFactory::~ComponentFactory()
{
}

std::unique_ptr<nts::IComponent>	nts::ComponentFactory::createComponent(const std::string &type, const std::string &value)
{
	return ((_map.at(type))(value));
}
