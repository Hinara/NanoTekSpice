/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** graph
*/

#include "Components/SuperComponent.hpp"
#include "Components/ComponentFactory.hpp"
#include "Graph.hpp"

Graph::Graph()
{
}

Graph::~Graph()
{
}

void			Graph::fillGraph(chipset_s chipset)
{
	nts::ComponentFactory	factory;
	_graph[chipset._name] = factory.createComponent(chipset._comp, chipset._name);
	if (chipset._comp == "output")
		_output[chipset._name] = static_cast<Output *>(_graph[chipset._name].get());
	else if (chipset._comp == "clock")
		_clock.push_back(chipset._name);
	else if (chipset._comp == "input")
		_input[chipset._name] = static_cast<Input *>(_graph[chipset._name].get());
}

void			Graph::setLink(link_s link)
{
	if (_graph.find(link._nameO) == _graph.cend() || _graph.find(link._nameT) == _graph.cend())
		throw Err::LexicalError("This component doesn't exist.");
	bool a = (static_cast<SuperComponent *>(_graph.at(link._nameO).get()))->isInput(link._pinO);
	bool b = (static_cast<SuperComponent *>(_graph.at(link._nameT).get()))->isInput(link._pinT);

	if (a && !b)
		_graph[link._nameT]->setLink(link._pinT, *(_graph[link._nameO]), link._pinO);
	else if (b && !a)
		_graph[link._nameO]->setLink(link._pinO, *(_graph[link._nameT]), link._pinT);
	else
		throw Err::LinkError("Can't link pin of the same type.");
}