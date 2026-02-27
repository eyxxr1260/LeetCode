# 121. Best Time to Buy and Sell Stock

## Problem Description

You are given an array `prices` where `prices[i]` is the price of a given stock on the `i`th day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return `0`.

**Example 1:**
* **Input:** `prices = [7,1,5,3,6,4]`
* **Output:** `5`
* **Explanation:** Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5. Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

**Example 2:**
* **Input:** `prices = [7,6,4,3,1]`
* **Output:** `0`
* **Explanation:** In this case, no transactions are done and the max profit = 0.

**Constraints:**
* `1 <= prices.length <= 10^5`
* `0 <= prices[i] <= 10^4`

---

## Approach

The problem asks us to find the maximum profit we can get by buying on one day and selling on a subsequent day. A brute-force approach would check every possible pair of buy and sell days, but that would be too slow. 

Instead, we can use a **One-Pass (Greedy)** approach to solve this in linear time. 

Here is the step-by-step logic:
1. **Track the lowest price:** As we iterate through the list of prices, we want to keep track of the lowest price we have seen so far. We initialize a variable `curr` (which acts as our minimum buying price) to the price on the first day.
2. **Calculate potential profit:** On any given day `i`, if we were to sell the stock, our profit would be the price today minus the lowest price we've seen in the past (`prices[i] - curr`).
3. **Update maximum profit:** We maintain a `maxP` variable to keep track of the highest profit we've calculated. At each step, we update `maxP` if the potential profit for the current day is greater than our current `maxP`.
4. **Update minimum price:** If the stock price on the current day `prices[i]` is lower than our recorded `curr`, we update `curr` to this new, lower price. This ensures we are always calculating future profits against the best possible buying price.

## Complexity
* **Time Complexity:** `O(n)` where `n` is the length of the `prices` array. We only traverse the array once.
* **Space Complexity:** `O(1)`. We are only using a few integer variables (`i`, `curr`, `maxP`), which require constant extra space.