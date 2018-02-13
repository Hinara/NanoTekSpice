/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** parser
*/

#include <sstream>
#include <iostream>
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
std::map<const std::string, std::unique_ptr<nts::IComponent>>	Parser::getGraph() const
{
	return _graph;
}
*/
char	Parser::epurLine(std ::string &line)
{
	if (line.find('#') != line.npos)
		line.erase(line.find('#'));
	if (line == "")
		return 1;
	return 0;
}

char	Parser::isKeyWord(const std::string line, int &chipset, int &link)
{
	if (line == ".chipsets:") {
		chipset += 1;
		if (chipset == 1)
			return 1;
	} else if (line == ".links:") {
		link += 1;
		if (link == 1)
			return 1;
	}
	return 0;
}

void	Parser::putInControler(chipset_s chipset)
{
	const std::vector<std::string>	priority = { "input", "clock", "true", "false" };
	nts::ComponentFactory	factory;

	if (chipset._comp == "output")
		_output[chipset._name] = factory.createComponent(chipset._comp, chipset._name);
	else if (find(priority.cbegin(), priority.cend(), chipset._comp) != priority.cend())
		_component[chipset._name] = factory.createComponent(chipset._comp, chipset._name);
}

void	Parser::verifChipset(const std::string line)
{
	std::istringstream	data(line);
	nts::ComponentFactory	factory;
	std::string		err;
	chipset_s		elem;

	if (!(data >> elem._comp) || !(data >> elem._name) || data >> err)
		throw Err::LexicalError("Chipset's problem when parsing the file.\n");
	else if (find(_comp.cbegin(), _comp.cend(), elem._comp) == _comp.cend())
		throw Err::UnknowType("This component doesn't exist.\n");
	else {
		if (_graph.find(elem._name) != _graph.cend())
			throw Err::LexicalError("\'" + elem._name + "\' is already used.\n");
	}
	putInControler(elem);
	_graph[elem._name] = factory.createComponent(elem._comp, elem._name);
}

void	Parser::LinkGraph(link_s link)
{
	if (_graph.find(link._nameO) == _graph.cend() || _graph.find(link._nameT) == _graph.cend())
		throw Err::LexicalError("This component doesn't exist.\n");
	else if (link._nameO == link._nameT && link._pinO == link._pinT)
		throw Err::LinkError("You can't link a component on the same pin.\n");
	else {
		if (_output.find(link._nameO) != _output.cend() && _output.find(link._nameT) == _output.cend())
			_output[link._nameO]->setLink(link._pinO, *(_graph[link._nameT]), link._pinT);
		if (_output.find(link._nameT) != _output.cend() && _output.find(link._nameO) == _output.cend())
			_output[link._nameT]->setLink(link._pinO, *(_graph[link._nameO]), link._pinT);
	}
}

void	Parser::verifLink(std::string line)
{
	std::istringstream	data(line);
	std::string		err;
	link_s			elem;

	if (!(data >> elem._nameO) || !(data >> elem._nameT) || data >> err)
		throw Err::LexicalError("Too much link on the line.\n");
	std::replace(line.begin(), line.end(), ':', ' ');
	data.str(line);
	elem._nameO = "";
	elem._nameT = "";
	if (!(data >> elem._nameO) || !(data >> elem._pinO)
	|| !(data >> elem._nameT) || !(data >> elem._pinT) || data >> err
	|| elem._pinO <= 0 || elem._pinT <= 0)
		throw Err::LexicalError("Bad arguments when parsing.\n");
	LinkGraph(elem);
}

void	Parser::parseLine(std::string line, int &chipsets, int &links)
{
	if (chipsets == 1 && links == 0) {
		std::replace(line.begin(), line.end(), ':', ' ');
		verifChipset(line);
	} else if (chipsets == 1 && links == 1) {
		verifLink(line);
	} else
		throw Err::LexicalError("Error: line not in the format:\n" + line);
}

void	Parser::parseFile()
{
	std::ifstream	myFile(_filename, std::ifstream::in);
	std::map<const std::string, std::map<const std::string, const std::string>>	_data;
	std::string	line;
	int		chipsets = 0;
	int		links = 0;

	try {
		while (getline(myFile, line)) {
			if (epurLine(line) == 1 || isKeyWord(line, chipsets, links) == 1)
				continue;
			parseLine(line, chipsets, links);
		}
		myFile.close();
	} catch (std::exception ex) {
		std::cout << ex.what();
		throw std::exception();
	}
}