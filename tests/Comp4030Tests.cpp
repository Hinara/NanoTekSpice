/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4030 Test
*/

#include "../src/Components/Output.hpp"
#include "../src/Components/Comp4030.hpp"
#include "../src/Components/Input.hpp"
#include <criterion/criterion.h>

Test(misc, 4030)
{
	Input			i1("None");
	Input			i2("None");
	Output			o("None");
	Comp4030		c("None");
	
	i1.setState(nts::TRUE);
	i2.setState(nts::TRUE);
	c.setLink(1, i1, 1);
	c.setLink(2, i2, 1);
	o.setLink(1, c, 3);
	o.simulate();
	cr_assert(o.getValue() == nts::FALSE);
}