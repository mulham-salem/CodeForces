# Problem 189A – Ribbon

## Problem Description

Polycarpus has a ribbon of length `n`. He wants to cut the ribbon into pieces such that:

1. Each piece has a length of either `a`, `b`, or `c`.
2. The total number of pieces is maximized.

You are given four integers: `n`, `a`, `b`, and `c`. Find the maximum number of ribbon pieces Polycarpus can get by cutting the ribbon according to the rules above.

### Input

Four space-separated integers:  

```

n a b c

```

Where:

- `1 ≤ n, a, b, c ≤ 4000`  
- It is guaranteed that at least one valid cutting exists.  

### Output

Print a single integer — the maximum possible number of ribbon pieces.

---

## Examples

**Example 1**

```

Input:
5 5 3 2

Output:
2

```

**Explanation:**  
- The ribbon can be cut into lengths 3 and 2 → 2 pieces.  
- Cutting into length 5 alone → 1 piece (less optimal).

**Example 2**

```

Input:
7 5 5 2

Output:
2

```

**Explanation:**  
- The ribbon can be cut into lengths 5 + 2 → 2 pieces.  

---

## Approach / Idea

- We want to **maximize the number of pieces**, not just find a combination that sums to `n`.  
- This means we often prefer **smaller lengths** because we can fit more pieces.  
- Let `i` be the number of pieces of length `a`, `j` the number of pieces of length `b`, and `k` the number of pieces of length `c`.  

We need to satisfy:

```

i*a + j*b + k*c = n

```

And maximize:

```

i + j + k

```

---

## Pseudocode

```

max_pieces = 0

for i = 0 to n / a:
for j = 0 to n / b:
remaining = n - (i*a + j*b)
if remaining < 0:
continue
if remaining % c == 0:
k = remaining / c
max_pieces = max(max_pieces, i + j + k)

print max_pieces

```

---

## Notes

- We iterate over all possible counts of `a` and `b` pieces.  
- The remaining length must be divisible by `c` to form valid pieces.  
- The `max` ensures we pick the combination that **maximizes the total number of pieces**.
- Complexity is low enough because `n ≤ 4000`.

---

## Key Takeaways

- Brute-force over small possible counts works efficiently for bounded constraints.  
- Always check the **remaining length** to see if it can form valid pieces.  
- Maximizing the number of pieces often means preferring **smaller lengths** when multiple options exist.

---
