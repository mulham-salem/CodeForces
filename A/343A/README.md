# Problem 343A – Rational Resistance

## Problem Summary

Build a resistance equal to the fraction `a/b` using the **fewest possible unit resistors** (each `= 1 Ω`).

Two operations are allowed:
- **Series:** `R = Re + 1`
- **Parallel:** `R = Re · 1 / (Re + 1)`

Given `a` and `b` (irreducible fraction), output the minimum number of resistors needed.

---

## Key Insight

This is **Euclid's Algorithm** in disguise.

The fraction `a/b` has a **continued fraction expansion**, and the **sum of all quotients** in that expansion equals the minimum number of unit resistors required.

Each loop iteration:
- `a / b` → number of **series** resistors needed in this layer
- `a % b` → what remains to be built
- swap → the fraction flips (this represents the **parallel** step)

The running total of all `a / b` values is the answer.

---

## Pseudocode

```

ans = 0
while b != 0:
	ans = ans + (a / b)      // integer division
	temp = a mod b
	a = b
	b = temp
print ans

```

---

## Why It Works

| Step | Meaning |
|------|---------|
| `a / b` | Minimum series resistors for this layer |
| `a % b` | Leftover fraction to build |
| swap `a, b` | Flip fraction → parallel move |
| `ans` sum | Total resistors = answer |

Because each quotient in Euclid's algorithm is the **minimum** count for that layer, and no smaller construction exists, the total is optimal.

---

## Examples

### Example 1: `a = 1, b = 1`

```

ans += 1/1 = 1   → ans = 1
a = 1, b = 0

```
**Answer: `1`** — one resistor is enough.

---

### Example 2: `a = 3, b = 2`

```

ans += 3/2 = 1   → ans = 1
a = 2, b = 1

ans += 2/1 = 2   → ans = 3
a = 1, b = 0

```
**Answer: `3`** — two parallel + one series = `1/2 + 1 = 3/2 Ω`.

---

### Example 3: `a = 199, b = 200`

```

ans += 199/200 = 0  → ans = 0
a = 200, b = 199

ans += 200/199 = 1  → ans = 1
a = 199, b = 1

ans += 199/1 = 199  → ans = 200
a = 1, b = 0

```
**Answer: `200`** — fraction is very close to 1, so many parallel resistors are needed.

---

## Complexity

- **Time:** `O(log(max(a, b)))` — same as Euclid's GCD
- **Space:** `O(1)`

---

## Notes

- Use 64-bit integers (`long long` in C++) since `a, b ≤ 10^18`.
- Do **not** use `%lld` in C++; prefer `cin`/`cout` or `%I64d`.
- A solution is always guaranteed to exist.
