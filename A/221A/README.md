# Problem 221A – A Little Elephant and Function

## Problem Overview

You are given an integer `n`.  
A little elephant defines a recursive function `f(x)` that sorts the first `x` elements of a permutation of numbers from `1` to `n`:

- If `x = 1`, stop.
- Otherwise:
  - Call `f(x - 1)`
  - Swap the elements at positions `x-1` and `x`

Your task is **not** to simulate the function.  
Instead, you need to **find a permutation of numbers from 1 to n** such that **after applying the function once**, the permutation becomes sorted in ascending order.

---

## Key Observation

When the function is applied as `f(n)`, it performs the following swaps sequentially:

```

swap(1, 2)
swap(2, 3)
swap(3, 4)
...
swap(n-1, n)

```

This sequence of swaps effectively **rotates the permutation to the left by one position**:

```

Before: [a1, a2, a3, ..., an]
After:  [a2, a3, ..., an, a1]

```

The first element moves to the end, and all others shift one position to the left.

---

## What Is Actually Required?

You must provide a permutation such that **after this left rotation**, the result is:

```

1 2 3 ... n

```

So you need to determine the permutation **before applying the function**.

---

## Reverse Thinking (Core Idea)

If the final sorted array is:

```

1 2 3 ... n

```

Then the array **before the function** must have been:

```

n 1 2 3 ... n-1

```

Because the first element moves to the end during the rotation.

---

## Examples

### Example 1

**Input**
```

1

```

**Output**
```

1

```

Explanation: With only one element, no swaps are needed.

---

### Example 2

**Input**
```

5

```

**Output**
```

5 1 2 3 4

```

After applying the function `f(5)`, the permutation becomes:

```

1 2 3 4 5

```

---

## Pseudocode

```

read n

if n == 1:
print 1
else:
print n
for i from 1 to n-1:
print i

```

---

## Summary

- The function does **not sort** in the usual way; it performs a **left rotation by one**.
- To achieve a sorted array after applying the function, print the permutation **before the rotation**.
- The correct permutation is always:

```

n 1 2 3 ... n-1

```