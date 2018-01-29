/*
** EPITECH PROJECT, 2017
** Nanotekspice
** File description:
** 4017 component
*/

#ifndef JOHNSONCOMP_HPP_
	#define JOHNSONCOMP_HPP_

#include "IComponent.hpp"

class JohnsonComp	:	public nts::IComponent {
	public:
		JohnsonComp();
		//[...]
		~JohnsonComp();
		nts::Tristate	compute(std::size_t pin = 1);
		void		setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin);
		void		dump() const;
		//[...]
	private:
		//[...]
};

#endif /* !JOHNSONCOMP_HPP_ */
