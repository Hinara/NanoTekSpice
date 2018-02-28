/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** InputTest
*/

#include "../src/Components/Input.hpp"
#include <criterion/criterion.h>

Test(misc, inputcomponentcompute)
{
	Input			t("None");
	t.setState(nts::TRUE);
	cr_assert(t.compute(1) == nts::TRUE);
}

Test(misc, inputcomponentcomputeinvalidpin)
{
	Input			t("None");
	cr_assert_throw(t.compute(2), std::out_of_range);
}