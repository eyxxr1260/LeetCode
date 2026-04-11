# 3740 & 3741. Minimum Distance Between Three Equal Elements I & II

## Problem Description

You are given an integer array `nums`. A tuple `(i, j, k)` of 3 **distinct** indices is **good** if `nums[i] == nums[j] == nums[k]`.

The **distance** of a good tuple is defined as:
$$|i - j| + |j - k| + |k - i|$$
where $|x|$ denotes the absolute value of $x$.

Return an integer denoting the **minimum** possible distance of a good tuple. If no good tuples exist, return `-1`.

### Examples

**Example 1:**
* **Input:** nums = [1,2,1,1,3]
* **Output:** 6
* **Explanation:** The minimum distance is achieved by the tuple (0, 2, 3) where $nums[0]=nums[2]=nums[3]=1$. 
* Distance: $|0 - 2| + |2 - 3| + |3 - 0| = 2 + 1 + 3 = 6$.

**Example 2:**
* **Input:** nums = [1,1,2,3,2,1,2]
* **Output:** 8
* **Explanation:** The minimum distance is achieved by the tuple (2, 4, 6) where $nums[2]=nums[4]=nums[6]=2$. 
* Distance: $|2 - 4| + |4 - 6| + |6 - 2| = 2 + 2 + 4 = 8$.

**Example 3:**
* **Input:** nums = [1]
* **Output:** -1
* **Explanation:** There are no good tuples.

### Constraints
* `1 <= n == nums.length <= 10^5`
* `1 <= nums[i] <= n`

---

## Approach

### 1. Mathematical Simplification
The most important step is to simplify the distance formula. Suppose we have three indices $i, j, k$ and we sort them such that $i < j < k$.
The distance formula becomes:
$$(j - i) + (k - j) + (k - i)$$
If we simplify this expression:
$$(j - i + k - j) + (k - i) = (k - i) + (k - i) = 2(k - i)$$

**Conclusion:** The distance of a good tuple is simply **twice the difference between the largest and smallest index**. The middle index $j$ does not change the total distance as long as it sits between $i$ and $k$.



### 2. Grouping by Value
Since we need three indices with the same value, we should group all indices where a specific number appears.
* Use a hash map (`unordered_map`) where the **key** is the number in `nums` and the **value** is a list (`vector`) of its indices.
* Because we iterate through the array from left to right, the list of indices for each number will naturally be **sorted**.

### 3. Sliding Window for Minimum Gap
For any specific number, we have a list of its positions: $[pos_0, pos_1, pos_2, pos_3, \dots, pos_m]$.
To minimize $2(k - i)$, we want to pick three positions that are as close as possible. In a sorted list, the closest three elements will always be **consecutive**. 
* We check triples: $(pos_0, pos_1, pos_2)$, then $(pos_1, pos_2, pos_3)$, and so on.
* For each triple, the distance is $2 \times (pos_{j+2} - pos_j)$.

### 4. Optimization for Large Data ($10^5$)
Since $N = 10^5$, we must avoid copying data. When iterating through the map, we use a **reference** (`&`) to the vector of indices. This ensures we don't spend time duplicating large arrays in memory.

---

## Complexity Analysis

* **Time Complexity:** $O(N)$
    * Building the map takes $O(N)$ as we visit each element once.
    * Iterating through the map and the sliding windows also takes $O(N)$ total because the sum of the lengths of all index vectors equals $N$.
* **Space Complexity:** $O(N)$
    * We store each index once in the `unordered_map`.