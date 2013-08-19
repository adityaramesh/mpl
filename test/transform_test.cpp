/*
** File Name:	transform_test.cpp
** Author:	Aditya Ramesh
** Date:	07/18/2013
** Contact:	_@adityaramesh.com
*/

#include <type_traits>
#include <mpl/bind.hpp>
#include <mpl/integer_sequence.hpp>
#include <mpl/operation.hpp>
#include <mpl/transform.hpp>
#include <ccbase/unit_test.hpp>

module("test transform")
{
	using s = mpl::integer_sequence<1, 2, 3>;
	using u = mpl::transform<
		mpl::bind<0, mpl::integer<1>, mpl::add>::template rebind,
		s
	>;
	using ue = mpl::integer_sequence<2, 3, 4>;
	require((std::is_same<u, ue>::value));
}

suite("Tests the MPL transform header.")
