/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4094
*/

#ifndef COMP4094_HPP_
	#define COMP4094_HPP_

#include <string>
#include "IComponent.hpp"

class Comp4094	:	public nts::IComponent
{
	public:
		Comp4094(const std::string &);
		~Comp4094();
		nts::Tristate	compute(std::size_t pin = 1);
		void		setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin);
		void		dump() const;
		const std::string	getName() const { return _name; }
	private:
		const std::string	_name;
};

#endif /* !COMP4094_HPP_ */
