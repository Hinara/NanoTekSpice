/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** parser
*/

#include <sstream>
#include <iostream>
#include "Components/SuperComponent.hpp"
#include "Errors.hpp"
#include "Parser.hpp"

Parser::Parser(const std::string &filename)
: _filename(filename)
{
	std::ifstream	myFile(_filename, std::ifstream::in);

	if (!myFile) {
		myFile.close();
		throw std::exception();
	}
	myFile.close();
}

Parser::~Parser()
{
}

bool	Parser::epurLine(std ::string &line)
{
	if (line.find('#') != line.npos)
		line.erase(line.find('#'));
	if (line == "")
		return false;
	return true;
}

bool	Parser::isKeyWord(const std::string line, parseState &s)
{
	if (line == ".chipsets:") {
		if (s == CHIPSET)
			throw Err::DuplicatedSectionHeader("Duplicated \'.chipset:\' header");
		s = CHIPSET;
		return (true);
	} else if (line == ".links:") {
		if (s == LINK)
			throw Err::DuplicatedSectionHeader("Duplicated \'.links:\' header");
		s = LINK;
		return (true);
	}
	return (false);
}

void	Parser::putInGraph(chipset_s chipset, graph_s &data)
{
	nts::ComponentFactory	factory;
	data._graph[chipset._name] = factory.createComponent(chipset._comp, chipset._name);
	if (chipset._comp == "output")
		data._output.push_back(chipset._name);
	else if (chipset._comp == "clock")
		data._clock.push_back(chipset._name);
	else if (chipset._comp == "input")
		data._input.push_back(chipset._name);
}

void	Parser::verifChipset(const std::string line, graph_s &dat)
{
	std::istringstream	data(line);
	nts::ComponentFactory	factory;
	std::string		err;
	chipset_s		elem;

	if (!(data >> elem._comp) || !(data >> elem._name) || data >> err)
		throw Err::LexicalError("Chipset's problem when parsing the file.");
	else if (find(_comp.cbegin(), _comp.cend(), elem._comp) == _comp.cend())
		throw Err::UnknowType("This component doesn't exist.");
	else {
		if (dat._graph.find(elem._name) != dat._graph.cend())
			throw Err::LexicalError("\'" + elem._name + "\' is already used.");
	}
	putInGraph(elem, dat);
}

void	Parser::LinkGraph(link_s link, graph_s &data)
{
	if (data._graph.find(link._nameO) == data._graph.cend() || data._graph.find(link._nameT) == data._graph.cend())
		throw Err::LexicalError("This component doesn't exist.");
	bool a = (static_cast<SuperComponent *>(data._graph.at(link._nameO).get()))->isInput(link._pinO);
	bool b = (static_cast<SuperComponent *>(data._graph.at(link._nameT).get()))->isInput(link._pinT);

	if (a && !b)
		data._graph[link._nameT]->setLink(link._pinT, *(data._graph[link._nameO]), link._pinO);
	else if (b && !a)
		data._graph[link._nameO]->setLink(link._pinO, *(data._graph[link._nameT]), link._pinT);
	else
		throw Err::LinkError("Can't link pin of the same type.");
}

void	Parser::verifLink(std::string line, graph_s &dat)
{
	std::istringstream	data(line);
	std::string		err;
	link_s			elem;

	if (!(data >> elem._nameO) || !(data >> elem._nameT) || data >> err)
		throw Err::LexicalError("Too much link on the line.");
	std::replace(line.begin(), line.end(), ':', ' ');
	std::istringstream	parse(line);
	if (!(parse >> elem._nameO) || !(parse >> elem._pinO)
	|| !(parse >> elem._nameT) || !(parse >> elem._pinT) || parse >> err
	|| elem._pinO <= 0 || elem._pinT <= 0)
		throw Err::LexicalError("Bad arguments when parsing.");
	LinkGraph(elem, dat);
}

void	Parser::parseLine(std::string line, parseState &state, graph_s &data)
{
	if (state == CHIPSET) {
		if (line.find(':') != line.npos)
			throw Err::LexicalError("\':\' is a separator and can't be use in chipset.");
		verifChipset(line, data);
	} else if (state == LINK) {
		verifLink(line, data);
	} else
		throw Err::LexicalError("Error: line not in the format:" + line);
}

void	Parser::parseFile(graph_s &data)
{
	std::ifstream	myFile(_filename, std::ifstream::in);
	std::string	line;
	parseState	state = NONE;
	int		lineNum = 0;

	try {
		while (getline(myFile, line)) {
			lineNum += 1;
			std::cout << line << std::endl;
			if (epurLine(line) && isKeyWord(line, state) == false)
				parseLine(line, state, data);
		}
		myFile.close();
	} catch (Err::Errors ex) {
		std::cerr << "Line " << lineNum << ": " << ex.what() << std::endl;
		throw std::exception();
	}
}