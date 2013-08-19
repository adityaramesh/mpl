/*
** File Name:	generate_range_test.cpp
** Author:	Aditya Ramesh
** Date:	07/17/2013
** Contact:	_@adityaramesh.com
*/

#include <type_traits>
#include <mpl/bind.hpp>
#include <mpl/generate_range.hpp>
#include <mpl/integer_sequence.hpp>
#include <ccbase/unit_test.hpp>

template <class S>
struct sum
{
	using type = mpl::sum<S>;
};

module("test generate range")
{
	using s = mpl::integer_sequence<2, 2, 2>;
	using u = mpl::generate_range<sum, s>;
	using ue = mpl::integer_sequence<0, 1, 1, 2, 1, 2, 2, 3>;
	require((std::is_same<u, ue>::value));
}

suite("Tests the MPL generate range header.")
