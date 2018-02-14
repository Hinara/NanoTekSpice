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
/*
std::map<const std::string, std::unique_ptr<nts::IComponent>>	&Parser::getGraph()
{
	return _graph;
}

std::map<const std::string, std::unique_ptr<nts::IComponent>>	&Parser::getOut()
{
	return _output;
}

std::map<const std::string, std::unique_ptr<nts::IComponent>>	&Parser::getSpec()
{
	return _spec;
}

std::map<const std::string, std::unique_ptr<nts::IComponent>>	&Parser::getComp()
{
	return _component;
}
*/
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
			throw Err::DuplicatedSectionHeader("Duplicated .chipset header");
		chipset = true;
		return (true);
	} else if (line == ".links:") {
		if (link)
			throw Err::DuplicatedSectionHeader("Duplicated .links header");
		link = true;
		return (true);
	}
	return (false);
}

void	Parser::putInControler(chipset_s chipset)
{
	const std::vector<std::string>	&priority = { "input", "clock", "true", "false" };
	nts::ComponentFactory	factory;

	if (chipset._comp == "output")
		_output[chipset._name] = factory.createComponent(chipset._comp, chipset._name);
	else if (find(priority.cbegin(), priority.cend(), chipset._comp) == priority.cend())
		_component[chipset._name] = factory.createComponent(chipset._comp, chipset._name);
	else if (chipset._comp == "clock" || chipset._comp == "input")
		_spec[chipset._name] = factory.createComponent(chipset._comp, chipset._name);
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
	putInControler(elem);
	_graph[elem._name] = factory.createComponent(elem._comp, elem._name);
}

void	Parser::LinkGraph(link_s link)
{
	if (_graph.find(link._nameO) == _graph.cend() || _graph.find(link._nameT) == _graph.cend())
		throw Err::LexicalError("This component doesn't exist.");
	//if (_component.find(link._nameO) != _component.cend() && _component.find(link._nameT) != _component.cend()) {
		const std::unordered_map<std::size_t, std::pair<nts::IComponent *, std::size_t>> a = (static_cast<SuperComponent *>(_component[link._nameO].get()))->getInput();
		const std::unordered_map<std::size_t, std::pair<nts::IComponent *, std::size_t>> b = (static_cast<SuperComponent *>(_component[link._nameT].get()))->getInput();

		if (a.find(link._pinO) != a.cend() && b.find(link._pinT) == b.cend())
			_graph[link._nameT]->setLink(link._pinT, *(_graph[link._nameO]), link._pinO);
		else if (b.find(link._pinT) != b.cend() && a.find(link._pinO) == a.cend())
			_graph[link._nameO]->setLink(link._pinO, *(_graph[link._nameT]), link._pinT);
		else
			throw Err::LinkError("Can't link an input pin to an another input pin.");
	//}
	/*if ((_output.find(link._nameO) != _output.cend() || _component.find(link._nameO) != _component.cend()) 
	&& _output.find(link._nameT) == _output.cend())
		_graph[link._nameO]->setLink(link._pinO, *(_graph[link._nameT]), link._pinT);
	else if ((_output.find(link._nameT) != _output.cend() || _component.find(link._nameT) != _component.cend()) 
	&& _output.find(link._nameO) == _output.cend())
		_graph[link._nameT]->setLink(link._pinT, *(_graph[link._nameO]), link._pinO);
	else
		throw Err::LinkError("Impossible link.");*/
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
			if (epurLine(line) && isKeyWord(line, chipsets, links) == false)
				parseLine(line, chipsets, links);
		}
		myFile.close();
	} catch (Err::Errors ex) {
		std::cerr << "Line " << lineNum << ": " << ex.what() << std::endl;
		throw std::exception();
	}
}