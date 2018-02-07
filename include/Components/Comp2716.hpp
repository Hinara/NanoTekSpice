/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 2716
*/

#ifndef COMP2716_HPP_
	#define COMP2716_HPP_

#include <string>
#include "IComponent.hpp"

class Comp2716	:	public nts::IComponent
{
	public:
		Comp2716(const std::string &);
		~Comp2716();
		nts::Tristate	compute(std::size_t pin = 1);
		void		setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin);
		void		dump() const;
		const std::string	getName() const { return _name; }
	private:
		const std::string	_name;
};

#endif /* !COMP2716_HPP_ */
