/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Clock Test
*/

#include "../src/Components/Clock.hpp"
#include <criterion/criterion.h>

Test(misc, clockinputcomponentcompute)
{
	Clock			t("None");
	t.setState(nts::TRUE);
	cr_assert(t.compute(1) == nts::TRUE);
}

Test(misc, clockinputcomponentcomputeinvalidpin)
{
	Clock			t("None");
	cr_assert_throw(t.compute(2), std::out_of_range);
}

Test(misc, clockswapstate)
{
	Clock			t("None");
	t.setState(nts::TRUE);
	t.swapState();
	cr_assert(t.compute(1) == nts::FALSE);
}

Test(misc, clockswapstateundefined)
{
	Clock			t("None");
	t.setState(nts::UNDEFINED);
	t.swapState();
	cr_assert(t.compute(1) == nts::UNDEFINED);
}
