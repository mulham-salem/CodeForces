# Problem 220A – Little Elephant and Problem

## Idea
The array was originally sorted in **non-decreasing order**, but someone may have swapped **at most one pair of elements**.

Instead of trying every possible swap, we compare the given array with its correctly sorted version.

- Copy the array.
- Sort the copy.
- Count how many positions differ between the original array and the sorted one.

### Key Observation
- If the array is already sorted, there are **0** different positions.
- If exactly one swap can sort the array, only the **two swapped positions** will be different.
- If more than two positions differ, one swap is not enough.

Therefore:

- `diff == 0` → **YES**
- `diff == 2` → **YES**
- `diff > 2` → **NO**

---

## Algorithm
1. Read the array.
2. Create a copy of it.
3. Sort the copied array.
4. Count the number of indices where the original and sorted arrays differ.
5. If the number of different positions is at most `2`, print **YES**.
6. Otherwise, print **NO**.

---

## Pseudocode

```text
Read n
Read array a

b = copy of a
Sort b

diff = 0

For i = 0 → n-1
    If a[i] != b[i]
        diff++

If diff <= 2
    Print "YES"
Else
    Print "NO"
```

---

## Correctness
The sorted copy represents the desired final arrangement.

If one swap is enough:
- Either the array is already sorted (`diff = 0`), or
- Exactly two positions contain incorrect values (`diff = 2`).

Any valid swap can only change two positions, so if more than two positions differ, no single swap can make the array sorted.

Thus, the algorithm correctly determines whether the array can be sorted using at most one swap.

---

## Complexity Analysis

- **Time Complexity:** `O(n log n)`
  - Sorting the copied array dominates the running time.

- **Space Complexity:** `O(n)`
  - An additional copy of the array is stored.
  
---
  