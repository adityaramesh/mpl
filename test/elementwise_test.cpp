/*
** File Name:	elementwise_test.cpp
** Author:	Aditya Ramesh
** Date:	07/18/2013
** Contact:	_@adityaramesh.com
*/

#include <type_traits>
#include <mpl/integer_sequence.hpp>
#include <mpl/arithmetic_elementwise.hpp>
#include <ccbase/unit_test.hpp>

module("test elementwise")
{
	using s = mpl::integer_sequence<1, 2, 3>;
	using u = mpl::elementwise_sum<s, s>;
	using ue = mpl::integer_sequence<2, 4, 6>;
	require((std::is_same<u, ue>::value));
}

suite("Tests the MPL elementwise header.")
