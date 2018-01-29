/*
** EPITECH PROJECT, 2017
** Nanotekspice
** File description:
** 4801 component
*/

#ifndef RANDOMMEMCOMP_HPP_
	#define RANDOMMEMCOMP_HPP_

#include "IComponent.hpp"

class RandomMemComp	:	public nts::IComponent {
	public:
		RandomMemComp();
		//[...]
		~RandomMemComp();
		nts::Tristate	compute(std::size_t pin = 1);
		void		setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin);
		void		dump() const;
		//[...]
	private:
		//[...]
};

#endif /* !RANDOMMEMCOMP_HPP_ */
