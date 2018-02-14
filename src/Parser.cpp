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

bool	Parser::isKeyWord(const std::string line, bool &chipset, bool &link)
{
	if (line == ".chipsets:") {
		if (chipset)
			throw Err::DuplicatedSectionHeader("Duplicated \'.chipset:\' header");
		chipset = true;
		return (true);
	} else if (line == ".links:") {
		if (link)
			throw Err::DuplicatedSectionHeader("Duplicated \'.links:\' header");
		link = true;
		return (true);
	}
	return (false);
}

void	Parser::putInGraph(chipset_s chipset)
{
	nts::ComponentFactory	factory;
	_graph[chipset._name] = factory.createComponent(chipset._comp, chipset._name);
	if (chipset._comp == "output")
		_output.push_back(chipset._name);
	else if (chipset._comp == "clock")
		_clock.push_back(chipset._name);
	else if (chipset._comp == "input")
		_input.push_back(chipset._name);
}

void	Parser::verifChipset(const std::string line)
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
		if (_graph.find(elem._name) != _graph.cend())
			throw Err::LexicalError("\'" + elem._name + "\' is already used.");
	}
	putInGraph(elem);
}

void	Parser::LinkGraph(link_s link)
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
		throw Err::LinkError("Can't link an input pin to an another input pin.");
}

void	Parser::verifLink(std::string line)
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
	LinkGraph(elem);
}

void	Parser::parseLine(std::string line, bool &chipsets, bool &links)
{
	if (chipsets && !links) {
		std::replace(line.begin(), line.end(), ':', ' ');
		verifChipset(line);
	} else if (chipsets && links) {
		verifLink(line);
	} else
		throw Err::LexicalError("Error: line not in the format:" + line);
}

void	Parser::parseFile()
{
	std::ifstream	myFile(_filename, std::ifstream::in);
	std::map<const std::string, std::map<const std::string, const std::string>>	_data;
	std::string	line;
	bool	chipsets = 0;
	bool	links = 0;
	int		lineNum = 0;

	try {
		while (getline(myFile, line)) {
			lineNum += 1;
			std::cout << line << std::endl;
			if (epurLine(line) && isKeyWord(line, chipsets, links) == false)
				parseLine(line, chipsets, links);
		}
		myFile.close();
	} catch (Err::Errors ex) {
		std::cerr << "Line " << lineNum << ": " << ex.what() << std::endl;
		throw std::exception();
	}
}