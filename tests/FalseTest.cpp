/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** FalseTest
*/

#include "../src/Components/False.hpp"
#include <criterion/criterion.h>

Test(misc, falsecomponentcompute)
{
	False			t("None");
	cr_assert(t.compute(1) == nts::FALSE);
}

Test(misc, falsecomponentcomputeinvalidpin)
{
	False			t("None");
	cr_assert_throw(t.compute(2), std::out_of_range);
}