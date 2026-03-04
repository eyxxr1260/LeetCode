# 1582. Special Positions in a Binary Matrix

## Problem Description

Given an `m x n` binary matrix `mat`, return the number of special positions in `mat`.

A position `(i, j)` is called **special** if `mat[i][j] == 1` and all other elements in row `i` and column `j` are `0` (rows and columns are 0-indexed).

**Constraints:**

* `m == mat.length`
* `n == mat[i].length`
* `1 <= m, n <= 100`
* `mat[i][j]` is either `0` or `1`.

---

## Approach

A naive brute-force approach would be to iterate through every cell in the matrix, and whenever we find a `1`, we scan its entire row and column to ensure there are no other `1`s. This would result in a time complexity of $O(M \times N \times (M + N))$, which is inefficient and involves a lot of redundant calculations.

Instead, we can use a **Precomputation** strategy.

### The Core Insight

Since the matrix only contains `0`s and `1`s, the condition "all other elements in the row and column are `0`" translates mathematically to:

* The sum of all elements in row `i` is exactly `1`.
* The sum of all elements in column `j` is exactly `1`.

### The 2-Step Process

1. **Precompute Counts (The First Pass):** We create two arrays, `rowCount` and `colCount`, to store the total number of `1`s in each row and each column. We iterate through the matrix once to populate these arrays.
2. **Verify Candidates (The Second Pass):**
We iterate through the matrix a second time. For every position `(i, j)`, we check three conditions:
* Is the current cell itself a `1`? (`mat[i][j] == 1`)
* Is it the *only* `1` in its row? (`rowCount[i] == 1`)
* Is it the *only* `1` in its column? (`colCount[j] == 1`)


If all three conditions are met, we have found a special position and can increment our answer.

---

## Complexity Analysis

* **Time Complexity: O(M * N)**
Where `M` is the number of rows and `N` is the number of columns. We traverse the entire matrix exactly twice. The lookup time for `rowCount[i]` and `colCount[j]` is $O(1)$, making the algorithm highly optimal.
* **Space Complexity: O(M + N)**
We allocate two additional 1D arrays: `rowCount` of size `M` and `colCount` of size `N`, resulting in a linear space complexity relative to the matrix dimensions.
