# 1404. Number of Steps to Reduce a Number in Binary Representation to One

## 1. Problem Description

Given the binary representation of an integer as a string `s`, return the number of steps to reduce it to `1` under the following rules:

* If the current number is even, divide it by 2.
* If the current number is odd, add 1 to it.

**Constraints:**

* `1 <= s.length <= 500`
* `s` consists of characters '0' or '1'.
* `s[0] == '1'` (The string represents a valid positive integer without leading zeros).

## 2. The Integer Overflow Trap

A common initial approach is to convert the binary string into a standard integer type (e.g., `long long int`) and simulate the steps using a `while (n != 1)` loop.

However, `s.length()` can be up to 500. This means the numeric value can be as large as $2^{500}$, which vastly exceeds the maximum limit of a 64-bit integer ($2^{63} - 1$). Attempting to convert the string to an integer will result in a severe integer overflow. Therefore, the operations must be simulated directly on the string.

## 3. Approach: String Traversal with Carry

Instead of modifying the string length (which is computationally expensive), we can simulate the operations by traversing the string from right to left (from the least significant bit to the most significant bit) while maintaining a `carry` state.

In binary arithmetic:

* **Dividing by 2** is equivalent to shifting the bits to the right (ignoring the current trailing '0').
* **Adding 1** to an odd number changes the trailing '1' to a '0' and generates a carry of `1` to the next bit.

By processing each character `s[i]` and adding the current `carry`, we can determine the necessary steps without evaluating the entire number.

## 4. Key Breakthroughs

### A. Why does the `carry` variable not reset to 0 after an odd number?

When you encounter an odd number (where `s[i] + carry == 1`), the rule dictates adding 1. In binary, `1 + 1 = 10`. This operation converts the current bit to `0` (making it even) and pushes a `1` to the next significant bit on the left.

The subsequent rule for even numbers requires dividing by 2, which effectively removes this trailing `0`. The carry `1` we generated is now the mathematical reality of the next bit. Because adding 1 to a sequence of 1s causes a cascading carry, once `carry` becomes `1`, it remains `1` as long as it encounters other `1`s, or it forces a `0` to become a `1` (which then triggers another +1 operation).

### B. Why does the loop stop at `i > 0` instead of traversing the entire string?

The target of the problem is to reduce the number to exactly `1`. The problem guarantees that `s[0]` is always '1'. This leading '1' represents our destination.

If the loop were to process `s[0]`, the algorithm would see a `1`, treat it as an odd number, add 1 to make it 2, and then divide by 2 to make it 1 again. This would add 2 unnecessary steps to the total. Therefore, the loop must terminate before processing the most significant bit.

### C. Why do we return `steps + carry` at the end?

When the loop terminates at `i = 1`, we look at the final leading bit `s[0]`, which is '1'. The outcome depends entirely on the leftover `carry`:

* **If `carry == 0`** : The leading bit remains `1`. The number has been successfully reduced to 1. No additional steps are required (`steps + 0`).
* **If `carry == 1`** : The carry propagates to `s[0]`, making its effective value `1 + 1 = 2` (binary `10`). To reduce `2` to `1`, exactly one more division by 2 is required. Hence, we add 1 additional step (`steps + 1`).

## 5. Complexity Analysis

* **Time Complexity: O(N)**, where N is the length of the string `s`. The algorithm iterates through the string exactly once.
* **Space Complexity: O(1)**. The algorithm only uses two integer variables (`steps` and `carry`), requiring constant extra space.
