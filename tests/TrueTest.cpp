/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** TrueTest
*/

#include "../src/Components/True.hpp"
#include <criterion/criterion.h>

Test(misc, truecomponentcompute)
{
	True			t("None");
	cr_assert(t.compute(1) == nts::TRUE);
}

Test(misc, truecomponentcomputeinvalidpin)
{
	True			t("None");
	cr_assert_throw(t.compute(2), std::out_of_range);
}