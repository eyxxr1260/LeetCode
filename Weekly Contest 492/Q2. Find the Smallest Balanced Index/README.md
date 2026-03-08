# 3862. Find the Smallest Balanced Index

## Problem Description

You are given an integer array `nums`.

An index `i` is **balanced** if the sum of elements strictly to the left of `i` equals the product of elements strictly to the right of `i`.

* If there are no elements to the left, the sum is considered as 0. 
* Similarly, if there are no elements to the right, the product is considered as 1.

Return an integer denoting the **smallest** balanced index. If no balanced index exists, return `-1`.

### Examples

**Example 1:**
* **Input:** `nums = [2,1,2]`
* **Output:** `1`
* **Explanation:**
  For index `i = 1`:
  Left sum = `nums[0] = 2`
  Right product = `nums[2] = 2`
  Since the left sum equals the right product, index 1 is balanced. No smaller index satisfies the condition, so the answer is 1.

**Example 2:**
* **Input:** `nums = [2,8,2,2,5]`
* **Output:** `2`
* **Explanation:**
  For index `i = 2`:
  Left sum = `2 + 8 = 10`
  Right product = `2 * 5 = 10`
  Since the left sum equals the right product, index 2 is balanced. No smaller index satisfies the condition, so the answer is 2.

**Example 3:**
* **Input:** `nums = [1]`
* **Output:** `-1`
* **Explanation:**
  For index `i = 0`: The left side is empty, so the left sum is 0. The right side is empty, so the right product is 1.
  Since the left sum does not equal the right product, index 0 is not balanced. Therefore, no balanced index exists and the answer is -1.

### Constraints
* `1 <= nums.length <= 10^5`
* `1 <= nums[i] <= 10^9`

---

## Approach

This problem requires calculating left sums and right products. A naive nested loop approach would result in an $O(N^2)$ time complexity, leading to a Time Limit Exceeded (TLE) error given the constraints ($10^5$). Furthermore, consecutive multiplications of $10^9$ will quickly exceed the capacity of a 64-bit integer (`long long`), causing an integer overflow.

To solve this efficiently and safely, we use **Precomputation** and **Overflow Capping**:

1. **Precompute Suffix Products:**
   We create a `products` array where `products[i]` stores the product of all elements to the right of `i`. We populate this array iterating from right to left using the state transition: `products[i] = products[i + 1] * nums[i + 1]`.

2. **Prevent Integer Overflow (The Division Trick):**
   The maximum possible left sum is $10^5 * 10^9 = 10^{14}$. If a right product exceeds this `max_sum`, it can never equal the left sum. To avoid overflow during multiplication, we use division to check if the next multiplication will breach our limit:
   > `if (products[i + 1] > max_sum / nums[i + 1])`
   If true, we simply cap the product at a value impossible to reach (`max_sum + 1`).

3. **Find the Balanced Index:**
   We iterate through the array from left to right, maintaining a running `sum` of the left elements. We compare this running `sum` to our precomputed `products[i]`. The first index where they match is our smallest balanced index.

---

## Complexity Analysis
* **Time Complexity:** `O(N)`, where N is the length of the `nums` array. We traverse the array exactly twice (once right-to-left for products, once left-to-right for sums), making it highly efficient.
* **Space Complexity:** `O(N)`, as we allocate an additional array `products` of the same length as `nums` to store the precomputed suffix products.

