/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** graph
*/

#include "Errors.hpp"
#include "Components/SuperComponent.hpp"
#include "Components/ComponentFactory.hpp"
#include "Graph.hpp"

Graph::Graph()
{
}

Graph::~Graph()
{
}

void	Graph::fillGraph(chipset_s chipset)
{
	nts::ComponentFactory	factory;
	_graph[chipset._name] = factory.createComponent(chipset._comp, chipset._name);
	if (chipset._comp == "output")
		_output[chipset._name] = static_cast<Output *>(_graph[chipset._name].get());
	else if (chipset._comp == "clock")
		_clock.push_back(make_pair(
			chipset._name,
			static_cast<Clock *>(_graph[chipset._name].get())
		));
	else if (chipset._comp == "input")
		_input[chipset._name] = static_cast<Input *>(_graph[chipset._name].get());
}

void	Graph::setLink(link_s link)
{
	if (_graph.find(link._nameO) == _graph.cend() ||
		_graph.find(link._nameT) == _graph.cend())
		throw Err::LexicalError("This component doesn't exist.");
	SuperComponent *compO = 
		(static_cast<SuperComponent *>(_graph.at(link._nameO).get()));
	SuperComponent *compT =
		(static_cast<SuperComponent *>(_graph.at(link._nameT).get()));

	if (compT->isInput(link._pinT) && compO->isOutput(link._pinO))
		_graph[link._nameT]->setLink(link._pinT, *compO, link._pinO);
	if (compO->isInput(link._pinO) && compT->isOutput(link._pinT))
		_graph[link._nameO]->setLink(link._pinO, *compT, link._pinT);
	if ((!compT->isInput(link._pinT) && !compO->isInput(link._pinO)) ||
		(!compT->isOutput(link._pinT) && !compO->isOutput(link._pinO)))
		throw Err::LinkError("Can't link pin of the same type.");
}