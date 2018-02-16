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
	void			setState(nts::Tristate);
protected:
	nts::Tristate		internalCompute(PinNumber) final;
	nts::Tristate		_state;
private:
	static const PinMap	_pins;
};

#endif /* !INPUT_HPP_ */
