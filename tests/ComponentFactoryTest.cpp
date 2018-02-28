/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Component Factory Test
*/

#include "../src/Components/ComponentFactory.hpp"
#include <criterion/criterion.h>

Test(misc, componentfactorysuccess)
{
	nts::ComponentFactory		cf;

	cr_expect_no_throw(cf.createComponent("4001", "v"), std::out_of_range);
}

Test(misc, componentfactoryerror)
{
	nts::ComponentFactory		cf;

	cr_assert_throw(cf.createComponent("AZERTY", "v"), std::out_of_range);
}