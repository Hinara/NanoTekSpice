/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4017 Test
*/

#include "../src/Components/Output.hpp"
#include "../src/Components/Comp4017.hpp"
#include "../src/Components/Input.hpp"
#include "../src/Components/Clock.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(misc, 4017)
{
	Clock			clock("None");
	Output			o("None");
	Comp4017		c("None");
	
	clock.setState(nts::FALSE);
	c.setLink(14, clock, 1);
	o.setLink(1, c, 3);
	o.simulate();
	cr_assert(o.getValue() == nts::TRUE);
	clock.swapState();
	o.simulate();
	cr_assert(o.getValue() == nts::FALSE);
}

Test(misc, 4017reset)
{
	Clock			clock("None");
	Input			reset("None");
	Output			o("None");
	Comp4017		c("None");
	
	clock.setState(nts::FALSE);
	reset.setState(nts::FALSE);
	c.setLink(14, clock, 1);
	c.setLink(15, reset, 1);
	o.setLink(1, c, 3);
	o.simulate();
	cr_assert(o.getValue() == nts::TRUE);
	clock.swapState();
	o.simulate();
	cr_assert(o.getValue() == nts::FALSE);
	reset.setState(nts::TRUE);
	o.simulate();
	cr_assert(o.getValue() == nts::TRUE);
}

Test(misc, 4017lowerthan5)
{
	Clock			clock("None");
	Output			o("None");
	Comp4017		c("None");
	
	clock.setState(nts::FALSE);
	c.setLink(14, clock, 1);
	o.setLink(1, c, 12);
	o.simulate();
	cr_assert(o.getValue() == nts::TRUE);
	for (int i = 0 ; i < 5; i++) {
		o.simulate();
		clock.swapState();
		cr_assert(o.getValue() == nts::TRUE);
		o.simulate();
		clock.swapState();
	}
	cr_assert(o.getValue() == nts::FALSE);
}

Test(redirect, 4017dump, .init=cr_redirect_stdout)
{
	Comp4017		c("None");
	
	c.dump();
}