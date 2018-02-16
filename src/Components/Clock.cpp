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