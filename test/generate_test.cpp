/*
** File Name:	generate_test.cpp
** Author:	Aditya Ramesh
** Date:	07/13/2013
** Contact:	_@adityaramesh.com
*/

#include <type_traits>
#include <mpl/generate.hpp>
#include <mpl/integer_sequence.hpp>
#include <ccbase/unit_test.hpp>

module("test generate")
{
	using s = mpl::constant_sequence<3, 3>;
	using t = mpl::consecutive_sequence<0, 3>;
	using u = mpl::integer_sequence<3, 3, 3>;
	using v = mpl::integer_sequence<0, 1, 2>;

	require((std::is_same<s, u>::value));
	require((std::is_same<t, v>::value));
}

suite("Tests the MPL generate header.")
