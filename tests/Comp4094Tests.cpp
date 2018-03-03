/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4094 Test
*/

#include "../src/Components/Comp4094.hpp"
#include "../src/Components/Clock.hpp"
#include "../src/Components/Input.hpp"
#include "../src/Components/Output.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>



#include <iostream>
Test(misc, 4094)
{
	Input			d("None");
	Clock			cl("None");
	Input			s("None");
	Input			oe("None");
	Output			q("None");
	Output			notq("None");
	Output			q8("None");
	Comp4094		c("None");
	
	d.setState(nts::TRUE);
	cl.setState(nts::TRUE);
	s.setState(nts::FALSE);
	oe.setState(nts::FALSE);
	c.setLink(2, d, 1);
	c.setLink(3, cl, 1);
	c.setLink(1, s, 1);
	c.setLink(15, oe, 1);
	q.setLink(1, c, 9);
	notq.setLink(1, c, 10);
	q8.setLink(1, c, 11);
	q8.simulate();
	q.simulate();
	cr_assert(q.getValue() == nts::FALSE);
	cr_assert(q8.getValue() == nts::UNDEFINED);
	for (int i = 0; i < 8; i++) {
		cl.swapState();
		q.simulate();
		cr_assert(q.getValue() == nts::FALSE);
		cl.swapState();
		q.simulate();
	}
	q.simulate();
	cr_assert(q.getValue() == nts::TRUE);
	cr_assert(q8.getValue() == nts::UNDEFINED);
	oe.setState(nts::TRUE);
	q8.simulate();
	cr_assert(q8.getValue() == nts::FALSE);
	s.setState(nts::TRUE);
	q8.simulate();
	cr_assert(q8.getValue() == nts::TRUE);
	notq.simulate();
	cr_assert(notq.getValue() == nts::FALSE);
}

Test(redirect, 4094dump, .init=cr_redirect_stdout)
{
	Comp4094	c("None");
	
	c.dump();
}