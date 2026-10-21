# Problem 340A – The Wall

## Problem Summary

Two painters paint bricks on an infinite wall:

- **Iahub** paints every **x**-th brick (x, 2x, 3x, ...) in red.
- **Floyd** paints every **y**-th brick (y, 2y, 3y, ...) in pink.

A brick is painted **both** colors if it is a multiple of **both** x and y — i.e., a multiple of `LCM(x, y)`.

Given a range `[a, b]`, count how many bricks in that range are painted both red and pink.

---

## Key Idea

The bricks painted both colors are exactly the multiples of:

```

lcm = LCM(x, y)

```

The number of multiples of `lcm` in `[a, b]` is:

```

count = floor(b / lcm) - floor((a - 1) / lcm)

```

This is a classic "count multiples in a range" formula.

---

## Example

**Input:**
```

2 3 6 18

```

- `LCM(2, 3) = 6`
- Multiples of 6 in `[6, 18]`: `6, 12, 18` → **3**

**Output:**
```

3

```

Another example:

**Input:**
```

4 6 1 20

```

- `LCM(4, 6) = 12`
- Multiples of 12 in `[1, 20]`: `12` → **1**

---

## Pseudocode

```

read x, y, a, b
lcm = (x / gcd(x, y)) * y
answer = b / lcm - (a - 1) / lcm
print answer

```

---

## Complexity

- **Time Complexity:** `O(log(min(x, y)))` — dominated by the GCD computation.
- **Space Complexity:** `O(1)` — only a few integer variables are used.

---

## Notes

- Use **64-bit integers** (`long long`) since `b` can be up to `2·10^9` and `lcm` up to `10^6`.
- The `gcd` function comes from `<numeric>` in C++17.
- Compute LCM as `(x / gcd(x, y)) * y` to avoid overflow.
