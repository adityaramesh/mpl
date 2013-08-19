/*
** File Name:	repeat_test.cpp
** Author:	Aditya Ramesh
** Date:	07/17/2013
** Contact:	_@adityaramesh.com
*/

#include <type_traits>
#include <mpl/integer_sequence.hpp>
#include <mpl/operation.hpp>
#include <mpl/repeat.hpp>
#include <ccbase/unit_test.hpp>

template <class T>
struct foo;

template <std::uintmax_t T>
struct foo<mpl::integer<T>>
{
	using type = mpl::integer<T + 1>;
};

module("test repeat")
{
	using t = mpl::repeat<3, mpl::integer<0>, foo>;
	using u = mpl::integer<3>;
	require((std::is_same<t, u>::value));
}

suite("Tests the MPL repeat header.")
