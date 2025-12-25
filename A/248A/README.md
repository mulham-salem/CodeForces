# Problem 248A – Cupboards

## Problem Summary

You are given **n cupboards**.  
Each cupboard has **two doors**:
- a **left door**
- a **right door**

Each door can be in one of two states:
- `0` → closed
- `1` → open

You are allowed to **change the state of any door** (open ↔ close).

---

## Goal

Make:
- **all left doors have the same state**
- **all right doors have the same state**

The left and right sides are handled **independently**.

Your task is to find the **minimum number of door state changes** required.

---

## Key Idea

For each side (left and right):

1. Count how many doors are:
   - open (`1`)
   - closed (`0`)
2. To make all doors equal, you only need to change the **smaller group**
3. Total answer =  
   changes for left doors + changes for right doors

---

## Example

### Input
```

4
1 0
1 1
0 1
1 1

```

Each line represents:
```

[left door] [right door]

```

---

### Left Doors Analysis

Left door values:
```

1, 1, 0, 1

```

- Open: 3
- Closed: 1

Minimum changes needed:
```

min(3, 1) = 1

```

---

### Right Doors Analysis

Right door values:
```

0, 1, 1, 1

```

- Open: 3
- Closed: 1

Minimum changes needed:
```

min(3, 1) = 1

```

---

### Final Answer

```

Total changes = 1 (left) + 1 (right) = 2

```

### Output
```

2

```

---

## Complexity

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## Conclusion

The problem is solved by:
- Treating left and right doors separately
- Counting open vs closed doors
- Changing the smaller group on each side

This guarantees the **minimum number of changes**.

---
