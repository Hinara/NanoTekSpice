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

	cr_expect_no_throw(cf.createComponent("4001", ""), std::out_of_range);
	cr_expect_no_throw(cf.createComponent("4008", ""), std::out_of_range);
	cr_expect_no_throw(cf.createComponent("4011", ""), std::out_of_range);
	cr_expect_no_throw(cf.createComponent("4013", ""), std::out_of_range);
	cr_expect_no_throw(cf.createComponent("4017", ""), std::out_of_range);
	cr_expect_no_throw(cf.createComponent("4030", ""), std::out_of_range);
	cr_expect_no_throw(cf.createComponent("4040", ""), std::out_of_range);
	cr_expect_no_throw(cf.createComponent("4069", ""), std::out_of_range);
	cr_expect_no_throw(cf.createComponent("4071", ""), std::out_of_range);
	cr_expect_no_throw(cf.createComponent("4081", ""), std::out_of_range);
	cr_expect_no_throw(cf.createComponent("4094", ""), std::out_of_range);
	cr_expect_no_throw(cf.createComponent("4514", ""), std::out_of_range);
	cr_expect_no_throw(cf.createComponent("4801", ""), std::out_of_range);
	cr_expect_no_throw(cf.createComponent("2716", ""), std::out_of_range);
	cr_expect_no_throw(cf.createComponent("input", ""), std::out_of_range);
	cr_expect_no_throw(cf.createComponent("output", ""), std::out_of_range);
	cr_expect_no_throw(cf.createComponent("clock", ""), std::out_of_range);
	cr_expect_no_throw(cf.createComponent("true", ""), std::out_of_range);
	cr_expect_no_throw(cf.createComponent("false", ""), std::out_of_range);
}

Test(misc, componentfactoryerror)
{
	nts::ComponentFactory		cf;

	cr_assert_throw(cf.createComponent("AZERTY", "v"), std::out_of_range);
}