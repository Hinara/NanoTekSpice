/*
** EPITECH PROJECT, 2017
** Nanotekspice
** File description:
** 4094 component
*/

#ifndef SHIFTREGCOMP_HPP_
	#define SHIFTREGCOMP_HPP_

#include "IComponent.hpp"

class ShiftRegComp	:	public nts::IComponent {
	public:
		ShiftRegComp();
		//[...]
		~ShiftRegComp();
		nts::Tristate	compute(std::size_t pin = 1);
		void		setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin);
		void		dump() const;
		//[...]
	private:
		//[...]
};

#endif /* !SHIFTREGCOMP_HPP_ */
