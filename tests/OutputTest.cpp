/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Output Test
*/

#include "../src/Components/Input.hpp"
#include "../src/Components/Output.hpp"
#include <criterion/criterion.h>

Test(misc, output) {
	Input			i("None");
	Output			o("None");
	i.setState(nts::TRUE);
	o.setLink(1, i, 1);
	o.simulate();
	cr_assert(o.getValue() == nts::TRUE);
}

Test(misc, outputcompute)
{
	Input			t("None");
	cr_assert_throw(t.compute(2), std::out_of_range);
}

Test(misc, unreachablefunction)
{
	Output			t("None");
}