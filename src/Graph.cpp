/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Graph
*/

#include <iostream>
#include <utility>
#include "Output.hpp"
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
	linkGraph(_link, _chipset);
}

const std::string	getChipsetType(const std::string _name, const std::deque<chipset_s> _chipset)
{
	for (chipset_s it : _chipset) {
		if (_name == it._name)
			return it._comp;
	}
	return "";
}

void	linkOuput(const std::string compO, const std::string compT, const link_s _link)
{
	if (compO == "output" || compT == "output") {

	}
}

void	Graph::linkGraph(const std::deque<link_s> _link, const std::deque<chipset_s> _chipset)
{
	for (link_s th : _link) {
		const std::string	compO = getChipsetType(th._nameO, _chipset);
		const std::string	compT = getChipsetType(th._nameT, _chipset);
		linkOuput(compO, compT, th);
	}
}

void	Graph::fillGraphControler(const std::deque<chipset_s> _chipset)
{
	nts::ComponentFactory	_factory;

	for (auto it = _chipset.cbegin(); it != _chipset.cend(); it++)
		_graphControler.insert(_graphControler.cbegin(), std::make_pair(it->_name,
		 _factory.createComponent(it->_comp, it->_name).get()));
}