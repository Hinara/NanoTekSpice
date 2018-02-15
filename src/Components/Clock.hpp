/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** clock
*/

#ifndef CLOCK_HPP_
	#define CLOCK_HPP_

#include <string>
#include "Input.hpp"

class Clock	:	public Input
{
public:
	Clock(const std::string &);
	~Clock();
	void	swapState();
private:
	const std::string	_name;
};

#endif /* !CLOCK_HPP_ */
