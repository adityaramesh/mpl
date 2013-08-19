/*
** File Name:	accumulate_range_test.cpp
** Author:	Aditya Ramesh
** Date:	07/17/2013
** Contact:	_@adityaramesh.com
*/

#include <type_traits>
#include <mpl/arithmetic_range.hpp>
#include <mpl/integer_sequence.hpp>
#include <ccbase/unit_test.hpp>

module("test accumulate range")
{
	using s = mpl::integer_sequence<1, 2, 3>;
	using u = mpl::sum_range<s, mpl::constant<mpl::integer<1>>::template rebind>;
	using ue = mpl::integer<6>;
	require((std::is_same<u, ue>::value));
}

suite("Tests the MPL accumulate range header.")
