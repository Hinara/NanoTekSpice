/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** clock
*/

#include "../Errors.hpp"
#include "Clock.hpp"

Clock::Clock(const std::string &name)
: Input(name), _name(name)
{
}

Clock::~Clock()
{
}

void	Clock::swapState()
{
	if (this->_state != nts::UNDEFINED) {
		this->_state = this->_state == (nts::TRUE) ?
			nts::TRUE : nts::FALSE;
	}
}