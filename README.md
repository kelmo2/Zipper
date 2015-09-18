# Zipper---Dynamic-Programming
This is the solution to a dynamic programming problem. This was written in C++ using visual studio 2008


Zippers: Given three strings, you are to determine whether the third string can be formed by combining the characters in the first two strings. The first two strings can be mixed arbitrarily, but the characters from each must stay in their original order in the third string.

For example, consider forming "tcarete" from "cat" and "tree": String A: c a t String B: t r e e String C: t c a r e t e

As you can see, we can form string C by selecting the first charcter of "tree", followed by the first 2 characters of "cat", followed by the second and third characters of "tree", followed by the last charcter of "cat" and "tree" respectively.

As a second example, consider forming "catrtee" from "cat" and "tree": String A: c a t String B: t r e e String C: c a t r t e e

The answer for this input is also 'yes'

Output: Output yes if A and B can be combined (zippered) into string C. Output no if A and B cannot be combined to form C.