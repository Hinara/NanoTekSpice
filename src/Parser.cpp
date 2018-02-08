/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** parser
*/

#include <sstream>
#include <iostream>
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

void	Parser::verifChipset(const std::string line)
{
	std::istringstream	data(line);
	std::string		err;
	chipset_s		elem;

	if (!(data >> elem._comp) || !(data >> elem._name) || data >> err)
		throw std::exception();
	else if (find(_comp.cbegin(), _comp.cend(), elem._comp) == _comp.cend())
		throw std::exception();
	for (auto it = _chipsets.cbegin(); it != _chipsets.cend(); it++) {
		if (it->_name == elem._name)
			throw std::exception();
	}
	_chipsets.push_back(elem);
}

void	verifName(const std::string name, std::deque<chipset_s> data)
{
	for (auto it = data.cbegin(); it != data.cend(); it++) {
		if (it->_name == name)
			return ;
	}
	throw std::exception();
}

void	Parser::verifLink(const std::string line)
{
	std::istringstream	data(line);
	std::string		err;
	link_s			elem;

	if (!(data >> elem._nameO) || !(data >> elem._pinO)
	|| !(data >> elem._nameT) || !(data >> elem._pinT) || data >> err
	|| elem._pinO <= 0 || elem._pinT <= 0)
		throw std::exception();
	verifName(elem._nameO, _chipsets);
	verifName(elem._nameT, _chipsets);
	_links.push_back(elem);
}

void	Parser::parseLine(const std::string line, int &chipsets, int &links)
{
	if (chipsets == 1 && links == 0) {
		verifChipset(line);
	} else if (chipsets == 1 && links == 1) {
		verifLink(line);
	} else
		throw std::exception();
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
			while (line.find(':') != line.npos)
				line.replace(line.find(':'), 1, " ");
			parseLine(line, chipsets, links);
		}
		myFile.close();
	} catch (std::exception ex) {
		throw std::exception();
	}
}