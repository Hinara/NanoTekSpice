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
#include <algorithm>
#include "Nano.hpp"
#include "Components/Output.hpp"
#include "Components/Input.hpp"
#include "Components/Clock.hpp"
#include "Components/IComponent.hpp"

class Graph {
	public:
		using CompMap =
			std::map<std::string, std::unique_ptr<nts::IComponent>>;
		using OutputMap = std::map<std::string, Output *>;
		using InputMap = std::unordered_map<std::string, Input *>;
		using ClockMap = std::unordered_map<std::string, Clock *>;
		Graph();
		~Graph();
		void	fillGraph(chipset_s);
		void	setLink(link_s);
		nts::IComponent	*getComp(const std::string &name)
			{ return _graph.at(name).get(); }
		Output		*getOutputComp(const std::string &name)
			{ return _output.at(name); }
		Input		*getInputComp(const std::string &name)
			{ return _input.at(name); }
		CompMap		&getGraph() { return _graph; }
		OutputMap	&getOutput() { return _output; }
		InputMap	&getInput() { return _input; }
		ClockMap	&getClock() { return _clock; }
	private:
		CompMap		_graph;
		OutputMap	_output;
		InputMap	_input;
		ClockMap	_clock;
};

#endif /* !GRAPH_HPP_ */
