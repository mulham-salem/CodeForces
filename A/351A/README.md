# Problem 351A – Jeff and Rounding

## Overview

Jeff has `2n` real numbers. He performs exactly `n` operations. In each operation he picks two unused numbers `i` and `j` (`i ≠ j`) and:

- replaces `aᵢ` with `⌊aᵢ⌋` (round **down**)
- replaces `aⱼ` with `⌈aⱼ⌉` (round **up**)

After all operations, exactly `n` numbers were rounded down and `n` numbers were rounded up.

Goal: minimize the absolute difference between the **original sum** and the **new sum**.

---

## Key Insight

Write each number as `a = k + f`, where `k = ⌊a⌋` is the integer part and `0 ≤ f < 1` is the fractional part.

| Action | New value | Change in sum |
|--------|-----------|---------------|
| `floor` | `k` | `-f` |
| `ceil`  | `k + 1` (if `f > 0`) | `1 - f` |
| `ceil`  | `k` (if `f = 0`) | `0` |

So:

- **Integer numbers** (`f = 0`) never change the sum, no matter how they are rounded. They only "consume" a `ceil` or `floor` slot.
- **Non-integer numbers** contribute `-f` if rounded down, and `+ (1 - f)` if rounded up.

If we rounded **every** non-integer number down, the total change would be:

```

-S,   where  S = sum of all fractional parts

```

Converting one non-integer number from `floor` to `ceil` increases the total by exactly `+1`. Hence, if we choose `c` non-integer numbers to round **up**, the total change becomes:

```

c - S

```

We want to choose `c` to minimize `|c - S|`, subject to:

```

max(0, n - z) ≤ c ≤ min(n, m)

```

where:

- `z` = number of integer numbers (`f = 0`)
- `m` = number of non-integer numbers (`f > 0`)
- the lower bound `n - z` ensures the remaining `ceil` operations can be taken from integers
- `c ≤ n` because we only have `n` `ceil` operations total
- `c ≤ m` because we cannot round up more non-integers than we have

---

## Example 1

```

n = 3
Numbers: 0.000  0.500  0.750  1.000  2.000  3.000

```

- Integers (`f = 0`): `0.000, 1.000, 2.000, 3.000` → `z = 4`
- Non-integers: `0.500, 0.750` → `m = 2`, `S = 0.5 + 0.75 = 1.25`

Range for `c`:

```

max(0, 3 - 4) = 0  ≤  c  ≤  min(3, 2) = 2

```

Evaluate `|c - 1.25|`:

| c | \|c − 1.25\| |
|---|-------------|
| 0 | 1.25 |
| 1 | 0.25 |
| 2 | 0.75 |

Minimum = `0.25` ✅ (matches expected output)

---

## Example 2

```

n = 3
Numbers: 4469.000  6526.000  4864.000  9356.383  7490.000  995.896

```

- Integers: `4469, 6526, 4864, 7490` → `z = 4`
- Non-integers: `9356.383, 995.896` → `m = 2`, `S = 0.383 + 0.896 = 1.279`

Range for `c`: `[0, 2]`

| c | \|c − 1.279\| |
|---|--------------|
| 0 | 1.279 |
| 1 | 0.279 |
| 2 | 0.721 |

Minimum = `0.279` ✅ (matches expected output)

---

## Pseudocode

```

read n
z ← 0            // count of integers
m ← 0            // count of non-integers
S ← 0            // sum of fractional parts

for i from 1 to 2n:
read a
f ← a - floor(a)
if f ≈ 0:
z ← z + 1
else:
m ← m + 1
S ← S + f

lo ← max(0, n - z)
hi ← min(n, m)

best ← +∞
for c from lo to hi:
best ← min(best, |c - S|)

print best with 3 decimal places

```

---

## Complexity

- **Time:** `O(n)` — one pass over the input, plus a loop of size at most `n`.
- **Space:** `O(1)` — only a few counters are stored.

Since `n ≤ 2000`, this is well within limits.
