/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4069
*/

#ifndef COMP4069_HPP_
	#define COMP4069_HPP_

#include <string>
#include <map>
#include <utility>
#include "IComponent.hpp"

class Comp4069	:	public nts::IComponent
{
public:
	Comp4069(const std::string &);
	~Comp4069();
	nts::Tristate	compute(std::size_t pin = 1);
	void		setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin);
	void		dump() const;
	const std::string	getName() const { return _name; }
private:
	const std::string	_name;
	std::map<std::size_t, std::pair<nts::IComponent *, std::size_t>>	_links;
};

#endif /* !COMP4069_HPP_ */
