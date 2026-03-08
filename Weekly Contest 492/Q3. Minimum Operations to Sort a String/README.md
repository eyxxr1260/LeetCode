# 3863. Minimum Operations to Sort a String

## Problem Description

You are given a string `s` consisting of lowercase English letters.

In one operation, you can select any **substring** of `s` that is **not** the entire string and **sort** it in non-descending alphabetical order.

Return the **minimum** number of operations required to make `s` sorted in non-descending order. If it is not possible, return `-1`.
 
### Examples

**Example 1:**
* **Input:** `s = "dog"`
* **Output:** `1`
* **Explanation:**
  Sort substring `"og"` to `"go"`. Now, `s = "dgo"`, which is sorted in ascending order. Thus, the answer is 1.

**Example 2:**
* **Input:** `s = "card"`
* **Output:** `2`
* **Explanation:**
  Sort substring `"car"` to `"acr"`, so `s = "acrd"`.
  Sort substring `"rd"` to `"dr"`, making `s = "acdr"`, which is sorted in ascending order. Thus, the answer is 2.

**Example 3:**
* **Input:** `s = "gf"`
* **Output:** `-1`
* **Explanation:**
  It is impossible to sort `s` under the given constraints (since we cannot select the entire string of length 2). Thus, the answer is -1.

### Constraints
* `1 <= s.length <= 10^5`
* `s` consists of only lowercase English letters.

---

## Approach

This problem looks like a complex sorting simulation, but it is actually a **logical deduction puzzle** based on the positions of the maximum and minimum characters in the string. Because we want to minimize operations, our best strategy is to sort the largest possible portions of the string: either the prefix `s[0...N-2]` or the suffix `s[1...N-1]`.

We can break the scenarios down into 5 specific cases:

1. **0 Operations:** The string is already sorted.
2. **Impossible (-1):** If the string length is exactly 2 and it is not sorted, we can never fix it. We are not allowed to sort the entire string, and sorting a substring of length 1 does nothing.
3. **1 Operation:** We can achieve this if we only need to sort the prefix or the suffix.
   * If the very first character `s[0]` is already the minimum character of the string, we just sort the suffix.
   * If the very last character `s[N-1]` is already the maximum character, we just sort the prefix.
4. **3 Operations (Worst Case):** This happens when the string is completely "deadlocked". 
   * The **unique** maximum character is stuck at `s[0]`.
   * The **unique** minimum character is stuck at `s[N-1]`.
   * Example: `"d c b a"`. We have to sort the prefix to move the max character away from the front, then sort the suffix to move the min character away from the back, and finally sort the prefix one more time to align everything.
5. **2 Operations:** If none of the extreme cases above apply, we can always solve the problem in exactly 2 operations (e.g., sort the prefix, then sort the suffix).

---

## Complexity Analysis
* **Time Complexity:** $O(N)$, where $N$ is the length of the string `s`. We only iterate through the string a few times sequentially (to check if it's sorted, to find the min/max characters, and to count their occurrences). 
* **Space Complexity:** $O(1)$. We only use a few primitive variables (`minL`, `maxL`, `minCount`, `maxCount`, `isSorted`) to store the state, so the space required is constant regardless of the string's length.

