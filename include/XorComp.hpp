/*
** EPITECH PROJECT, 2017
** Nanotekspice
** File description:
** 4030 component
*/

#ifndef XORCOMP_HPP_
	#define XORCOMP_HPP_

#include "IComponent.hpp"

class XorComp	:	public nts::IComponent {
	public:
		XorComp();
		//[...]
		~XorComp();
		nts::Tristate	compute(std::size_t pin = 1);
		void		setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin);
		void		dump() const;
		//[...]
	private:
		//[...]
};

#endif /* !XORCOMP_HPP_ */
