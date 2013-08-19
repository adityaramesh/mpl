/*
** File Name:	apply_swizzle_test.cpp
** Author:	Aditya Ramesh
** Date:	07/18/2013
** Contact:	_@adityaramesh.com
*/

#include <type_traits>
#include <mpl/integer_sequence.hpp>
#include <mpl/apply_swizzle.hpp>
#include <ccbase/unit_test.hpp>

template <class T, class U>
struct get_2nd
{
	using type = U;
};

module("test apply swizzle")
{
	using s =
	typename mpl::apply_swizzle<
		mpl::integer_sequence<1, 0>,
		get_2nd
	>::template rebind<
		mpl::integer<1>,
		mpl::integer<2>
	>::type;

	using se = mpl::integer<1>;
	require((std::is_same<s, se>::value));
}

suite("Tests the MPL apply swizzle header.")
