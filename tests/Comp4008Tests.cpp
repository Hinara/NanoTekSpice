/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4008 Test
*/

#include "../src/Components/Output.hpp"
#include "../src/Components/Comp4008.hpp"
#include "../src/Components/Input.hpp"
#include <criterion/criterion.h>

Test(misc, 4008)
{
	Input			ic("None");
	Input			ia1("None");
	Input			ia2("None");
	Input			ia3("None");
	Input			ia4("None");
	Input			ib1("None");
	Input			ib2("None");
	Input			ib3("None");
	Input			ib4("None");
	Output			o1("None");
	Output			o2("None");
	Output			o3("None");
	Output			o4("None");
	Output			oc("None");
	Comp4008		c("None");
	
	ia1.setState(nts::TRUE);
	ia2.setState(nts::TRUE);
	ia3.setState(nts::TRUE);
	ia4.setState(nts::TRUE);
	ib1.setState(nts::TRUE);
	ib2.setState(nts::TRUE);
	ib3.setState(nts::TRUE);
	ib4.setState(nts::TRUE);
	ic.setState(nts::TRUE);
	c.setLink(9, ic, 1);
	c.setLink(7, ia1, 1);
	c.setLink(6, ia2, 1);
	c.setLink(5, ia3, 1);
	c.setLink(4, ia4, 1);
	c.setLink(3, ib1, 1);
	c.setLink(2, ib2, 1);
	c.setLink(1, ib3, 1);
	c.setLink(15, ib4, 1);
	o1.setLink(1, c, 10);
	o2.setLink(1, c, 11);
	o3.setLink(1, c, 12);
	o4.setLink(1, c, 13);
	oc.setLink(1, c, 14);
	o1.simulate();
	o2.simulate();
	o3.simulate();
	o4.simulate();
	oc.simulate();
	cr_assert(oc.getValue() == nts::TRUE);
	cr_assert(o2.getValue() == nts::TRUE);
	cr_assert(o3.getValue() == nts::TRUE);
	cr_assert(o4.getValue() == nts::TRUE);
	cr_assert(o1.getValue() == nts::TRUE);
}