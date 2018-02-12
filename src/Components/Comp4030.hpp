/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4030
*/

#ifndef COMP4030_HPP_
	#define COMP4030_HPP_

#include <string>
#include <map>
#include <utility>
#include "IComponent.hpp"

class Comp4030	:	public nts::IComponent
{
	public:
		Comp4030(const std::string &);
		~Comp4030();
		nts::Tristate	compute(std::size_t pin = 1);
		void		setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin);
		void		dump() const;
		const std::string	getName() const { return _name; }
	private:
		const std::string	_name;
		std::map<std::size_t, std::pair<nts::IComponent *, std::size_t>>	_links;
};

#endif /* !COMP4030_HPP_ */
