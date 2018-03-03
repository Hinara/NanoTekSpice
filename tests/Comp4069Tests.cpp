/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4069 Test
*/

#include "../src/Components/Output.hpp"
#include "../src/Components/Comp4069.hpp"
#include "../src/Components/Input.hpp"
#include <criterion/criterion.h>

Test(misc, 4069)
{
	Input			i("None");
	Output			o("None");
	Comp4069		c("None");
	
	i.setState(nts::TRUE);
	c.setLink(1, i, 1);
	o.setLink(1, c, 2);
	o.simulate();
	cr_assert(o.getValue() == nts::FALSE);
}