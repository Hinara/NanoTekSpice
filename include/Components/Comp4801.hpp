/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4801
*/

#ifndef COMP4801_HPP_
	#define COMP4801_HPP_

#include <string>
#include "IComponent.hpp"

class Comp4801	:	public nts::IComponent
{
	public:
		Comp4801(const std::string &);
		~Comp4801();
		nts::Tristate	compute(std::size_t pin = 1);
		void		setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin);
		void		dump() const;
		const std::string	getName() const { return _name; }
	private:
		const std::string	_name;
};

#endif /* !COMP4801_HPP_ */
