/*
** EPITECH PROJECT, 2017
** Nanotekspice
** File description:
** 4040 component
*/

#ifndef COUNTERCOMP_HPP_
	#define COUNTERCOMP_HPP_

#include "IComponent.hpp"

class CounterComp	:	public nts::IComponent {
	public:
		CounterComp();
		//[...]
		~CounterComp();
		nts::Tristate	compute(std::size_t pin = 1);
		void		setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin);
		void		dump() const;
		//[...]
	private:
		//[...]
};

#endif /* !COUNTERCOMP_HPP_ */
