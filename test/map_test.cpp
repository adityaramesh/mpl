/*
** File Name:	map_test.cpp
** Author:	Aditya Ramesh
** Date:	07/13/2013
** Contact:	_@adityaramesh.com
*/

#include <iostream>
#include <mpl/integer_sequence.hpp>
#include <mpl/map.hpp>
#include <ccbase/unit_test.hpp>

struct m2
{
	template <class T>
	struct get
	{
		using type = mpl::sequence<T>;
	};
};

module("test get")
{
	using m1 = mpl::sequence<
		mpl::integer_sequence<1, 10>,
		mpl::integer_sequence<2, 20>,
		mpl::integer_sequence<3, 30>
	>;

	using t1 = mpl::get<mpl::integer<2>, m1>;
	using t2 = mpl::get<int, m2>;
	require((std::is_same<t1, mpl::integer<20>>::value));
	require((std::is_same<t2, mpl::sequence<int>>::value));
}

module("test multimap")
{
	using m1 = mpl::sequence<
		mpl::integer_sequence<1, 10>,
		mpl::integer_sequence<2, 20>,
		mpl::integer_sequence<3, 30>
	>;
	
	using m2 = mpl::sequence<
		mpl::sequence<mpl::integer<1>, mpl::integer_sequence<10, 20, 30>>,
		mpl::sequence<mpl::integer<2>, mpl::integer_sequence<10, 20, 30>>,
		mpl::sequence<mpl::integer<3>, mpl::integer_sequence<10, 20, 30>>
	>;

	static constexpr auto a = !mpl::is_multimap<m1>::value;
	static constexpr auto b = mpl::is_multimap<m2>::value;
	require(a);
	require(b);
}

module("test insert")
{
	using m1 = mpl::sequence<
		mpl::integer_sequence<1, 10>,
		mpl::integer_sequence<2, 20>,
		mpl::integer_sequence<3, 30>
	>;
	
	using m2 = mpl::sequence<
		mpl::sequence<mpl::integer<1>, mpl::integer_sequence<10, 20, 30>>,
		mpl::sequence<mpl::integer<2>, mpl::integer_sequence<10, 20, 30>>,
		mpl::sequence<mpl::integer<3>, mpl::integer_sequence<10, 20, 30>>
	>;

	using n1 = mpl::insert<mpl::integer<3>, mpl::integer<30>, m1>;
	using n2 = mpl::insert<mpl::integer<2>, mpl::integer<40>, m1>;
	using n3 = mpl::insert<mpl::integer<4>, mpl::integer<40>, m1>;

	using o1 = mpl::insert<mpl::integer<2>, mpl::integer<30>, m2>;
	using o2 = mpl::insert<mpl::integer<2>, mpl::integer<40>, m2>;
	using o3 = mpl::insert<mpl::integer<4>, mpl::integer<40>, m2>;

	using n1e = mpl::sequence<
		mpl::integer_sequence<1, 10>,
		mpl::integer_sequence<2, 20>,
		mpl::integer_sequence<3, 30>
	>;

	using n2e = mpl::sequence<
		mpl::integer_sequence<1, 10>,
		mpl::integer_sequence<2, 40>,
		mpl::integer_sequence<3, 30>
	>;

	using n3e = mpl::sequence<
		mpl::integer_sequence<1, 10>,
		mpl::integer_sequence<2, 20>,
		mpl::integer_sequence<3, 30>,
		mpl::integer_sequence<4, 40>
	>;

	using o1e = mpl::sequence<
		mpl::sequence<mpl::integer<1>, mpl::integer_sequence<10, 20, 30>>,
		mpl::sequence<mpl::integer<2>, mpl::integer_sequence<10, 20, 30>>,
		mpl::sequence<mpl::integer<3>, mpl::integer_sequence<10, 20, 30>>
	>;

	using o2e = mpl::sequence<
		mpl::sequence<mpl::integer<1>, mpl::integer_sequence<10, 20, 30>>,
		mpl::sequence<mpl::integer<2>, mpl::integer_sequence<10, 20, 30, 40>>,
		mpl::sequence<mpl::integer<3>, mpl::integer_sequence<10, 20, 30>>
	>;

	using o3e = mpl::sequence<
		mpl::sequence<mpl::integer<1>, mpl::integer_sequence<10, 20, 30>>,
		mpl::sequence<mpl::integer<2>, mpl::integer_sequence<10, 20, 30>>,
		mpl::sequence<mpl::integer<3>, mpl::integer_sequence<10, 20, 30>>,
		mpl::sequence<mpl::integer<4>, mpl::integer_sequence<40>>
	>;

	require((std::is_same<n1, n1e>::value));
	require((std::is_same<n2, n2e>::value));
	require((std::is_same<n3, n3e>::value));

	require((std::is_same<o1, o1e>::value));
	require((std::is_same<o2, o2e>::value));
	require((std::is_same<o3, o3e>::value));
}

module("test replace")
{
	using m1 = mpl::sequence<
		mpl::integer_sequence<1, 10>,
		mpl::integer_sequence<2, 20>,
		mpl::integer_sequence<3, 30>
	>;
	
	using m2 = mpl::sequence<
		mpl::sequence<mpl::integer<1>, mpl::integer_sequence<10, 20, 30>>,
		mpl::sequence<mpl::integer<2>, mpl::integer_sequence<10, 20, 30>>,
		mpl::sequence<mpl::integer<3>, mpl::integer_sequence<10, 20, 30>>
	>;

	using n1 = mpl::replace<mpl::integer<2>, mpl::integer<30>, m1>;
	using n2 = mpl::replace<mpl::integer<4>, mpl::integer<40>, m1>;

	using o1 = mpl::replace<mpl::integer<2>, mpl::integer<30>, m2>;
	using o2 = mpl::replace<mpl::integer<4>, mpl::integer<40>, m2>;

	using n1e = mpl::sequence<
		mpl::integer_sequence<1, 10>,
		mpl::integer_sequence<2, 30>,
		mpl::integer_sequence<3, 30>
	>;

	using n2e = mpl::sequence<
		mpl::integer_sequence<1, 10>,
		mpl::integer_sequence<2, 20>,
		mpl::integer_sequence<3, 30>
	>;

	using o1e = mpl::sequence<
		mpl::sequence<mpl::integer<1>, mpl::integer_sequence<10, 20, 30>>,
		mpl::sequence<mpl::integer<2>, mpl::integer_sequence<30>>,
		mpl::sequence<mpl::integer<3>, mpl::integer_sequence<10, 20, 30>>
	>;

	using o2e = mpl::sequence<
		mpl::sequence<mpl::integer<1>, mpl::integer_sequence<10, 20, 30>>,
		mpl::sequence<mpl::integer<2>, mpl::integer_sequence<10, 20, 30>>,
		mpl::sequence<mpl::integer<3>, mpl::integer_sequence<10, 20, 30>>
	>;
	
	require((std::is_same<n1, n1e>::value));
	require((std::is_same<n2, n2e>::value));
	require((std::is_same<o1, o1e>::value));
	require((std::is_same<o2, o2e>::value));
}

module("test erase")
{
	using m1 = mpl::sequence<
		mpl::sequence<mpl::integer<1>, mpl::integer_sequence<10, 20, 30>>,
		mpl::sequence<mpl::integer<2>, mpl::integer_sequence<10, 20, 30>>,
		mpl::sequence<mpl::integer<3>, mpl::integer_sequence<10, 20, 30>>
	>;

	using n1 = mpl::erase<mpl::integer<2>, m1>;
	using n2 = mpl::erase<mpl::integer<4>, m1>;
	
	using n1e = mpl::sequence<
		mpl::sequence<mpl::integer<1>, mpl::integer_sequence<10, 20, 30>>,
		mpl::sequence<mpl::integer<3>, mpl::integer_sequence<10, 20, 30>>
	>;

	using n2e = mpl::sequence<
		mpl::sequence<mpl::integer<1>, mpl::integer_sequence<10, 20, 30>>,
		mpl::sequence<mpl::integer<2>, mpl::integer_sequence<10, 20, 30>>,
		mpl::sequence<mpl::integer<3>, mpl::integer_sequence<10, 20, 30>>
	>;

	require((std::is_same<n1, n1e>::value));
	require((std::is_same<n2, n2e>::value));
}

module("test contains")
{
	using m1 = mpl::sequence<
		mpl::sequence<mpl::integer<1>, mpl::integer_sequence<10, 20, 30>>,
		mpl::sequence<mpl::integer<2>, mpl::integer_sequence<10, 20, 30>>,
		mpl::sequence<mpl::integer<3>, mpl::integer_sequence<10, 20, 30>>
	>;

	static constexpr auto a = mpl::contains_key<mpl::integer<1>, m1>::value;
	static constexpr auto b = mpl::contains_value<
		mpl::integer_sequence<10, 20, 30>, m1
	>::value;

	require(a);
	require(b);
}

suite("Tests the MPL map header.")
