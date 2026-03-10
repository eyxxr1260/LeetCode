# 3130. Find All Possible Stable Binary Arrays II

## Problem Description

You are given 3 positive integers `zero`, `one`, and `limit`.

A binary array `arr` is called **stable** if:

* The number of occurrences of 0 in `arr` is **exactly** `zero`.
* The number of occurrences of 1 in `arr` is **exactly** `one`.
* Each subarray of `arr` with a size greater than `limit` must contain **both** 0 and 1. (i.e., No continuous blocks of 0s or 1s strictly greater than `limit`).

Return the **total** number of stable binary arrays. Since the answer may be very large, return it **modulo** $10^9 + 7$.

**Constraints:**

* `1 <= zero, one, limit <= 1000` *(This is the only difference from Part I, strictly requiring an $O(N^2)$ solution).*

---

## Approach

Because the constraints are up to 1000, the $O(N^3)$ approach from Part I (iterating $k$ from 1 to `limit` at every step) will result in a **Time Limit Exceeded (TLE)** error. We need to optimize the state transitions to $O(1)$ time per state, bringing the overall time complexity down to $O(N^2)$.

We can achieve this using the **Sliding Window Sum** or **Inclusion-Exclusion Principle**.

### The State Definition

We maintain the exact same 3D DP array as Part I:

* `dp[i][j][0]`: Number of valid arrays using `i` zeros, `j` ones, ending in `0`.
* `dp[i][j][1]`: Number of valid arrays using `i` zeros, `j` ones, ending in `1`.

### The "Lazy Builder" Optimization (Inclusion-Exclusion)

Instead of carefully appending blocks of size 1 to `limit`, we can blindly append just **one** single element and then mathematically subtract any illegal configurations we accidentally created.

Let's derive the formula for `dp[i][j][0]` (appending a `0`):

1. **The Blind Addition:** If we want an array ending in `0`, we can take *any* valid array of length $i+j-1$ (whether it ends in `0` or `1`) and simply stick a `0` at the end.

$$Total = dp[i-1][j][0] + dp[i-1][j][1]$$


2. **The Illegal Case:**
By blindly adding a `0`, we might accidentally break the `limit` rule. But because the previous arrays were already 100% valid, the **only** way adding a single `0` causes an explosion is if the previous array *already ended in exactly `limit` zeros*.
By adding our new `0`, the suffix becomes `limit + 1` zeros, which is illegal.
3. **Identifying the Violators:**
What does an illegal array look like? It has a valid prefix ending in `1`, followed by exactly `limit + 1` zeros.
`[Valid prefix ending in 1] + [Exactly limit + 1 zeros]`
To find out how many such violators exist, we look at that valid prefix. That prefix must have used $(i - limit - 1)$ zeros, $j$ ones, and ended in `1`.

$$Violators = dp[i - limit - 1][j][1]$$


4. **The Final $O(1)$ Transition:**
We subtract the violators from the blind addition:

$$dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1] - dp[i - limit - 1][j][1]$$



*(The logic for `dp[i][j][1]` is perfectly symmetrical).*

### The C++ Modulo Trap

In modular arithmetic, subtraction can result in a negative number in C++.
For example, if `A % MOD = 5` and `B % MOD = 100`, then `A - B = -95`. To prevent the DP from breaking due to negative indices during modulo operations, we must **add `MOD` before taking the modulo**:
`(A - B + MOD) % MOD`

---

## Complexity Analysis

* **Time Complexity:** $O(\text{zero} \times \text{one})$
We utilize a nested loop iterating `zero` and `one` times. Inside the inner loop, we only perform $O(1)$ constant time additions and subtractions. This brings the time complexity down from $O(N^3)$ to $O(N^2)$, easily passing the strict constraints.
* **Space Complexity:** $O(\text{zero} \times \text{one})$
The 3D vector requires memory proportional to $\text{zero} \times \text{one} \times 2$. For limits up to 1000, this requires roughly $1000 \times 1000 \times 2 \times 8 \text{ bytes} \approx 16 \text{ MB}$, which comfortably fits within standard memory limits.
