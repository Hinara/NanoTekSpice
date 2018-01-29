/*
** EPITECH PROJECT, 2017
** Nanotekspice
** File description:
** Parser
*/

#ifndef PARSER_HPP_
	#define PARSER_HPP_

#include <map>
#include <string>
#include "IComponent.hpp"

class Parser {
	public:
		Parser(const std::string &);
		~Parser();
		const std::string				&getFile() const;
		std::map<const std::string, nts::IComponent &>	getComponants() const;
	private:
		const std::string	_file;
		std::map<const std::string, nts::IComponent &>	_components;
};

#endif /* !PARSER_HPP_ */
