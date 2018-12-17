# mdindex
A C++ implement of nested loop with variable dimension

For real life computational research, 
multi-dimension problems kill our time.

Consider an *N*-dimension problem.  
We write some codes with *N* level loops.

A month later, *M*-dimension problem need to be solved.
All you can do is to rewrite the codes.

To deal with this problem, I came up with this solution.
Coordinates in such case can be stored in a vector object.
A unnested loop then can be used if the vector itself can
loop over all dimensions.

Read more about the usage in the wiki page.

The tool present here is a pure head file.  Just include it in your 
source file, and it should work.


