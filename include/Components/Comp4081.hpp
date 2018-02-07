/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4081
*/

#ifndef COMP4081_HPP_
	#define COMP4081_HPP_

#include <string>
#include "IComponent.hpp"

class Comp4081	:	public nts::IComponent
{
	public:
		Comp4081(const std::string &);
		~Comp4081();
		nts::Tristate	compute(std::size_t pin = 1);
		void		setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin);
		void		dump() const;
		const std::string	getName() const { return _name; }
	private:
		const std::string	_name;
};

#endif /* !COMP4081_HPP_ */
