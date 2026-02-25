# 1356. Sort Integers by The Number of 1 Bits

## Problem Description
Given an integer array `arr`, sort the integers in the array in ascending order by the number of `1`s in their binary representation. 

**Tie-breaking rule:** If two or more integers have the exact same number of `1`s, you must sort them in ascending order by their actual decimal value.

## Intuition & Approach
This problem is a perfect use case for **Custom Sorting** combined with **Bit Manipulation**.

Instead of manually implementing a sorting algorithm, we can leverage C++'s built-in `std::sort()` and provide it with a custom "referee" (a Lambda function) to dictate the rules of the sort.

To count the number of `1` bits quickly, we use the GCC built-in function `__builtin_popcount()`, which counts the set bits (1s) of an integer in `O(1)` time.

### Sorting Logic:
1. **Primary Condition:** Compare the bit counts. The number with fewer `1`s goes first.
2. **Secondary Condition:** If the bit counts are identical, compare the actual integer values. The smaller number goes first.
