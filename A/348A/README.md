# Problem 348A – Mafia

## Problem Summary

There are `n` friends playing "Mafia". Each round, exactly **one** person is the supervisor and the other `n-1` people play. Friend `i` wants to play at least `a[i]` rounds (as a player, not supervisor). Find the **minimum number of total rounds** needed so that every friend plays at least `a[i]` times.

**Key insight:** If the game runs for `R` total rounds, then across all rounds there are `R * (n - 1)` total "playing slots" (since each round has `n-1` players). Also, no single person can play more than `R` rounds, because there are only `R` rounds in total.

---

## Constraints

- `3 ≤ n ≤ 10^5`
- `1 ≤ a[i] ≤ 10^9`
- The answer can exceed a 32-bit integer → use `long long`

---

## Approach

Two conditions must hold for the answer `R`:

1. **Total capacity:** Across `R` rounds, there are `R * (n-1)` playing slots. We need:
```

R * (n - 1) ≥ sum(a)
→  R ≥ ceil(sum / (n - 1))

```
2. **Individual limit:** No one can play more than `R` rounds (there are only `R` rounds total). So:
```

R ≥ max(a)

```

Therefore, the answer is:

```

answer = max( max(a), ceil(sum / (n - 1)) )

```

---

## Example 1

```

n = 3
a = [3, 2, 2]

```

- `sum = 7`, `max = 3`
- `ceil(7 / 2) = 4`
- `answer = max(3, 4) = 4`

✅ Output: **4**

---

## Example 2

```

n = 4
a = [2, 2, 2, 2]

```

- `sum = 8`, `max = 2`
- `ceil(8 / 3) = 3`
- `answer = max(2, 3) = 3`

✅ Output: **3**

---

## Pseudocode

```

read n
sum = 0
maxA = 0

for i in 1..n:
	read a
	sum  += a
	maxA = max(maxA, a)

answer = max(maxA, ceil(sum / (n - 1)))
print answer

```

---

> **Note:** `ceil(sum / (n - 1))` is computed as `(sum + n - 2) / (n - 1)` using integer division to avoid floating-point errors.

---

## Complexity

- **Time:** `O(n)` — a single pass over the array
- **Space:** `O(1)` — only two accumulators
