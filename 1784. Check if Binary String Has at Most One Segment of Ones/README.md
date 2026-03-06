# 1784. Check if Binary String Has at Most One Segment of Ones

## Problem Description

Given a binary string `s` without leading zeros, return `true` if `s` contains **at most one** contiguous segment of ones. Otherwise, return `false`.

**Constraints:**

* `1 <= s.length <= 100`
* `s[i]` is either `'0'` or `'1'`.
* **`s[0]` is `'1'`.**

---

## Approach

The wording "contiguous segment of ones" can be slightly confusing at first glance. It means we are looking for "islands" of `1`s separated by `0`s.

The most critical clue in the problem description is the constraint: **`s[0]` is always `'1'**`.
This guarantees that we always start on the first "island" of ones. From this starting point, the island can either continue (if we see more `1`s) or end (when we hit the first `0`).

Once the island ends, if we ever encounter another `'1'` later in the string, it implies the existence of a *second* island, which violates the "at most one contiguous segment" rule.

There are two primary ways to translate this logic into code:

### Approach 1: State Tracking (Flag Variable)

We can iterate through the string while maintaining a boolean flag (`haveSeenZero`).

* If we encounter a `'0'`, we set the flag to `true`, indicating the first segment of ones has ended.
* If we encounter a `'1'` but our flag is already `true`, we immediately return `false` because we have found a second segment.

### Approach 2: The "01" Substring Check (Optimal / One-Liner)

If we think about the failure condition in Approach 1, the only way a string can be invalid is if a `'1'` appears *after* a `'0'`.
Therefore, an invalid string must contain the exact sequence `"01"` at least once somewhere in the string. If the substring `"01"` does not exist, the string is perfectly valid. We can simply use the built-in string search function to check for this.

---

## Complexity Analysis

* **Time Complexity: $O(N)$**
  * **Solution 1:** Takes $O(N)$ time because it requires only a single pass through the string of length $N$.
  * **Solution 2:** The `std::string::find()` function takes $O(N)$ time to scan the string for the target substring in the worst case.


* **Space Complexity: $O(1)$**

  * Both solutions use a constant amount of auxiliary space. Solution 1 only uses a single boolean variable, and Solution 2 performs the search in-place without allocating additional memory.

