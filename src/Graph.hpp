/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Graph
*/

#ifndef GRAPH_HPP_
	#define GRAPH_HPP_

#include <map>
#include <string>
#include <memory>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include "Nano.hpp"
#include "Components/Output.hpp"
#include "Components/Input.hpp"
#include "Components/IComponent.hpp"

class Graph {
	public:
		Graph();
		~Graph();
		void	fillGraph(chipset_s);
		void	setLink(link_s);
		nts::IComponent							*getComp(const std::string &name) { return _graph.at(name).get(); }
		Output								*getOutputComp(const std::string &name) { return _output.at(name); }
		Input								*getInputComp(const std::string &name) { return _input.at(name); }
		std::map<std::string, std::unique_ptr<nts::IComponent>>		&getGraph() { return _graph; }
		std::map<std::string, Output *>					&getOutput() { return _output; }
		std::unordered_map<std::string, Input *>			&getInput() { return _input; }
		std::vector<nts::IComponent *>					&getClock() { return _clock; }
	private:
		std::map<std::string, std::unique_ptr<nts::IComponent>>	_graph;
		std::map<std::string, Output *>				_output;
		std::unordered_map<std::string, Input *>		_input;
		std::vector<nts::IComponent *>				_clock;
};

#endif /* !GRAPH_HPP_ */
