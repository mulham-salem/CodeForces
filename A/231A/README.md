# Problem 231A – Team

## Problem Summary

A group of friends wants to solve programming problems together.

For each problem, **three friends** discuss whether they are sure about the solution or not.

Each friend gives:
- `1` → sure about the solution
- `0` → not sure

A problem will be solved **only if at least two friends are sure**.

---

## Goal

Given several problems, determine **how many problems will be solved** by the team.

---

## Input Description

- The first line contains an integer `n` — the number of problems.
- The next `n` lines each contain **three integers** (`0` or `1`), representing the opinions of the three friends.

---

## Key Rule

For each problem:
- Count how many `1`s are in the line
- If the count is **≥ 2**, the problem is solved

---

## Example

### Input
```

3
1 1 0
1 1 1
1 0 0

```

---

### Step-by-Step Explanation

#### Problem 1
```

1 1 0

```
- Sure friends = 2  
✅ Solved

---

#### Problem 2
```

1 1 1

```
- Sure friends = 3  
✅ Solved

---

#### Problem 3
```

1 0 0

```
- Sure friends = 1  
❌ Not solved

---

### Final Result

```

Solved problems = 2

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

The solution is straightforward:
- For each problem, count how many team members are sure
- If at least two are sure, count the problem as solved

This approach guarantees correctness with minimal computation.

---
