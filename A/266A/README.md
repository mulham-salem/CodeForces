# Problem 266A – Stones on the Table

## Requirement

You are given:
- An integer `n` — the number of stones.
- A string `s` of length `n` representing the colors of the stones.

Stones are placed in a row.

Your task is to find the **minimum number of stones to remove**
so that **no two adjacent stones have the same color**.

---

## Input

- Integer `n`
- String `s` (length `n`)

---

## Output

- One integer — number of stones to remove

---

## Examples

### Example 1

**Input**
```

3
RRG

```

**Output**
```

1

```

**Explanation**
```

R R G
↑ ↑
Two adjacent stones have the same color.
Remove one of them → only 1 removal needed.

```

---

### Example 2

**Input**
```

5
RRRRR

```

**Output**
```

4

```

**Explanation**
```

All stones have the same color.
To make all adjacent stones different,
only one stone can remain.

Removed stones = 5 - 1 = 4

```

---

## Solution Idea

1. Traverse the stones from left to right.
2. Compare each stone with the previous one.
3. If two adjacent stones have the **same color**:
   - One of them must be removed.
4. Count how many times this situation occurs.

---

## Important Notes

- Only **adjacent stones** matter.
- It does not matter **which stone** you remove, only the count.
- The order of stones does not change after removals.

---

## Complexity

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## Key Insight

Each time two neighboring stones have the same color,
exactly **one removal** is required.
So the answer is the number of equal adjacent pairs.