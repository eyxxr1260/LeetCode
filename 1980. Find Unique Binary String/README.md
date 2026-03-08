# 1980. Find Unique Binary String

## Problem Description

Given an array of strings `nums` containing `n` unique binary strings each of length `n`, return a binary string of length `n` that **does not appear** in `nums`. If there are multiple answers, you may return any of them.

**Constraints:**

* `n == nums.length`
* `1 <= n <= 16`
* `nums[i].length == n`
* `nums[i]` is either `'0'` or `'1'`.
* All the strings of `nums` are **unique**.

---

## Approach

While a standard approach might involve generating random strings or checking all possible combinations until an unused one is found, that can be highly inefficient and complex to implement.

Because the problem guarantees that we are given exactly `n` strings of length `n`, we can use an mathematical trick known as **Cantor's Diagonal Argument**.

### The Diagonal Trick

Instead of searching for a missing string, we **construct** a missing string character by character. We want to build an answer string `ans` of length `n` such that it is guaranteed to be different from every single string currently in the `nums` array.

How do we guarantee it's different from `nums[0]`?

* We make sure its **0th** character is the opposite of `nums[0][0]`.
    
How do we guarantee it's different from `nums[1]`?
* We make sure its **1st** character is the opposite of `nums[1][1]`.

By generalizing this rule, we can ensure that our constructed string differs from the $i$-th string in the array at the $i$-th position. Because it differs from *every* string by at least one character, it is mathematically impossible for our newly generated string to exist in the input array.


---

## Complexity Analysis

* **Time Complexity: O(N)**
Where `N` is the number of strings in the array (which is also the length of each string). We only use a single loop that iterates `N` times. In each iteration, accessing the character and assigning the flipped value takes `O(1)` constant time.
* **Space Complexity: O(1)** (Auxiliary Space)
We do not use any extra data structures like hash sets or arrays to keep track of the strings. The only space used is the `ans` string of length `N` which is required for the output, resulting in `O(1)` auxiliary space.
