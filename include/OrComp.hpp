/*
** EPITECH PROJECT, 2017
** Nanotekspice
** File description:
** 4071 component
*/

#ifndef ORCOMP_HPP_
	#define ORCOMP_HPP_

#include "IComponent.hpp"

class OrComp	:	public nts::IComponent {
	public:
		OrComp();
		//[...]
		~OrComp();
		nts::Tristate	compute(std::size_t pin = 1);
		void		setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin);
		void		dump() const;
		//[...]
	private:
		//[...]
};

#endif /* !ORCOMP_HPP_ */
