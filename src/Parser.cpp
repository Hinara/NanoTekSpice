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
			throw Err::ParsingError("Duplicated \'.chipset:\' header");
		s = CHIPSET;
		return (true);
	} else if (line == ".links:") {
		if (s != CHIPSET)
			throw Err::ParsingError("Links section without Chipset section before");
		if (s == LINK)
			throw Err::ParsingError("Duplicated \'.links:\' header");
		s = LINK;
		return (true);
	}
	return (false);
}

void	Parser::verifChipset(const std::string line, Graph &dat)
{
	std::istringstream	data(line);
	nts::ComponentFactory	factory;
	std::string		err;
	chipset_s		elem;

	if (!(data >> elem._comp) || !(data >> elem._name) || data >> err)
		throw Err::ParsingError("Chipset's problem when parsing the file.");
	else if (find(_comp.cbegin(), _comp.cend(), elem._comp) == _comp.cend())
		throw Err::ParsingError("The component '" + elem._comp + "' doesn't exist.");
	else {
		if (dat.getGraph().find(elem._name) != dat.getGraph().cend())
			throw Err::ParsingError("\'" + elem._name + "\' is already used.");
	}
	dat.fillGraph(elem);
}

void	Parser::verifLink(std::string line, Graph &dat)
{
	std::istringstream	data(line);
	std::string		err;
	link_s			elem;

	if (!(data >> elem._nameO) || !(data >> elem._nameT) || data >> err)
		throw Err::ParsingError("Too much link on the line.");
	std::replace(line.begin(), line.end(), ':', ' ');
	std::istringstream	parse(line);
	if (!(parse >> elem._nameO) || !(parse >> elem._pinO)
	|| !(parse >> elem._nameT) || !(parse >> elem._pinT) || parse >> err
	|| elem._pinO <= 0 || elem._pinT <= 0)
		throw Err::ParsingError("Bad arguments when parsing.");
	dat.setLink(elem);
}

void	Parser::parseLine(std::string line, parseState &state, Graph &data)
{
	if (state == CHIPSET) {
		if (line.find(':') != line.npos)
			throw Err::ParsingError("\':\' is a separator and can't be use in chipset.");
		verifChipset(line, data);
	} else if (state == LINK) {
		verifLink(line, data);
	} else
		throw Err::ParsingError("Error: line not in the format:" + line);
}

void	Parser::parseFile(Graph &data)
{
	std::ifstream	myFile(_filename, std::ifstream::in);
	std::string	line;
	parseState	state = NONE;
	int		lineNum = 0;

	try {
		while (getline(myFile, line)) {
			lineNum += 1;
			if (epurLine(line) && isKeyWord(line, state) == false)
				parseLine(line, state, data);
		}
		myFile.close();
	} catch (Err::Errors ex) {
		std::cerr << "Line " << lineNum << ": " << ex.what() << std::endl;
		throw std::exception();
	}
}