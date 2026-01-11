# Codeforces 149A – Business trip

## Problem Summary
Petya can water a flower in any of the 12 months of the year.  
If he waters the flower in month `i`, it grows by `a[i]` centimeters.  
If he does not, the growth for that month is `0`.

Petya’s parents will believe him **only if the total growth is at least `k` centimeters**.

### Goal
Find the **minimum number of months** Petya needs to water the flower so that the total growth is **≥ `k`**.  
If it is impossible, print `-1`.

---

## Key Observations
- The order of months does **not** matter.
- To minimize the number of months, we should choose the months with the **largest growth values first**.
- Special case:
  - If `k = 0`, the answer is `0` (no watering is needed).

---

## Solution Approach
1. If `k == 0`, print `0` and stop.
2. Sort the array `a` in **descending order**.
3. Start adding values from the largest to the smallest.
4. Count how many months are used until the sum becomes **≥ `k`**.
5. If after all 12 months the sum is still less than `k`, print `-1`.

---

## Examples

### Example 1
**Input**
```

k = 5
a = [1, 1, 1, 1, 2, 2, 3, 2, 2, 1, 1, 1]

```

Sorted:
```

[3, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1]

```

- Month 1 → sum = 3  
- Month 2 → sum = 5 ✅

**Output**
```

2

```

---

### Example 2
**Input**
```

k = 0
a = [0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 3, 0]

```

No growth is required.

**Output**
```

0

```

---

### Example 3
**Input**
```

k = 11
a = [1, 1, 4, 1, 1, 5, 1, 1, 4, 1, 1, 1]

```

Sorted:
```

[5, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1]

```

- Month 1 → sum = 5  
- Month 2 → sum = 9  
- Month 3 → sum = 13 ✅

**Output**
```

3

````

---

## Complexity

* Sorting: `O(12 log 12)` (constant in practice)
* Iteration: `O(12)`

Overall time complexity is **constant** and very efficient.

---

## Conclusion

This problem is solved using a **greedy approach**:
always take the months with the highest growth first to minimize the number of watering months.