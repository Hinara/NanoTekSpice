/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Graph
*/

#include <utility>
#include "ComponentFactory.hpp"
#include "Graph.hpp"

Graph::Graph()
{
}

Graph::~Graph()
{
	_graphControler.clear();
}

void	Graph::createGraph(const std::deque<chipset_s> _chipset, const std::deque<link_s> _link)
{
	fillGraphControler(_chipset);
	linkGraph(_link);
}

void	Graph::linkGraph(const std::deque<link_s> _link)
{

}

void	Graph::fillGraphControler(const std::deque<chipset_s> _chipset)
{
	nts::ComponentFactory	_factory;

	for (auto it = _chipset.cbegin(); it != _chipset.cend(); it++)
		_graphControler.insert(_graphControler.cbegin(), std::make_pair(it->_name,
		 _factory.createComponent(it->_comp, it->_name).get()));
}