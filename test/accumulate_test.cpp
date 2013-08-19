/*
** File Name:	accumulate_test.cpp
** Author:	Aditya Ramesh
** Date:	07/12/2013
** Contact:	_@adityaramesh.com
*/

#include <type_traits>
#include <mpl/arithmetic.hpp>
#include <mpl/integer_sequence.hpp>
#include <ccbase/unit_test.hpp>

module("test accumulate")
{
	using s = mpl::integer_sequence<1, 2, 3>;
	require(mpl::sum<s>::value == 6);
	require(mpl::product<s>::value == 6);
}

suite("Tests the MPL accumulate header.")
