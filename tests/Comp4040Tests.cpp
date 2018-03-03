/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4040 Test
*/

#include "../src/Components/Output.hpp"
#include "../src/Components/Comp4040.hpp"
#include "../src/Components/Input.hpp"
#include "../src/Components/Clock.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(misc, 4040)
{
	Clock			clock("None");
	Output			o("None");
	Comp4040		c("None");
	
	clock.setState(nts::TRUE);
	c.setLink(10, clock, 1);
	o.setLink(1, c, 9);
	o.simulate();
	cr_assert(o.getValue() == nts::FALSE);
	clock.swapState();
	o.simulate();
	cr_assert(o.getValue() == nts::TRUE);
	clock.swapState();
	o.simulate();
	cr_assert(o.getValue() == nts::TRUE);
	clock.swapState();
	o.simulate();
	cr_assert(o.getValue() == nts::FALSE);
}

Test(misc, 4040reset)
{
	Clock			clock("None");
	Input			reset("None");
	Output			o("None");
	Comp4040		c("None");
	
	clock.setState(nts::TRUE);
	reset.setState(nts::FALSE);
	c.setLink(10, clock, 1);
	c.setLink(11, reset, 1);
	o.setLink(1, c, 9);
	o.simulate();
	cr_assert(o.getValue() == nts::FALSE);
	clock.swapState();
	o.simulate();
	cr_assert(o.getValue() == nts::TRUE);
	reset.setState(nts::TRUE);
	o.simulate();
	cr_assert(o.getValue() == nts::FALSE);
}

Test(redirect, 4040dump, .init=cr_redirect_stdout)
{
	Comp4040		c("None");
	
	c.dump();
}