# 1758. Minimum Changes To Make Alternating Binary String

## Problem Description

You are given a string `s` consisting only of the characters `'0'` and `'1'`. In one operation, you can change any `'0'` to `'1'` or vice versa.

The string is called **alternating** if no two adjacent characters are equal. For example, the string `"010"` is alternating, while the string `"0100"` is not.

Return the **minimum** number of operations needed to make `s` alternating.

**Constraints:**

* `1 <= s.length <= 10^4`
* `s[i]` is either `'0'` or `'1'`.

---

## Approach

A greedy approach of simply flipping a character whenever it matches the previous one can fail because it assumes the first character is always correct. For a binary string, there are strictly **only two** valid alternating patterns of length `n`:

1. **Pattern A (Starts with '0'):** `01010101...` (Even indices are '0', odd indices are '1')
2. **Pattern B (Starts with '1'):** `10101010...` (Even indices are '1', odd indices are '0')

Instead of simulating the flips step-by-step, this problem becomes a pattern-matching exercise. We just need to count how many characters in the given string `s` differ from Pattern A and Pattern B, and then return the smaller count.

### The Mathematical Shortcut

Notice that Pattern A and Pattern B are exact opposites (bitwise inverses) of each other. At any given index `i`, if Pattern A has a `'0'`, Pattern B is guaranteed to have a `'1'`.

Because a character in `s` can only be `'0'` or `'1'`, it must match exactly one of the patterns and mismatch the other at that specific index.
This leads to a highly optimized mathematical relationship:
`Operations for Pattern B = Total Length - Operations for Pattern A`

This means we only need to calculate the mismatches for one pattern (e.g., the one starting with '0') using a single loop. We can then deduce the mismatches for the other pattern instantly using subtraction, entirely avoiding a second loop.


---

## Complexity Analysis

* **Time Complexity: O(N)**
Where `N` is the length of the string `s`. The algorithm iterates through the string exactly once to compare the characters against the target pattern. The subsequent mathematical deduction takes `O(1)` time.
* **Space Complexity: O(1)**
The algorithm only utilizes a few integer variables (`zeroFirst`, `oneFirst`) to maintain the counts. It evaluates the string in-place without creating any new strings or arrays, resulting in constant auxiliary space.