1680. Concatenation of Consecutive Binary Numbers

## Problem Description

Given an integer `n`, return the decimal value of the binary string formed by concatenating the binary representations of `1` to `n` in order, modulo `10^9 + 7`.

**Constraints:**

* `1 <= n <= 10^5`

## Approach

The naive approach of converting numbers to binary strings, concatenating them, and converting them back to a decimal integer will result in a Time Limit Exceeded (TLE) error and exceed memory limits due to the massive size of the concatenated string.

Instead, this problem can be efficiently solved using **bitwise operations** and **modulo arithmetic**.

### 1. Concatenation as Bitwise Left Shift

Concatenating a new binary number to the end of an existing binary number is mathematically equivalent to shifting the existing number to the left by the bit-length of the new number, and then adding the new number.

For example, if the current accumulated result is `1` (binary `1`) and we want to append `2` (binary `10`):

* The length of binary `10` is 2.
* Left shift the current result by 2 bits: `1 << 2` becomes `100` (decimal 4).
* Add the new number: `100 + 10` becomes `110` (decimal 6).

### 2. Dynamically Tracking Binary Length

To perform the left shift, we need to know the binary length of the current integer `i`. The length of a binary number increments exactly when the number reaches a power of 2 (e.g., 1, 2, 4, 8, 16...).

We can efficiently check if a number is a power of 2 using the bitwise AND trick:

* Condition: `(i & (i - 1)) == 0`
* If this condition is true, `i` is a power of 2, meaning its binary representation requires one additional bit compared to `i - 1`. We increment our `length` variable accordingly.

*Note on initialization: We initialize `length = 0`. During the very first iteration where `i = 1`, the condition `(1 & 0) == 0` evaluates to true. The `length` immediately increments to `1` before the shift operation, which is the correct binary length for the number 1.*

### 3. Modulo Arithmetic at Each Step

Because the final number is astronomically large, we must take the modulo `10^9 + 7` at every single step to prevent integer overflow.

The properties of modulo arithmetic allow us to apply the modulo operation during intermediate additions and multiplications (a left shift is essentially multiplication by a power of 2) without affecting the final result. Using a 64-bit integer (`long long int` in C++) for the accumulator `ans` ensures that the temporary value during the left shift and addition does not overflow before the modulo is applied.

## Complexity Analysis

* **Time Complexity:** `O(N)`
The algorithm iterates from `1` to `n` exactly once. Inside the loop, it performs constant time `O(1)` bitwise and arithmetic operations.
* **Space Complexity:** `O(1)`
The algorithm only uses a few primitive variables (`ans`, `length`, `MOD`), requiring no extra scaling memory.