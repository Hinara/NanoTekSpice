/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4008
*/

#ifndef COMP4008_HPP_
	#define COMP4008_HPP_

#include <string>
#include <map>
#include <utility>
#include "IComponent.hpp"

class Comp4008	:	public nts::IComponent
{
	public:
		Comp4008(const std::string &);
		~Comp4008();
		nts::Tristate	compute(std::size_t pin = 1);
		void		setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin);
		void		dump() const;
		const std::string	getName() const { return _name; }
	private:
		const std::string	_name;
		std::map<std::size_t, std::pair<nts::IComponent *, std::size_t>>	_links;
};

#endif /* !COMP4008_HPP_ */
