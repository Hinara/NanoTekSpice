/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** LogicGates Nor Test
*/

#include "../src/Components/LogicGates.hpp"
#include <criterion/criterion.h>

Test(misc, nor_true_true)
{
	cr_assert(LogicGates::norGate(nts::TRUE, nts::TRUE) == nts::FALSE);
}

Test(misc, nor_true_und)
{
	cr_assert(LogicGates::norGate(nts::TRUE, nts::UNDEFINED) == nts::FALSE);
}

Test(misc, nor_false_und)
{
	cr_assert(LogicGates::norGate(nts::FALSE, nts::UNDEFINED) ==
		nts::UNDEFINED);
}

Test(misc, nor_false_false)
{
	cr_assert(LogicGates::norGate(nts::FALSE, nts::FALSE) == nts::TRUE);
}