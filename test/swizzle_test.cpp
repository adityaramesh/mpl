/*
** File Name:	swizzle_test.cpp
** Author:	Aditya Ramesh
** Date:	07/18/2013
** Contact:	_@adityaramesh.com
*/

#include <type_traits>
#include <mpl/integer_sequence.hpp>
#include <mpl/swizzle.hpp>
#include <ccbase/unit_test.hpp>

module("test swizzle")
{
	using s = mpl::integer_sequence<1, 2, 3>;
	using t = mpl::integer_sequence<1, 2, 0>;
	using u = mpl::swizzle<t, s>;
	using ue = mpl::integer_sequence<2, 3, 1>;
	require((std::is_same<u, ue>::value));
}

suite("Tests the MPL swizzle header.")
