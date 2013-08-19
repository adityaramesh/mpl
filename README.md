<!--
  ** File Name:	README.md
  ** Author:	Aditya Ramesh
  ** Date:	08/19/2013
  ** Contact:	_@adityaramesh.com
-->

# Introduction

The purpose of this library is to give your compiler bad gas, and possibly even
diarrhea. It does this by equipping you with a set of generic metaprogramming
operations that operate on multidimensional ranges---accumulation operations,
transformation operations, generation operations, and many others. If you need
to do something _utterly vile and repulsive_, like generate and perform
computations on tensors during compile time, this library is for you. After you
force-feed your compiler your code (as if any sane compiler would lex it
voluntarily!), pour some Pepto-Bismol on your computer, because your computer
needs it.

Subject Responses to Trial Substances
- GCC (4.8.1): Bad gas and foul odor. Delusional episodes about little creatures
  with long ears and green hats.
- ICC (14): Constipation and obsessive nose-picking.
- Clang (3.4): Diarrhea and temporary lactose-intolerance.
- MSVC: **pffffft** Hah! **COFF! COFF! COFF!**

# TODO

- Documentation. Hah!
- Finish `permutation.hpp`.

# Compilation

This library uses a build system called Rake, because running the Rakefile will
make your compiler feel like it has run into a rake.
