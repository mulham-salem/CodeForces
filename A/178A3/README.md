# Problem 178A3 – Educational Game

## Problem Summary

You are given an array of non-negative integers.

In one move, you choose an index `i` with `a[i] > 0`, decrease it by `1`, and increase any element with the **same parity** (`i`, `i+2`, `i+4`, ...) by `1`.

For every prefix length `k` (`1 ≤ k < n`), determine the **minimum number of moves** required to make the first `k` elements equal to zero.

---

## Key Observation

Each unit stored at position `i` must be moved away from the prefix once.

Therefore, every unit contributes **at least one move**.

To minimize the total number of future moves, every unit should always be transferred to the **furthest reachable position** with the same parity, delaying any additional moves until absolutely necessary.

As the array is processed from left to right:

- Add all units that previously arrived at the current position.
- Move every unit at the current position to the furthest valid index.
- Accumulate the number of moves.
- After processing position `i`, the accumulated value is the answer for prefix `i + 1`.

---

## Algorithm

For each position from left to right:

1. Add carried units from previous positions.
2. Add the current value to the total number of moves.
3. Output the current total.
4. Find the furthest reachable index with the same parity.
5. Transfer all current units there.

---

## Pseudocode

```text
read n
read array a

carry = array of zeros
totalMoves = 0

for i = 0 to n - 2
    a[i] += carry[i]

    totalMoves += a[i]
    output totalMoves

    find the furthest reachable index
    having the same parity as i

    carry[furthest] += a[i]
```

---

## Complexity

- **Time Complexity:** `O(n log n)` *(or effectively close to linear, since finding the furthest position is inexpensive for each index)*
- **Space Complexity:** `O(n)`

---