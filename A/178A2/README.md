# Problem 178A2 – Educational Game

## Problem Overview

You are given an array `a` of `n` non-negative integers.

For every prefix length `k` (`1 ≤ k < n`), determine the **minimum number of moves** required to make the first `k` elements equal to zero.

In one move:

- Choose an index `i` where `a[i] > 0`
- Choose an integer `t ≥ 0`
- Move one unit from position `i` to position `i + 2*t` (without exceeding the array bounds)

The task is to output the minimum number of moves for every possible prefix.

---

## Key Insight

Instead of simulating every move, the solution processes the array from left to right.

It keeps track of:

- The total number of operations performed so far.
- Delayed contributions from previously processed positions using a helper array (`carry`).

This avoids expensive simulations while correctly counting the required operations.

---

## Algorithm (Pseudo Code)

```text
Initialize total_moves = 0
Initialize carry array with zeros

For each position i from 0 to n-2:
    Add delayed contributions to a[i]
    Add a[i] to total_moves
    Output total_moves

    Find the farthest reachable position from i
    Propagate a[i] to that position using carry
```

---

## Complexity

- **Time Complexity:** `O(n log n)`
- **Space Complexity:** `O(n)`

---

## Example

### Input

```text
4
1 0 1 2
```

### Output

```text
1
1
3
```

### Explanation

- Process the array from left to right.
- At each position, merge any delayed values stored in `carry`.
- Every processed unit contributes one move.
- Its effect is then propagated to the farthest reachable position.

---

## Summary

The solution does **not** simulate every individual move.

Instead, it efficiently counts the required operations by:

- Processing positions in order.
- Accumulating delayed contributions.
- Propagating their effects using the `carry` array.

This produces the minimum number of moves for every prefix within the required time limits.

---