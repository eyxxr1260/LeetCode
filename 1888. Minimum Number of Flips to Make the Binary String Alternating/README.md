# 1888. Minimum Number of Flips to Make the Binary String Alternating

## Problem Description

You are given a binary string `s`. You are allowed to perform two types of operations on the string in any sequence:

* **Type-1:** Remove the character at the start of the string `s` and append it to the end of the string.
* **Type-2:** Pick any character in `s` and flip its value, i.e., if its value is `'0'` it becomes `'1'` and vice-versa.

Return the **minimum** number of **type-2** operations you need to perform such that `s` becomes alternating. The string is called alternating if no two adjacent characters are equal (e.g., `"010"` and `"1010"` are alternating, while `"0100"` is not).

**Constraints:**

* `1 <= s.length <= 10^5`
* `s[i]` is either `'0'` or `'1'`.

---

## Approach

This problem is a leveled-up version of the standard "make the string alternating" problem. The introduction of the **Type-1 operation** essentially means we can **rotate** the string.

A brute-force approach of rotating the string `N` times and checking the minimum flips for each rotation would result in an $O(N^2)$ time complexity, which will result in a Time Limit Exceeded (TLE) error given $N \le 10^5$.

To solve this efficiently in $O(N)$ time, we can combine two powerful techniques: **String Concatenation** and the **Sliding Window**.

### Step 1: The Concatenation Trick to Simulate Rotation

Instead of physically moving characters from the front to the back one by one, we can simply concatenate the string to itself: `doubled_s = s + s`.
Any window of length `N` within this `doubled_s` represents one of the possible rotated states of the original string.

* *Example:* If `s = "111000"`, then `doubled_s = "111000111000"`.
* Window `[0, 5]` is `"111000"` (0 rotations).
* Window `[1, 6]` is `"110001"` (1 rotation).

### Step 2: Prepare the Target Templates

Just like standard alternating binary strings, there are only two valid target patterns of length `2N`:

* `Target 1:` `"010101010101..."`
* `Target 2:` `"101010101010..."`

### Step 3: Sliding Window Execution

We slide a window of size `N` across `doubled_s` and compare it against `Target 1` and `Target 2`.

* **Add to Window:** As the right side of the window expands, if the new character doesn't match the target, we increment our difference counter.
* **Remove from Window:** As the window shifts right, the leftmost character falls out of the window. If that character was previously contributing to our difference counter (i.e., it was a mismatch), we decrement our counter.
* **Record Minimum:** Once the window size reaches `N`, we record the minimum difference found so far.


---

## Complexity Analysis

* **Time Complexity:** $O(N)$
Where $N$ is the length of the string `s`. We iterate through a string of length $2N$ a constant number of times. Inside the sliding window, all addition, removal, and comparison operations are $O(1)$.
* **Space Complexity:** $O(N)$
We allocate extra space to store `doubled_s`, `alt1`, and `alt2`, all of which are proportional to the length of the input string $2N$. *(Note: This can be optimized to $O(1)$ space by using modulo arithmetic `i % n` instead of actually concatenating strings, but $O(N)$ space is often preferred for readability during interviews).*
