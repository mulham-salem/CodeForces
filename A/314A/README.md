# Problem 314A – Sereja and Contest

## Problem Summary

We have `n` participants with ratings `a1, a2, ..., an`.

For each participant at position `i`, a rating change `di` is calculated based on the current table.

A participant is removed if `di < k`.

The table is **dynamic**:
- After removing someone, the table shrinks and positions shift.
- We always remove the participant with the **best (smallest) original position** among those currently having `di < k`.
- We repeat until no one satisfies `di < k`.

We must output the **original indices** of removed participants in removal order.

---

## Algorithm

1. Read `n`, `k`, and array `a`.
2. Initialize:
   - `d = 0` (accumulated sum)
   - `j = 0` (number of kept participants so far)
3. For each `i` from `0` to `n-1`:
   - Compute `t = j * (n - i - 1) * a[i]`
   - If `d - t < k`:
     - Output `i + 1` (1-based original index)
     - Participant is removed (do **not** update `d` or `j`)
   - Else:
     - `d += j * a[i]`
     - `j++` (participant is kept)
4. End.

---

## Example 1

**Input:**
```

5 0
5 3 4 1 2

```

**Output:**
```

2
3
4

```

**Explanation:**
- Participant 2 is removed first.
- Table becomes `[5, 4, 1, 2]`, then participant 3 (originally) is removed.
- Table becomes `[5, 1, 2]`, then participant 4 (originally) is removed.
- No more removals.

---

## Example 2

**Input:**
```

10 -10
5 5 1 7 5 1 2 4 9 2

```

**Output:**
```

2
4
5
7
8
9

```

---

## Complexity

- **Time:** O(n) — single pass
- **Space:** O(n) — for storing ratings

---

## Notes

- `k` is non-positive (`-1e9 ≤ k ≤ 0`), so `di < k` means `di` must be sufficiently negative.
- Use 64-bit integers (`long long`) because values can be large.
- The solution avoids explicit simulation by maintaining a cumulative sum and a kept-count.

---