/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** LogicGates And Test
*/

#include "../src/Components/LogicGates.hpp"
#include <criterion/criterion.h>

Test(misc, and_true_true)
{
	cr_assert(LogicGates::andGate(nts::TRUE, nts::TRUE) == nts::TRUE);
}

Test(misc, and_true_false)
{
	cr_assert(LogicGates::andGate(nts::TRUE, nts::FALSE) == nts::FALSE);
}

Test(misc, and_true_und)
{
	cr_assert(LogicGates::andGate(nts::TRUE, nts::UNDEFINED) ==
		nts::UNDEFINED);
}

Test(misc, and_false_und)
{
	cr_assert(LogicGates::andGate(nts::FALSE, nts::UNDEFINED) ==
		nts::FALSE);
}