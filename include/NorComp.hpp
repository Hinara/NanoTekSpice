/*
** EPITECH PROJECT, 2017
** Nanotekspice
** File description:
** 4001 component
*/

#ifndef NORCOMP_HPP_
	#define NORCOMP_HPP_

#include "IComponent.hpp"

class NorComp	:	public nts::IComponent {
	public:
		NorComp();
		//[...]
		~NorComp();
		nts::Tristate	compute(std::size_t pin = 1);
		void		setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin);
		void		dump() const;
		//[...]
	private:
		//[...]
};

#endif /* !NORCOMP_HPP_ */
