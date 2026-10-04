# Problem 319A – Malek Dance Club

## Overview

Malek Dance Club (MDC) and Natalia Fan Club (NFC) each have **2ⁿ** members, with IDs from `0` to `2ⁿ - 1`.  
A dance assignment pairs every MDC member `i` with NFC member `i XOR x`, where `x` is a given binary string of length `n`.

The **complexity** of an assignment is the number of pairs of dancing pairs `(a, b)` and `(c, d)` such that:

- `a < c` and `b > d`

In other words, we count how many **inversions** exist in the pairing sequence.

---

## Key Observation

The pairing is defined by:

```

MDC member i  →  NFC member (i XOR x)

```

Since `x` is fixed, the sequence of NFC partners is just a permutation of `0 … 2ⁿ - 1`.

For any two MDC members `a < c`, an inversion happens when:

```

(a XOR x) > (c XOR x)

```

The total number of inversions can be computed directly from the binary value of `x`:

```

answer = (value(x) * 2^(n - 1)) mod 1,000,000,007

```

Where `value(x)` is the integer represented by the binary string `x`.

### Why does this work?

- XOR with `x` flips the bits of `i` wherever `x` has `1`s.
- Each `1` bit in `x` contributes exactly `2^(n-1)` inversions to the total count.
- Summing over all `1` bits gives `value(x) * 2^(n-1)`.

---

## Examples

### Example 1

**Input:**
```

11

```

**Explanation:**

- `n = 2`, so there are `2² = 4` members.
- `x = 11₂ = 3`.
- Pairing:
  - `0 → 0 XOR 3 = 3`
  - `1 → 1 XOR 3 = 2`
  - `2 → 2 XOR 3 = 1`
  - `3 → 3 XOR 3 = 0`
- Sequence of NFC partners: `3, 2, 1, 0`
- Inversions: every pair is inverted → `C(4, 2) = 6`.
- Formula check: `value(x) = 3`, `2^(n-1) = 2`, so `3 × 2 = 6`.

**Output:**
```

6

```

---

### Example 2

**Input:**
```

01

```

**Explanation:**

- `n = 2`, so there are `2² = 4` members.
- `x = 01₂ = 1`.
- Pairing:
  - `0 → 0 XOR 1 = 1`
  - `1 → 1 XOR 1 = 0`
  - `2 → 2 XOR 1 = 3`
  - `3 → 3 XOR 1 = 2`
- Sequence of NFC partners: `1, 0, 3, 2`
- Inversions:
  - `(0,1)` with `(1,0)` → inversion
  - `(2,3)` with `(3,2)` → inversion
- Total inversions: `2`.
- Formula check: `value(x) = 1`, `2^(n-1) = 2`, so `1 × 2 = 2`.

**Output:**
```

2

```

---

### Example 3

**Input:**
```

1

```

**Explanation:**

- `n = 1`, so there are `2¹ = 2` members.
- `x = 1₂ = 1`.
- Pairing:
  - `0 → 0 XOR 1 = 1`
  - `1 → 1 XOR 1 = 0`
- Sequence of NFC partners: `1, 0`
- Inversions: `(0,1)` with `(1,0)` → `1` inversion.
- Formula check: `value(x) = 1`, `2^(n-1) = 1`, so `1 × 1 = 1`.

**Output:**
```

1

```

---

## Pseudocode

```

MOD = 1000000007

READ x as string
n = length of x

value = 0
FOR each character c in x:
	value = (value * 2 + (c - '0')) MOD MOD

power = 1
FOR i = 0 to n - 2:
	power = (power * 2) MOD MOD

answer = (value * power) MOD MOD
PRINT answer

```

---

## Complexity

- **Time:** O(n) — one pass to compute `value`, one pass to compute `2^(n-1)`
- **Space:** O(1) — only a few variables

---

## Constraints

- `1 ≤ n ≤ 100`
- `x` may contain leading zeros
- Answer modulo `1,000,000,007`

---