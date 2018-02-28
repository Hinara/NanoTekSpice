/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** LogicGates Nand Test
*/

#include "../src/Components/LogicGates.hpp"
#include <criterion/criterion.h>

Test(misc, nand_true_true)
{
	cr_assert(LogicGates::nandGate(nts::TRUE, nts::TRUE) == nts::FALSE);
}

Test(misc, nand_true_false)
{
	cr_assert(LogicGates::nandGate(nts::TRUE, nts::FALSE) == nts::TRUE);
}

Test(misc, nand_true_und)
{
	cr_assert(LogicGates::nandGate(nts::TRUE, nts::UNDEFINED) ==
		nts::UNDEFINED);
}

Test(misc, nand_false_und)
{
	cr_assert(LogicGates::nandGate(nts::FALSE, nts::UNDEFINED) ==
		nts::TRUE);
}