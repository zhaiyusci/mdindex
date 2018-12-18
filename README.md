# mdindex
A C++ implement of nested loop with variable dimension

For real life computational research, 
multi-dimension problems kill our time.

Consider an *N*-dimension problem.
We write some codes with *N* level loops.

A month later, *M*-dimension problems need to be solved.
All you can do is to rewrite the codes.

To deal with this problem, I came up with this solution.
Coordinates in such case can be stored in a vector object.
A non-nested loop then can be used if the vector itself can
loop over all dimensions.

The tool present here is a pure head file.  Just include it in your 
source file, and it should work.

First thing you should notice is that the work based on the standard container `vector`.
[Learn more](https://en.cppreference.com/w/cpp/container/vector) about `vector` class if you are not familiar with it.

In this work, `mdindex` class is implemented.  To use this class, include the head file
```cpp
#include "path/to/mdindex.h"
```
The method listed below:

## Initialization

```cpp
mdindex(const std::vector <int> &max);
```
Set the integer in max as the largest number of each dimension.  For example, you have

```cpp
std::vector<int> max{3,4,5};
```
This means here we have a three-dimension problem where the number of discrete points in each dimension is 3, 4, or 5, respectively.

Then you can write
```cpp
mdindex in(max);
```
to have a multi-dimension index object.

```cpp
mdindex(const mdindex& rhs);
```
The make a copy of `rhs`.

## Set the status
```cpp
mdindex::reset();
```
Set all the indices to 0

## Change the index
+ `++` `--` operators.  To the next or previous one.
+ `+=` `-=` operators.  Run more steps.

You should notice as we are using C++, the index runs from `0` to `(max-1)`.
If it runs out of range, a runtime error is thrown.


## Check the current index
```cpp
mdindex::current();
```
returns the current overall index.

```cpp
mdindex::current(unsigned int i);
```
returns the current ith dimension index.
```cpp
mdindex::max();
```
returns the total number of possible combination.
```cpp
mdindex::max(unsigned int i);
```
returns the max ith dimension index.







