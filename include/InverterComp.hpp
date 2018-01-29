/*
** EPITECH PROJECT, 2017
** Nanotekspice
** File description:
** 4069 component
*/

#ifndef INVERTERCOMP_HPP_
	#define INVERTERCOMP_HPP_

#include "IComponent.hpp"

class InverterComp	:	public nts::IComponent {
	public:
		InverterComp();
		//[...]
		~InverterComp();
		nts::Tristate	compute(std::size_t pin = 1);
		void		setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin);
		void		dump() const;
		//[...]
	private:
		//[...]
};

#endif /* !INVERTERCOMP_HPP_ */
