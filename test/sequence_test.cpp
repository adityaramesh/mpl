/*
** File Name:	sequence_test.cpp
** Author:	Aditya Ramesh
** Date:	07/13/2013
** Contact:	_@adityaramesh.com
*/

#include <type_traits>
#include <mpl/sequence.hpp>
#include <ccbase/unit_test.hpp>

module("test concatenation")
{
	using s = mpl::sequence<int>;
	using t = mpl::sequence<float>;
	using u = mpl::cat<s, t>;
	using v = mpl::sequence<int, float>;
	require((std::is_same<u, v>::value));

	using s1 = mpl::sequence<>;
	using t1 = mpl::sequence<float>;
	using u1 = mpl::cat<s1, t1>;
	using v1 = mpl::sequence<float>;
	require((std::is_same<u1, v1>::value));

	using s2 = mpl::sequence<int>;
	using u2 = mpl::append<float, s2>;
	using v2 = mpl::sequence<int, float>;
	require((std::is_same<u2, v2>::value));

	using s3 = mpl::sequence<int>;
	using u3 = mpl::prepend<float, s3>;
	using v3 = mpl::sequence<float, int>;
	require((std::is_same<u3, v3>::value));
}

module("test access")
{
	using s = mpl::sequence<int, float, double>;
	using t = mpl::at<1, s>;
	using u = mpl::set<1, short, s>;
	using v = mpl::sequence<int, short, double>;

	require(mpl::size<s>::value == 3);
	require((std::is_same<t, float>::value));
	require((std::is_same<u, v>::value));

	static constexpr auto a = mpl::contains<float, s>::value;
	static constexpr auto b = !mpl::contains<long, s>::value;
	require(a);
	require(b);
}

module("test insert")
{
	using s = mpl::sequence<int, float, double>;
	using u = mpl::insert_at<1, long, s>;
	using v = mpl::insert_at<3, long, s>;

	using eu = mpl::sequence<int, long, float, double>;
	using ev = mpl::sequence<int, float, double, long>;
	require((std::is_same<u, eu>::value));
	require((std::is_same<v, ev>::value));
}

module("test erase")
{
	using s = mpl::sequence<int, float, double>;
	using u = mpl::erase_at<0, s>;
	using v = mpl::erase_at<2, s>;

	using ue = mpl::sequence<float, double>;
	using ve = mpl::sequence<int, float>;
	require((std::is_same<u, ue>::value));
	require((std::is_same<v, ve>::value));
}

suite("Tests sequence operations.")
