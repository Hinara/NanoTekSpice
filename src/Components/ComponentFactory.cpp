/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Componentfactory
*/

#include "Comp2716.hpp"
#include "Comp4001.hpp"
#include "Comp4008.hpp"
#include "Comp4011.hpp"
#include "Comp4013.hpp"
#include "Comp4017.hpp"
#include "Comp4030.hpp"
#include "Comp4040.hpp"
#include "Comp4069.hpp"
#include "Comp4071.hpp"
#include "Comp4081.hpp"
#include "Comp4094.hpp"
#include "Comp4514.hpp"
#include "Comp4801.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "Clock.hpp"
#include "True.hpp"
#include "False.hpp"
#include "ComponentFactory.hpp"

nts::ComponentFactory::ComponentFactory()
{
}

nts::ComponentFactory::~ComponentFactory()
{
}

const nts::ComponentFactory::CompMap	nts::ComponentFactory::_map = {
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

nts::ComponentFactory::CompPtr	nts::ComponentFactory::createComponent(
	const std::string &type, const std::string &value)
{
	return (_map.at(type))(value);
}