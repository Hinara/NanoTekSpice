/*
** EPITECH PROJECT, 2017
** Nanotekspice
** File description:
** 4514 component
*/

#ifndef DECODERCOMP_HPP_
	#define DECODERCOMP_HPP_

#include "IComponent.hpp"

class DecoderComp	:	public nts::IComponent {
	public:
		DecoderComp();
		//[...]
		~DecoderComp();
		nts::Tristate	compute(std::size_t pin = 1);
		void		setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin);
		void		dump() const;
		//[...]
	private:
		//[...]
};

#endif /* !DECODERCOMP_HPP_ */
