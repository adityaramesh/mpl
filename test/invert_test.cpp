/*
** File Name:	invert_test.cpp
** Author:	Aditya Ramesh
** Date:	07/14/2013
** Contact:	_@adityaramesh.com
*/

#include <mpl/integer_sequence.hpp>
#include <mpl/invert.hpp>
#include <ccbase/unit_test.hpp>

module("test invert")
{
	using l = mpl::sequence<
		mpl::integer_sequence<1, 10>,
		mpl::integer_sequence<2, 20>,
		mpl::integer_sequence<3, 30>
	>;
	using m = mpl::sequence<
		mpl::sequence<mpl::integer<1>, mpl::integer_sequence<10, 20, 30>>,
		mpl::sequence<mpl::integer<2>, mpl::integer_sequence<10, 20, 30>>,
		mpl::sequence<mpl::integer<3>, mpl::integer_sequence<10, 20, 30>>
	>;
	using n = mpl::sequence<
		mpl::sequence<mpl::integer<10>, mpl::integer_sequence<1, 2, 1, 4>>
	>;

	using u = mpl::invert<l>;
	using v = mpl::invert<m>;
	using w = mpl::invert<n>;

	using ue = mpl::sequence<
		mpl::sequence<mpl::integer<10>, mpl::integer_sequence<1>>,
		mpl::sequence<mpl::integer<20>, mpl::integer_sequence<2>>,
		mpl::sequence<mpl::integer<30>, mpl::integer_sequence<3>>
	>;
	using ve = mpl::sequence<
		mpl::sequence<mpl::integer<10>, mpl::integer_sequence<1, 2, 3>>,
		mpl::sequence<mpl::integer<20>, mpl::integer_sequence<1, 2, 3>>,
		mpl::sequence<mpl::integer<30>, mpl::integer_sequence<1, 2, 3>>
	>;
	using we = mpl::sequence<
		mpl::sequence<mpl::integer<1>, mpl::integer_sequence<10>>,
		mpl::sequence<mpl::integer<2>, mpl::integer_sequence<10>>,
		mpl::sequence<mpl::integer<4>, mpl::integer_sequence<10>>
	>;

	require((std::is_same<u, ue>::value));
	require((std::is_same<v, ve>::value));
	require((std::is_same<w, we>::value));
}

suite("Tests the MPL invert header.")
