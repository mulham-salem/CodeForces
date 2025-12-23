# Problem 143A – Help Greg

## Problem Summary
Greg has **three friends** and knows how many candies each one has.  
He wants all three to have the **same number of candies**.

Your task:
- Determine the **minimum number of candies Greg needs to buy** to equalize them.

---

## Key Idea
- Let `a`, `b`, `c` = candies of the three friends
- To equalize, bring everyone **up to the maximum**:
```text
max_candies = max(a, b, c)
needed = (max_candies - a) + (max_candies - b) + (max_candies - c)
````

* This is the **total number of candies Greg needs**.

---

## Example 1

**Input**

```
3 2 5
```

**Explanation**

* Maximum candies = 5
* Candies needed:

```
5 - 3 = 2
5 - 2 = 3
5 - 5 = 0
Total = 2 + 3 + 0 = 5
```

**Output**

```
5
```

---

## Example 2

**Input**

```
4 4 4
```

**Explanation**

* Maximum = 4
* All already equal
* Candies needed = 0

**Output**

```
0
```

---

## Pseudocode

```text
read a, b, c
max_val = max(a, b, c)
answer = (max_val - a) + (max_val - b) + (max_val - c)
print answer
```

---

## Final Notes

* Only positive number of candies are added (Greg cannot remove candies)
* Simple calculation, **O(1) complexity**
* Works for any integers a, b, c
