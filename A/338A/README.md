# Problem 338A – Quiz

## Problem Summary

Manao answers **n** consecutive questions. He got exactly **m** correct. A correct answer gives +1 point and increments a consecutive-correct counter. If the counter reaches **k**, it resets to 0 and the total score is **doubled** (after adding the +1). Wrong answers reset the counter to 0.

Given `n`, `m`, `k`, find the **minimum possible score** modulo `1 000 000 009`. We minimize the actual score, not its remainder.

---

## Key Idea

Let `w = n - m` be the number of wrong answers. Wrong answers split the `m` correct answers into at most `w + 1` groups.

- If we can fit all correct answers into groups of size `< k`, i.e. `m ≤ (k-1) * (w+1)`, **no doubling happens** → answer is simply `m`.
- Otherwise, some doublings are unavoidable. To minimize the score, place all forced doubling blocks **first**, then the remaining correct answers as singles at the end (so they are never doubled).

Number of forced doublings:
```

x = ceil( (m - (k-1)*(w+1)) / k )

```

Score from `x` doublings (each block: add `k`, then double):
```

S = 2k * (2^x - 1)

```
Plus the leftover singles `(m - x*k)` added at the end. Take everything mod `1e9+9`, using fast modular exponentiation for `2^x`.

---

## Examples

**Example 1**
```

n = 5, m = 3, k = 2
w = 2, (k-1)*(w+1) = 3
m ≤ 3  →  no doubling  →  answer = 3

```
Arrangement: ✔ ✘ ✔ ✘ ✔ → score 3.

**Example 2**
```

n = 5, m = 4, k = 2
w = 1, (k-1)(w+1) = 2
m > 2  →  x = ceil((4-2)/2) = 1
score = 22(2^1 - 1) + (4 - 12) = 4 + 2 = 6

```
Arrangement: ✔ ✔ (doubles) ✘ ✔ ✔ → score 6.

---

## Pseudocode

```

read n, m, k
w = n - m
limit = (k - 1) * (w + 1)

if m <= limit:
print m mod MOD
else:
x = ceil( (m - limit) / k )
p2 = pow(2, x, MOD)
ans = (2k mod MOD) * (p2 - 1) mod MOD
ans = (ans + (m - xk)) mod MOD
print ans

```

---

## Complexity

- **Time:** `O(log x)` for modular exponentiation.
- **Space:** `O(1)`.

Fits easily within limits (`n ≤ 1e9`, `1 s`, `256 MB`).
