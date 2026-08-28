# Problem 264A – Escape from Stones

## Problem Summary

Squirrel Liss starts in an interval `[0, 1]`.

For each stone, the stone falls at the **center of Liss's current interval**. After the stone falls:

- `l` → Liss escapes to the **left**.
- `r` → Liss escapes to the **right**.

The stones are numbered from `1` to `n`.

After all stones have fallen, print their numbers from **left to right**.

---

## Key Observation

If a stone has direction:

- `r`: the new stone appears to the **right** of the previous stones, so `r` stones keep their original order.
- `l`: the new stone appears to the **left** of the previous stones, so `l` stones appear in reverse order.

Therefore:

1. Store all `r` stone numbers in their original order.
2. Store all `l` stone numbers in their original order.
3. Print the `r` stones from first to last.
4. Print the `l` stones from last to first.

---

## Examples

### Example 1

**Input:**

```text
llrlr
```
`r` stones:
```
3 5
```
`l` stones:
```
1 2 4
```
Reverse the `l` stones:
```
4 2 1
```
Final order:
```
3 5 4 2 1
```
**Output:**
```
3
5
4
2
1
```
---

### Example 2

**Input:**
```
rrlll
```
`r` stones:
```
1 2
```
`l` stones:
```
3 4 5
```
Reverse the `l` stones:
```
5 4 3
```
Final order:
```
1 2 5 4 3
```
**Output:**
```
1
2
5
4
3
```
### Example 3

**Input:**
```
lrlrr
```
`r` stones:
```
2 4 5
```
`l` stones:
```
1 3
```
Reverse the `l` stones:
```
3 1
```
Final order:
```
2 4 5 3 1
```
**Output:**
```
2
4
5
3
1
```
---

## Pseudocode

```
Read string s

Create two lists:
    right = empty
    left = empty

For each character s[i]:
    stone = i + 1

    If s[i] is 'r':
        add stone to right
    Else:
        add stone to left

Print all elements of right
from first to last

Print all elements of left
from last to first
```

---

## Complexity

**Time:** `O(n)`

**Space:** `O(n)`

---