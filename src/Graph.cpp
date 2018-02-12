/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Graph
*/

#include <iostream>
#include <utility>
#include "Errors.hpp"
#include "Components/Output.hpp"
#include "Components/ComponentFactory.hpp"
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
	throw Err::UnknowType("This " + _name + " name doesn't exist");
	return "";
}

void	linkOuput(nts::IComponent *first, nts::IComponent *second, std::size_t f_pin, std::size_t s_pin)
{
	first->setLink(f_pin, *second, s_pin);
}

void	Graph::linkGraph(const std::deque<link_s> _link, const std::deque<chipset_s> _chipset)
{
	for (link_s th : _link) {
		const std::string	compO = getChipsetType(th._nameO, _chipset);
		const std::string	compT = getChipsetType(th._nameT, _chipset);

		if ((std::find(_priority.cbegin(), _priority.cend(), compO) != _priority.cend() 
		&& std::find(_priority.cbegin(), _priority.cend(), compT) == _priority.cend()) ||
		 (compO == "output" && compT != "output"))
			linkOuput(_graphControler[th._nameO], _graphControler[th._nameT], th._pinO, th._pinT);
		else if ((std::find(_priority.cbegin(), _priority.cend(), compO) == _priority.cend() 
		&& std::find(_priority.cbegin(), _priority.cend(), compT) != _priority.cend()) ||
		 (compT == "output" && compO != "output"))
			linkOuput(_graphControler[th._nameT], _graphControler[th._nameO], th._pinT, th._pinO);
		else
			throw Err::LinkError("Error at the creation of the graph.");
	}
}

void	Graph::fillGraphControler(const std::deque<chipset_s> _chipset) noexcept
{
	nts::ComponentFactory	_factory;

	for (auto it = _chipset.cbegin(); it != _chipset.cend(); it++)
		_graphControler.insert(_graphControler.cbegin(), std::make_pair(it->_name,
		 _factory.createComponent(it->_comp, it->_name).get()));
}