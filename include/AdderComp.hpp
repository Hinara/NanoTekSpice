/*
** EPITECH PROJECT, 2017
** Nanotekspice
** File description:
** 4008 component
*/

#ifndef ADDERCOMP_HPP_
	#define ADDERCOMP_HPP_

#include "IComponent.hpp"

class AdderComp 	:	public nts::IComponent {
	public:
		AdderComp();
		//[...]
		~AdderComp();
		nts::Tristate	compute(std::size_t pin = 1);
		void		setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin);
		void		dump() const;
		//[...]
	private:
		//[...]
};

#endif /* !ADDERCOMP_HPP_ */
