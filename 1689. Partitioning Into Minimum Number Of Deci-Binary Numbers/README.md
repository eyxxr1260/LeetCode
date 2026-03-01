# 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers

## Problem Description

A decimal number is called **deci-binary** if each of its digits is either `0` or `1` without any leading zeros (e.g., `101` and `1100`).

Given a string `n` that represents a positive decimal integer, the goal is to return the **minimum** number of positive deci-binary numbers needed so that they sum up to `n`.

**Constraints:**

* `1 <= n.length <= 10^5`
* `n` consists of only digits and does not contain any leading zeros.

---

## Approach

At first glance, this problem might look like it requires a complex Dynamic Programming or Greedy algorithm. However, it is actually a logic puzzle based on how basic addition works column by column.

### The Core Insight

Consider how we construct a target number using deci-binary numbers. A deci-binary number can contribute a maximum of `1` to any specific digit column (ones, tens, hundreds, etc.) per addition.

If we look at the number column by column:

* To get a `3` in the tens column, we must add exactly three `1`s together in that column (`1 + 1 + 1`). This means we need **at least 3** deci-binary numbers.
* To get a `2` in the ones column, we need two `1`s (`1 + 1 + 0`). Since we already have 3 numbers from our tens column requirement, we can simply set the ones column of the third number to `0`.

> **The Rule:** The minimum number of deci-binary numbers required is always exactly equal to the **maximum digit** found in the string `n`.

### Example Walkthroughs

* **Example 1 (`n = "32"`):** The digits are `3` and `2`. The maximum digit is `3`. Therefore, we need 3 numbers.
* **Example 2 (`n = "82734"`):** The maximum digit in this string is `8`. We will need exactly 8 deci-binary numbers to accumulate enough `1`s for that specific column.
* **Example 3 (`n = "27346209830709182346"`):** The maximum digit is `9`. Therefore, the answer is 9.

There is no need to perform any actual arithmetic or string manipulation. We only need to scan the string to find the largest character.

---

## Complexity Analysis

* **Time Complexity: O(N)**, where N is the length of the string `n`. We iterate through the characters of the string at most once. The early exit condition (`max_digit == 9`) can make it even faster in practice.
* **Space Complexity: O(1)**. We only use a single integer variable (`max_digit`) to keep track of the largest number, requiring constant extra space.
