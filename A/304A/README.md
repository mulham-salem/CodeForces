# Problem 304A – Pythagorean Theorem II

## Problem Overview

In this problem, we are asked to count how many **right-angled triangles** with **integer side lengths** exist such that:

- The sides satisfy the Pythagorean theorem  
  **a² + b² = c²**
- The side lengths follow the constraints  
  **1 ≤ a ≤ b ≤ c ≤ n**

Here:
- `a` and `b` are the two legs of the triangle
- `c` is the hypotenuse (the longest side)

The input is a single integer `n`, and the task is to count all valid triangles whose sides do not exceed `n`.

---

## Key Observations

- Each valid triangle corresponds to a **Pythagorean triple**.
- The condition `a ≤ b ≤ c` ensures that the same triangle is **not counted multiple times**.
- Instead of looping over all three sides, we can:
  - Loop over `a` and `b`
  - Compute `c` directly using the equation

---

## Example

### Example 1

**Input**
```

n = 5

```

Valid triangle:
- (3, 4, 5)

**Output**
```

1

```

---

### Example 2

**Input**
```

n = 10

```

Valid triangles:
- (3, 4, 5)
- (6, 8, 10)

**Output**
```

2

```

---

## Algorithm Idea

1. Iterate `a` from `1` to `n`
2. Iterate `b` from `a` to `n`
3. Compute  
```

x = a² + b²

```
4. Check if `x` is a perfect square
5. Let `c = √x`
6. If `c ≤ n`, count the triangle

---

## Pseudo-code

```

count = 0

for a from 1 to n:
for b from a to n:
x = a*a + b*b
c = integer square root of x

```
    if c*c == x and c <= n:
        count++
```

print count

```

---

## Complexity

- Time complexity: **O(n²)**
- Space complexity: **O(1)**

This approach is efficient enough for `n ≤ 10⁴`.

---