# 3861. Minimum Capacity Box

## Problem Description

You are given an integer array `capacity`, where `capacity[i]` represents the capacity of the `ith` box, and an integer `itemSize` representing the size of an item.

The `ith` box can store the item if `capacity[i] >= itemSize`.

Return an integer denoting the index of the box with the **minimum** capacity that can store the item. If multiple such boxes exist, return the **smallest index**.

If no box can store the item, return `-1`.

### Examples

**Example 1:**
* **Input:** `capacity = [1,5,3,7]`, `itemSize = 3`
* **Output:** `2`
* **Explanation:** The box at index 2 has a capacity of 3, which is the minimum capacity that can store the item. Thus, the answer is 2.

**Example 2:**
* **Input:** `capacity = [3,5,4,3]`, `itemSize = 2`
* **Output:** `0`
* **Explanation:** The minimum capacity that can store the item is 3, and it appears at indices 0 and 3. Thus, the answer is 0.

**Example 3:**
* **Input:** `capacity = [4]`, `itemSize = 5`
* **Output:** `-1`
* **Explanation:** No box has enough capacity to store the item, so the answer is -1.

### Constraints
* `1 <= capacity.length <= 100`
* `1 <= capacity[i] <= 100`
* `1 <= itemSize <= 100`

---

## Approach

The goal is to find a box that is large enough to hold the item (`>= itemSize`) but is as small as possible to minimize wasted space. If there is a tie, we must pick the one that appears first (smallest index).

A simple single-pass linear scan is perfect for this:
1. **Trackers:** We maintain two variables: `ans` (initialized to `-1` for the default "not found" state) and `min_num` (initialized to `INT_MAX` to track the best fit we've seen so far).
2. **Left-to-Right Scan:** By iterating from `i = 0` to `n - 1`, we naturally evaluate smaller indices first.
3. **Condition Check:** For each box, we check two things:
   * Is it big enough? (`capacity[i] >= itemSize`)
   * Is its capacity strictly smaller than the best one we've found? (`min_num > capacity[i]`)
4. **Tie-breaking:** Because we use a strictly greater-than sign (`min_num > capacity[i]`), if we encounter another box later with the *exact same* minimum capacity, we will ignore it. This perfectly satisfies the rule to return the "smallest index".

---

## Complexity Analysis
* **Time Complexity:** $O(N)$, where $N$ is the length of the `capacity` array. We only iterate through the array exactly once.
* **Space Complexity:** $O(1)$. We only use a few integer variables for tracking state, regardless of the input size.
