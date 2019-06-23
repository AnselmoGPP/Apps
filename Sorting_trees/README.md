# Sorting trees

There are N trees in a row. We have to cut one of them. All the remaining trees should be sorted in non-decreasing order of height. Count the number of ways this can be done.

Write a function "int function(vector<int> &A)" that, given an array A containing N integers, where A[K] denotes the height of the K-th tree, returns the number of trees you can cut to satisfy the above condition. If the condition cannot be satisfied, your function should return 0.

Examples:

- Given A = [3, 4, 5, 4], your function should return 2. You can cut down the tree of height 5 or second tree of heigh 4.

- Given A = [4, 5, 2, 3, 4], your function should return 0. After cutting down any of these trees, the rest of the trees will not be ordered by height.

- Given A = [1, 2, 3, 3, 5, 6, 7], your function should return 7. You can cut down any of these trees.

Asume that: 

- N is an integer within the range [1..200].
- Each element of array A is an integer within the range [1..1000].

