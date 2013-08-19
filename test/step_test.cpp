/*
** File Name:	step_test.cpp
** Author:	Aditya Ramesh
** Date:	07/16/2013
** Contact:	_@adityaramesh.com
*/

#include <type_traits>
#include <mpl/integer_sequence.hpp>
#include <mpl/step.hpp>
#include <ccbase/unit_test.hpp>

module("test step by unit tuple")
{
	using s1 = mpl::integer_sequence<0, 1, 0>;
	using s2 = mpl::integer_sequence<1, 1, 0>;
	using s3 = mpl::integer_sequence<1, 1, 1>;
	using s4 = mpl::integer_sequence<2, 2, 2>;

	using t1 = mpl::step<s1, s4>;
	using t2 = mpl::step<s2, s4>;
	using t3 = mpl::step<s3, s4>;

	using t1e = mpl::integer_sequence<1, 1, 0>;
	using t2e = mpl::integer_sequence<0, 0, 1>;
	using t3e = mpl::integer_sequence<0, 0, 0>;

	require((std::is_same<t1, t1e>::value));
	require((std::is_same<t2, t2e>::value));
	require((std::is_same<t3, t3e>::value));
}

module("test multiple steps")
{
	using s1 = mpl::integer_sequence<0, 0, 0>;
	using s2 = mpl::integer_sequence<2, 2, 2>;

	using u = mpl::step<s1, s2, 8>;
	require((std::is_same<u, s1>::value));
}

module("test non-unit step")
{
	using s1 = mpl::integer_sequence<0, 0>;
	using s2 = mpl::integer_sequence<6, 6>;
	using s3 = mpl::integer_sequence<2, 2>;

	using t1 = mpl::step<s1, s2, 0, s3>;
	using t2 = mpl::step<s1, s2, 2, s3>;
	using t3 = mpl::step<s1, s2, 3, s3>;

	using t1e = mpl::integer_sequence<0, 0>;
	using t2e = mpl::integer_sequence<4, 0>;
	using t3e = mpl::integer_sequence<0, 2>;

	require((std::is_same<t1, t1e>::value));
	require((std::is_same<t2, t2e>::value));
	require((std::is_same<t3, t3e>::value));
}

suite("Tests the MPL step header.")
