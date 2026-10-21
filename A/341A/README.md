# Problem 341A – Tourist Problem

## Problem Summary

Iahub starts at position `0` and must visit `n` destinations located at distinct positions `a1, a2, ..., an` on a straight line. He visits each destination exactly once, in any order, and stops at the last destination (no return to 0).

For every possible route (permutation), the total distance is computed. We need the **average** total distance over all `n!` routes, expressed as an irreducible fraction `numerator/denominator`.

---

## Key Idea

Instead of enumerating all `n!` routes, we count how many times each edge (distance between two points, or between 0 and a point) appears across all permutations.

1. **Sort** the positions.
2. **Contribution of each destination to the first step** (from 0):
   - Each destination `a[i]` is the first visited in `(n-1)!` routes, contributing `a[i]` each time.
3. **Contribution of edges between destinations**:
   - For a pair of positions `(a[i], a[j])` with `i < j`, the edge length `a[j] - a[i]` appears in the route in both directions with a known count.
   - Each pair contributes `2 * (a[j] - a[i])` per permutation on average counting, times the number of permutations where they are adjacent... but the classic closed form is:

```

numerator = sum(a) + Σ 2 * a[i] * (2*i - n + 1)   // for i from 0 to n-1, 0-indexed
denominator = n

```

The final fraction is reduced by `gcd(numerator, denominator)`.

## Why `denominator = n`?

The average over all `n!` permutations simplifies dramatically — the `n!` cancels out, leaving denominator `n`. This is because each destination appears equally often in each "position role" across all permutations.

---

## Example

**Input:**
```

3
2 3 5

```

**Sorted:** `[2, 3, 5]`, `sum = 10`

Compute contributions (`i` is 0-indexed):

| i | a[i] | 2*i - n + 1 | 2*a[i]*(2i-n+1) |
|---|------|-------------|------------------|
| 0 | 2    | -2          | -8               |
| 1 | 3    | 0           | 0                |
| 2 | 5    | 2           | 20               |

```

numerator = 10 + (-8 + 0 + 20) = 22
denominator = 3
gcd(22, 3) = 1

```

**Output:**
```

22 3

```

Which matches the problem statement: average = `22/3`.

---

## Pseudocode

```

read n
read array a[0..n-1]
sum = Σ a[i]
sort(a)

numerator = sum
for i from 0 to n-1:
	numerator += 2 * a[i] * (2*i - n + 1)

denominator = n
g = gcd(abs(numerator), denominator)
print numerator / g, denominator / g

```

---

## Complexity

- **Time:** `O(n log n)` due to sorting.
- **Space:** `O(n)` for storing the array.

---

## Notes

- Use `long long` for `numerator` since values can reach up to ~`10^12` (n ≤ 10^5, ai ≤ 10^7).
- The formula works because each ordered pair of destinations contributes symmetrically, and the `(n-1)!` factor cancels with the `n!` in the denominator, leaving a factor of `1/n`.
