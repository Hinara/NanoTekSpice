/*
** EPITECH PROJECT, 2017
** Nanotekspice
** File description:
** 4081 component
*/

#ifndef ANDCOMP_HPP_
	#define ANDCOMP_HPP_

#include "IComponent.hpp"

class AndComp	:	public nts::IComponent {
	public:
		AndComp();
		//[...]
		~AndComp();
		nts::Tristate	compute(std::size_t pin = 1);
		void		setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin);
		void		dump() const;
		//[...]
	private:
		//[...]
};

#endif /* !ANDCOMP_HPP_ */
