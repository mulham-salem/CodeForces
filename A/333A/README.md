# Problem 333A – Secrets

## Problem Summary

Gerald sells a secret for exactly `n` marks. The only coins available have denominations that are powers of 3: `1, 3, 9, 27, ...`.

A buyer cannot pay exactly `n` marks (using any combination of his coins). So he pays an amount **greater than or equal to `n`** using the **minimum number of coins** possible from his collection.

We consider every possible coin collection where the buyer **cannot** form exactly `n`. For each such collection, we compute the minimum number of coins needed to pay at least `n`. We want the **maximum** of these minimums over all such collections.

---

## Key Idea

Let `p` be the smallest power of 3 that does **not** divide `n`. In other words, `p = 3^k` where `3^k` does not divide `n`, but all smaller powers of 3 do divide `n`.

The answer is:

```

answer = floor(n / p) + 1

```

Since `p` does not divide `n`, this is simply the smallest integer strictly greater than `n / p`.

---

## Examples

### Example 1: `n = 1`

- Powers of 3: `1, 3, 9, ...`
- `1` divides `n = 1`, so we check `3`.
- `3` does not divide `1`. So `p = 3`.
- `answer = floor(1 / 3) + 1 = 0 + 1 = 1`

**Output:** `1`

---

### Example 2: `n = 4`

- `1` divides `4`. Check `3`.
- `3` does not divide `4`. So `p = 3`.
- `answer = floor(4 / 3) + 1 = 1 + 1 = 2`

**Output:** `2`

---

### Example 3: `n = 9`

- `1` divides `9`. Check `3`.
- `3` divides `9`. Check `9`.
- `9` divides `9`. Check `27`.
- `27` does not divide `9`. So `p = 27`.
- `answer = floor(9 / 27) + 1 = 0 + 1 = 1`

**Output:** `1`

---

## Pseudocode

```

read n
power = 1

while n % power == 0:
	power = power * 3
	
answer = n / power

if n % power != 0:
	answer = answer + 1
	
print answer

```

---

## Complexity

- **Time:** `O(log₃ n)` — at most ~36 iterations for `n ≤ 10¹⁷`
- **Space:** `O(1)`