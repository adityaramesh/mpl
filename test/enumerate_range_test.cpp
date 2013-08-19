/*
** File Name:	enumerate_range_test.cpp
** Author:	Aditya Ramesh
** Date:	07/18/2013
** Contact:	_@adityaramesh.com
*/

#include <type_traits>
#include <mpl/enumerate_range.hpp>
#include <mpl/integer_sequence.hpp>
#include <ccbase/unit_test.hpp>

module("test range")
{
	using s = mpl::integer_sequence<1, 1>;
	using t = mpl::integer_sequence<3, 3>;
	using u = mpl::enumerate_range<t, s>;
	using ue = mpl::sequence<
		mpl::integer_sequence<1, 1>,
		mpl::integer_sequence<2, 1>,
      		mpl::integer_sequence<3, 1>,
		mpl::integer_sequence<1, 2>,
		mpl::integer_sequence<2, 2>,
      		mpl::integer_sequence<3, 2>,
		mpl::integer_sequence<1, 3>,
		mpl::integer_sequence<2, 3>,
      		mpl::integer_sequence<3, 3>
	>;
	require((std::is_same<u, ue>::value));
}

suite("Tests the MPL enumerate range header.")
