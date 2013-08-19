/*
** File Name:	enumerate_map_test.cpp
** Author:	Aditya Ramesh
** Date:	07/18/2013
** Contact:	_@adityaramesh.com
*/

#include <type_traits>
#include <mpl/enumerate_map.hpp>
#include <mpl/integer_sequence.hpp>
#include <ccbase/unit_test.hpp>

struct map
{
	using extents = mpl::extents<2, 2, 2>;

	template <class Coordinates>
	struct get
	{
		using type = mpl::sum<Coordinates>;
	};
};

module("test enumerate map")
{
	using u = mpl::enumerate_map<map>;
	using ue = mpl::sequence<
		mpl::sequence<mpl::sequence<mpl::integer<0>, mpl::integer<0>, mpl::integer<0>>, mpl::integer<0>>,
		mpl::sequence<mpl::sequence<mpl::integer<1>, mpl::integer<0>, mpl::integer<0>>, mpl::integer<1>>,
		mpl::sequence<mpl::sequence<mpl::integer<0>, mpl::integer<1>, mpl::integer<0>>, mpl::integer<1>>,
		mpl::sequence<mpl::sequence<mpl::integer<1>, mpl::integer<1>, mpl::integer<0>>, mpl::integer<2>>,
		mpl::sequence<mpl::sequence<mpl::integer<0>, mpl::integer<0>, mpl::integer<1>>, mpl::integer<1>>,
		mpl::sequence<mpl::sequence<mpl::integer<1>, mpl::integer<0>, mpl::integer<1>>, mpl::integer<2>>,
		mpl::sequence<mpl::sequence<mpl::integer<0>, mpl::integer<1>, mpl::integer<1>>, mpl::integer<2>>,
		mpl::sequence<mpl::sequence<mpl::integer<1>, mpl::integer<1>, mpl::integer<1>>, mpl::integer<3>>
	>;
	require((std::is_same<u, ue>::value));
}

suite("Tests the MPL enumerate map header.")
