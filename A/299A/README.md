# Problem 299A – Ksusha and Array

## Problem Statement

Given an array of `n` positive integers, find a number **from the array** such that **all array elements are divisible by it**. If no such number exists, print `-1`.

---

## Key Insight

For a number `x` to divide **every** element of the array, `x` must divide the **GCD** of all elements.

The GCD of the whole array is the **largest** number that divides every element. Any valid answer must be a divisor of the GCD. But since the answer must also be **an element of the array**, the simplest check is:

1. Compute `g = gcd(a[1], a[2], ..., a[n])`.
2. If `g` exists in the array → print `g`.
3. Otherwise → print `-1`.

Why does this work? Because if any element `x` divides all numbers, then `x` divides the GCD `g`. Since `x` is in the array and `x | g`, we must have `x ≤ g`. But `g` itself divides every element, and if `g` is in the array, it's automatically a valid answer. If `g` is not in the array, then no element can divide all others.

---

## Examples

### Example 1
```

Input:
3
2 2 4

Output:
2

```

GCD of `{2, 2, 4}` is `2`, and `2` is in the array → answer is `2`.

---

### Example 2
```

Input:
5
2 1 3 1 6

Output:
1

```

GCD of `{2, 1, 3, 1, 6}` is `1`, and `1` is in the array → answer is `1`.

---

### Example 3
```

Input:
3
2 3 5

Output:
-1

```

GCD of `{2, 3, 5}` is `1`, but `1` is not in the array → answer is `-1`.

---

## Pseudocode

```
READ n
READ array a of size n

g = 0
FOR each x in a:
    g = GCD(g, x)
END FOR

FOR each x in a:
    IF x == g:
        PRINT g
        RETURN
    END IF
END FOR

PRINT -1

```

---

## Complexity

- **Time:** `O(n log(max(a)))` — due to GCD computations.
- **Space:** `O(n)` — for storing the array.

---