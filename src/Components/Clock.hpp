/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** clock
*/

#ifndef CLOCK_HPP_
	#define CLOCK_HPP_
	#include "Input.hpp"

class Clock	:	public Input
{
public:
	Clock(const std::string &);
	~Clock() = default;
	void	swapState();
};

#endif /* !CLOCK_HPP_ */
