
# 3129. Find All Possible Stable Binary Arrays I

## Problem Description

You are given 3 positive integers `zero`, `one`, and `limit`.

A binary array `arr` is called **stable** if:

* The number of occurrences of 0 in `arr` is **exactly** `zero`.
* The number of occurrences of 1 in `arr` is **exactly** `one`.
* Each subarray of `arr` with a size greater than `limit` must contain **both** 0 and 1.

Return the **total** number of stable binary arrays. Since the answer may be very large, return it **modulo** $10^9 + 7$.

**Example 1:**

* **Input:** `zero = 1, one = 1, limit = 2`
* **Output:** `2`
* **Explanation:** The two possible stable binary arrays are `[1,0]` and `[0,1]`. Both arrays have a single 0 and a single 1, and no subarray has a length greater than 2.

**Example 2:**

* **Input:** `zero = 1, one = 2, limit = 1`
* **Output:** `1`
* **Explanation:** The only possible stable binary array is `[1,0,1]`. Note that the binary arrays `[1,1,0]` and `[0,1,1]` have subarrays of length 2 with identical elements (e.g., `1,1`), hence, they are not stable.

**Example 3:**

* **Input:** `zero = 3, one = 3, limit = 2`
* **Output:** `14`
* **Explanation:** All the possible stable binary arrays are `[0,0,1,0,1,1]`, `[0,0,1,1,0,1]`, `[0,1,0,0,1,1]`, `[0,1,0,1,0,1]`, `[0,1,0,1,1,0]`, `[0,1,1,0,0,1]`, `[0,1,1,0,1,0]`, `[1,0,0,1,0,1]`, `[1,0,0,1,1,0]`, `[1,0,1,0,0,1]`, `[1,0,1,0,1,0]`, `[1,0,1,1,0,0]`, `[1,1,0,0,1,0]`, and `[1,1,0,1,0,0]`.

**Constraints:**

* $1 \le \text{zero}, \text{one}, \text{limit} \le 200$

---

## Approach

### Step 1: Translating the Tricky Constraint

The problem states: *"Each subarray of size greater than limit must contain both 0 and 1."*
This is a mathematically strict way of saying: **"You are strictly forbidden from having more than `limit` consecutive 0s, or more than `limit` consecutive 1s."**

### Step 2: Defining the DP State

We want to build the valid arrays step by step. To know what we can legally append to our current sequence, we must keep track of three things:

1. How many `0`s we have used so far ($i$).
2. How many `1`s we have used so far ($j$).
3. What the **last appended element** was (`0` or `1`), because we must alternate groups of 0s and 1s to avoid exceeding the limit.

We define a 3D Dynamic Programming array `dp[i][j][c]`:

* `dp[i][j][0]`: The number of valid sequences using $i$ zeros, $j$ ones, and **ending in 0**.
* `dp[i][j][1]`: The number of valid sequences using $i$ zeros, $j$ ones, and **ending in 1**.

### Step 3: Base Cases (Initialization)

If we only want to use `0`s (meaning $j = 0$), there is exactly 1 way to do it, as long as the total number of `0`s doesn't exceed our `limit`.

* `dp[i][0][0] = 1` for $1 \le i \le \min(\text{zero}, \text{limit})$

Similarly, if we only want to use `1`s (meaning $i = 0$):

* `dp[0][j][1] = 1` for $1 \le j \le \min(\text{one}, \text{limit})$

### Step 4: State Transitions (The "Chunking" Method)

Instead of adding one character at a time, we build the sequence by appending **chunks** of characters of the opposite type.

* **To build a sequence ending in `0` (`dp[i][j][0]`):**
We must take a valid sequence that previously **ended in `1`** (`dp[i-k][j][1]`), and attach a chunk of `k` zeros to the end of it.
How big can this chunk of zeros be? It can be anything from $1$ up to $\min(i, \text{limit})$.

$$dp[i][j][0] = \sum_{k=1}^{\min(i, limit)} dp[i-k][j][1]$$


* **To build a sequence ending in `1` (`dp[i][j][1]`):**
We take a valid sequence that previously **ended in `0`** (`dp[i][j-k][0]`), and attach a chunk of `k` ones to the end of it.

$$dp[i][j][1] = \sum_{k=1}^{\min(j, limit)} dp[i][j-k][0]$$



*(Don't forget to apply `% MOD` at every addition step to prevent integer overflow!)*

### Step 5: The Final Answer

The total number of valid sequences using exactly `zero` 0s and `one` 1s will be the sum of those ending in `0` and those ending in `1`:
`Total = (dp[zero][one][0] + dp[zero][one][1]) % MOD`

---

## Complexity Analysis

* **Time Complexity:** $O(\text{zero} \times \text{one} \times \text{limit})$
We have three nested loops. The outer loops run `zero` and `one` times, and the innermost loop runs up to `limit` times. Given the constraints ($N \le 200$), the maximum operations are $200 \times 200 \times 200 = 8 \times 10^6$, which easily executes well under the typical 1-second time limit in C++.
* **Space Complexity:** $O(\text{zero} \times \text{one})$
We allocated a 3D vector of size `(zero + 1) * (one + 1) * 2`. Since the third dimension is a constant $2$, the memory scales linearly with $\text{zero} \times \text{one}$, which takes up a fraction of a Megabyte and is highly optimal.
