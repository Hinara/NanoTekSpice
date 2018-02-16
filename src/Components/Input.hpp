/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Input
*/

#ifndef INPUT_HPP_
	#define INPUT_HPP_
	#include "SuperComponent.hpp"

class Input	:	public SuperComponent
{
public:
	Input(const std::string &);
	~Input();
	nts::Tristate		internalCompute(PinNumber) final;
	static const PinMap	pins;
	void			setState(nts::Tristate);
protected:
	nts::Tristate		_state;
};

#endif /* !INPUT_HPP_ */
