# Problem 30A – Accounting

## Problem Summary
In the kingdom of King Copa, the total income in year **0** is `A`, and the total income in year **n** is `B`.

The king assumes that the income changes every year by the same **integer growth coefficient `X`**.

This leads to the equation:

A · Xⁿ = B

Your task is to find an **integer value of `X`** that satisfies this equation.

### Important Notes
- `A`, `B`, and `X` must all be **integers**.
- `X` can be **positive, negative, or zero**.
- If multiple solutions exist, output **any of them**.
- If no integer solution exists, output:

```

No solution

```

---

## Key Observations

1. The constraints are small:
   - `|A| ≤ 1000`
   - `|B| ≤ 1000`
   - `1 ≤ n ≤ 10`

2. Because `Xⁿ` grows quickly, the possible values of `X` are limited.

3. We can **brute-force all reasonable values of `X`** and check which one satisfies:

```

A * X^n = B

```

4. If such `X` is found, print it immediately.

---

## Special Case

If:

```

A = 0

```

Then the equation becomes:

```

0 * X^n = B

```

Two situations appear:

- If `B ≠ 0` → impossible → `No solution`
- If `B = 0` → any `X` works → print any integer

---

## Example 1

Input
```

2 18 2

```

Equation

```

2 * X^2 = 18

```

Divide by 2:

```

X^2 = 9

```

Possible solutions:

```

X = 3
X = -3

```

One valid output:

```

3

```

---

## Example 2

Input
```

-1 8 3

```

Equation

```

-1 * X^3 = 8

```

So:

```

X^3 = -8

```

Solution:

```

X = -2

```

Output

```

-2

```

---

## Example 3

Input
```

0 0 10

```

Equation

```

0 * X^10 = 0

```

This is true for **any integer `X`**.

Example output:

```

5

```

---

## Example 4

Input
```

1 16 5

```

Equation

```

X^5 = 16

```

But:

```

2^5 = 32
1^5 = 1

```

No integer `X` satisfies the equation.

Output:

```

No solution

```

---

## Algorithm Idea

We simply test possible values of `X` and check whether the equation holds.

---

## Pseudocode

```
read A, B, n

if A == 0
if B == 0
print any integer (e.g., 1)
else
print "No solution"
stop

for X from -1000 to 1000
compute value = X^n

if A * value == B
    print X
    stop

print "No solution"

```

---

## Time Complexity

```

O(R * n)

```

Where:

- `R` is the search range for `X`
- `n ≤ 10`

This is very small, so the solution runs instantly.
