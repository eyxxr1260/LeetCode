# 1545. Find Kth Bit in Nth Binary String

## Problem Description

Given two positive integers `n` and `k`, the binary string $S_n$ is formed as follows:

* $S_1$ = "0"
* $S_i$ = $S_{i-1}$ + "1" + `reverse(invert(`$S_{i-1}$`))` for $i > 1$

Where `+` denotes concatenation, `reverse(x)` reverses the string, and `invert(x)` changes all '0's to '1's and '1's to '0's.

Return the $k^{th}$ bit in $S_n$. (1-indexed)

**Constraints:**

* `1 <= n <= 20`
* `1 <= k <= 2^n - 1`

## Approach

A brute-force approach of constructing the entire string $S_n$ would be too slow and memory-intensive, especially since $S_{20}$ is $2^{20} - 1$ characters long (roughly 1 million bits).

Instead, we can use a **Divide and Conquer (Recursive)** approach. By observing the construction rule, we can see that $S_n$ has a perfect symmetric structure:
`[ S_{n-1} ] + "1" + [ reverse(invert(S_{n-1})) ]`

Let `len` be the length of $S_n$ (which is $2^n - 1$) and `mid` be the exact center position (`len / 2 + 1`).
For any query $k$, we can determine its location relative to `mid`:

1. **If $k == mid$:** The bit is exactly the "1" in the middle. We simply return `'1'`.
2. **If $k < mid$:** The bit is located in the left half, which is identical to $S_{n-1}$. We can just recursively search for the $k^{th}$ bit in $S_{n-1}$.
3. **If $k > mid$:** The bit is in the right half. This half is the inverted and reversed version of $S_{n-1}$.
    * First, we map $k$ back to its original position in $S_{n-1}$. Since it was reversed, its mirrored position is `len - k + 1`.
    * We recursively find the bit at this mirrored position in $S_{n-1}$.
    * Since the right half was also inverted, we must **invert the result** before returning it.



## Complexity Analysis

* **Time Complexity: O(N)**
In each recursive call, `n` decreases by 1. The maximum depth of the recursion tree is `N`. Therefore, the time complexity is strictly bounded by $O(N)$. Given $N \le 20$, this requires at most 20 operations, which is incredibly fast.
* **Space Complexity: O(N)**
The space complexity is determined by the maximum depth of the recursion stack. Since we recurse at most `N` times, the space complexity is $O(N)$.