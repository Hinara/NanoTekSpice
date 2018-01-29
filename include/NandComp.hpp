/*
** EPITECH PROJECT, 2017
** Nanotekspice
** File description:
** 4011 component
*/

#ifndef NANDCOMP_HPP_
	#define NANDCOMP_HPP_

#include "IComponent.hpp"

class NandComp	:	public nts::IComponent {
	public:
		NandComp();
		//[...]
		~NandComp();
		nts::Tristate	compute(std::size_t pin = 1);
		void		setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin);
		void		dump() const;
		//[...]
	private:
		//[...]
};

#endif /* !NANDCOMP_HPP_ */
