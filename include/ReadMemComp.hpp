/*
** EPITECH PROJECT, 2017
** Nanotekspice
** File description:
** 2716 component
*/

#ifndef READMEMCOMP_HPP_
	#define READMEMCOMP_HPP_

#include "IComponent.hpp"

class ReadMemComp	:	public nts::IComponent {
	public:
		ReadMemComp();
		//[...]
		~ReadMemComp();
		nts::Tristate	compute(std::size_t pin = 1);
		void		setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin);
		void		dump() const;
		//[...]
	private:
		//[...]
};

#endif /* !READMEMCOMP_HPP_ */
