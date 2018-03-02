/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4071 Test
*/

#include "../src/Components/Output.hpp"
#include "../src/Components/Comp4071.hpp"
#include "../src/Components/Input.hpp"
#include <criterion/criterion.h>

Test(misc, 4071gate1)
{
	Input			i1("None");
	Input			i2("None");
	Output			o("None");
	Comp4071		c("None");
	
	i1.setState(nts::TRUE);
	i2.setState(nts::TRUE);
	c.setLink(1, i1, 1);
	c.setLink(2, i2, 1);
	o.setLink(1, c, 3);
	o.simulate();
	cr_assert(o.getValue() == nts::TRUE);
}

Test(misc, 4071gate2)
{
	Input			i1("None");
	Input			i2("None");
	Output			o("None");
	Comp4071		c("None");
	
	i1.setState(nts::TRUE);
	i2.setState(nts::TRUE);
	c.setLink(5, i1, 1);
	c.setLink(6, i2, 1);
	o.setLink(1, c, 4);
	o.simulate();
	cr_assert(o.getValue() == nts::TRUE);
}

Test(misc, 4071gate3)
{
	Input			i1("None");
	Input			i2("None");
	Output			o("None");
	Comp4071		c("None");
	
	i1.setState(nts::TRUE);
	i2.setState(nts::TRUE);
	c.setLink(8, i1, 1);
	c.setLink(9, i2, 1);
	o.setLink(1, c, 10);
	o.simulate();
	cr_assert(o.getValue() == nts::TRUE);
}

Test(misc, 4071gate4)
{
	Input			i1("None");
	Input			i2("None");
	Output			o("None");
	Comp4071		c("None");
	
	i1.setState(nts::TRUE);
	i2.setState(nts::TRUE);
	c.setLink(12, i1, 1);
	c.setLink(13, i2, 1);
	o.setLink(1, c, 11);
	o.simulate();
	cr_assert(o.getValue() == nts::TRUE);
}