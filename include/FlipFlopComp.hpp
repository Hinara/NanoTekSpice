/*
** EPITECH PROJECT, 2017
** Nanotekspice
** File description:
** 4013 component
*/

#ifndef FLIPFLOPCOMP_HPP_
	#define FLIPFLOPCOMP_HPP_

#include "IComponent.hpp"

class FlipFlopComp	:	public nts::IComponent {
	public:
		FlipFlopComp();
		//[...]
		~FlipFlopComp();
		nts::Tristate	compute(std::size_t pin = 1);
		void		setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin);
		void		dump() const;
		//[...]
	private:
		//[...]
};

#endif /* !FLIPFLOPCOMP_HPP_ */
