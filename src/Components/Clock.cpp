/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** clock
*/

#include "Clock.hpp"

Clock::Clock(const std::string &value)
: Input(value)
{
}

void	Clock::swapState()
{
	if (this->_state != nts::UNDEFINED) {
		this->_state = this->_state == (nts::TRUE) ?
			nts::FALSE : nts::TRUE;
	}
}