/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Graph
*/

#ifndef GRAPH_HPP_
	#define GRAPH_HPP_

#include <map>
#include <deque>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>
#include "Nano.hpp"
#include "IComponent.hpp"

class Graph {
	public:
		Graph();
		~Graph();
		void	createGraph(const std::deque<chipset_s>, const std::deque<link_s>);
		std::map<const std::string, nts::IComponent *>	getGraph() const { return _graphControler; }
	private:
		std::map<const std::string, nts::IComponent *>	_graphControler;
		std::vector<std::string>	_priority = { "input", "clock", "true", "false" };
	private:
		void	fillGraphControler(const std::deque<chipset_s>) noexcept;
		void	linkGraph(const std::deque<link_s>, const std::deque<chipset_s>);
};

#endif /* !GRAPH_HPP_ */
