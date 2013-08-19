/*
** File Name:	subsample_range_test.cpp
** Author:	Aditya Ramesh
** Date:	07/18/2013
** Contact:	_@adityaramesh.com
*/

#include <type_traits>
#include <mpl/subsample_range.hpp>
#include <mpl/integer_sequence.hpp>
#include <ccbase/unit_test.hpp>

module("test subsample range")
{
	using s1 = mpl::integer_sequence<6, 6>;
	using s2 = mpl::integer_sequence<2, 2>;

	using t = mpl::subsample_range<s2, s1>;
	using te = mpl::sequence<
		mpl::sequence<mpl::integer<0>, mpl::integer<0>>,
		mpl::sequence<mpl::integer<2>, mpl::integer<0>>,
		mpl::sequence<mpl::integer<4>, mpl::integer<0>>,
		mpl::sequence<mpl::integer<0>, mpl::integer<2>>,
		mpl::sequence<mpl::integer<2>, mpl::integer<2>>,
		mpl::sequence<mpl::integer<4>, mpl::integer<2>>,
		mpl::sequence<mpl::integer<0>, mpl::integer<4>>,
		mpl::sequence<mpl::integer<2>, mpl::integer<4>>,
		mpl::sequence<mpl::integer<4>, mpl::integer<4>>
	>;
	require((std::is_same<t, te>::value));
}

suite("Tests the MPL subsample range header.")
