# Disjoint intervals

Interval: Pair (A,B) of integers such that A <= B. 

Overlap: When for two intervals (A,B) and (C,D) there exists an integer K such taht A <= K <= B and C <= K <= D. 

Disjoint: Intervals that don't overlap.

Union: For two intervals (A,B) and (C,D), when a single interval (min(A,C),max(BD)) results from (A,B) and (C,D) overlap. 

Intervals (2,6) and (-3,3) overlap and their union is (-3,6). Intervals (13,16) and (16,25) overlap and their union is 13,25). Intervals (50, 58) and (57,63) overlap and their union is (50,63). Intervals (80,86) and (8,8) are disjoint and don't overlap with other intervals. The union of all the intervals consists of a set of pairwise disjoint intervals.

Write a function "int solution(vector<int> &A, vector<int> &B);" that, give two arrays A and B consisting of N elements each, returns the number of pairwise disjoint intervals constituing the union of N intervals described by arrays A and B. The K-th interval, where K is an integer within the range {0..(N-1)], is defined as (A[K],B[K]).

Write an algorithm for the following assumptions:

- N is an integer within the range [0..100000].
- Each element of arrays A, B is an integer within the range [-1.000.000.000..1.000.000.000].
- A[K] <= B[K[ for integers K within the range of [0..(N-1)].
