# Problem 433A – Kitahara Haruki's Gift

## Problem Summary
You are given `n` apples.  
Each apple weighs either **100** or **200** grams.

Your task is to determine whether it is possible to split all apples into **two groups** such that the **total weight of both groups is equal**.

You must use all apples, and you are **not allowed to break** any apple.

---

## Key Observation
Since all weights are multiples of 100, we can simplify the problem by converting weights into **units**:

- 100 → 1 unit  
- 200 → 2 units  

So instead of working with weights, we work with units.

Let:
- `c100` = number of apples weighing 100
- `c200` = number of apples weighing 200

Total units:
```

units = c100 + 2 * c200

```

Each group must have:
```

units / 2

```

---

## Necessary Conditions

### 1. Total units must be even
If `units` is odd, it is **impossible** to split them evenly.

Example:
```

Apples: 100 100 100 200
Units:  1   1   1   2  → total = 5 (odd)
Result: NO

```

---

### 2. Handling apples of weight 200
If the total units are even:

- If `c200` is **even**, we can always split the apples evenly.
- If `c200` is **odd**, one 200-weight apple remains unpaired.
  - This apple can only be balanced using **two 100-weight apples**.
  - Therefore, we must have `c100 ≥ 2`.

---

## Examples

### Example 1
```

Input:
100 200 100 200

Units:
1 + 2 + 1 + 2 = 6

c200 is even → YES

```

---

### Example 2
```

Input:
200 200 200

Units:
2 + 2 + 2 = 6

c200 is odd and c100 = 0 → NO

```

---

### Example 3
```

Input:
200 200 200 100 100

Units:
2 + 2 + 2 + 1 + 1 = 8

Odd c200 but c100 ≥ 2 → YES

```

---

## Pseudocode

```

count c100 and c200

units = c100 + 2 * c200

if units is odd:
print "NO"
else:
if c200 is even:
print "YES"
else:
if c100 >= 2:
print "YES"
else:
print "NO"

```

---

## Conclusion
The problem is not about summing weights directly,  
but about **balancing units** and handling the case where a single heavy apple must be compensated by two light ones.

---