/*
** File Name:	match_test.cpp
** Author:	Aditya Ramesh
** Date:	08/19/2013
** Contact:	_@adityaramesh.com
*/

#include <mpl/match.hpp>
#include <ccbase/unit_test.hpp>

using namespace mpl;

template <class A>
struct foo;

module("test match")
{
	using s = sequence<int, foo<int>, double>;
	using t = sequence<int, short, long>;

	static constexpr auto b1 =
	mpl::contains_specialization_of<foo, s>::value;

	static constexpr auto b2 =
	!mpl::contains_specialization_of<foo, t>::value;

	require(b1);
	require(b2);
}

suite("Tests the MPL match header.")
