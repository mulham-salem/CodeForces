# Problem 185A – Plant

## Overview

We start with a single triangle pointing **upwards**.

Each year, every triangle splits into **4 smaller triangles**:

- An **upward** triangle produces:
  - 3 upward triangles
  - 1 downward triangle
- A **downward** triangle produces:
  - 3 downward triangles
  - 1 upward triangle

The process repeats for `n` years.

The goal is to determine **how many upward-pointing triangles** exist after `n` years, modulo **10⁹ + 7**.

---

## Key Observation

Instead of simulating every triangle, track only:

- `U` = number of upward triangles
- `D` = number of downward triangles

After one year:

```text
U' = 3U + D
D' = U + 3D
```

From these transitions:

- The total number of triangles doubles twice every year:

```text
U + D = 4ⁿ
```

- The difference between upward and downward triangles doubles every year:

```text
U − D = 2ⁿ
```

Combining the two equations:

```text
2U = 4ⁿ + 2ⁿ
```

Therefore:

```text
U = (4ⁿ + 2ⁿ) / 2
```

Since the answer is required modulo **10⁹ + 7**, division by `2` is performed using the modular inverse.

---

## Algorithm

```text
Read n

Compute:
    p4 = 4ⁿ mod MOD
    p2 = 2ⁿ mod MOD

Compute the modular inverse of 2

Answer = (p4 + p2) × inverse(2) mod MOD

Print Answer
```

---

## Complexity

- **Time Complexity:** `O(log n)`
- **Space Complexity:** `O(1)`

---