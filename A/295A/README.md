# Problem 295A – Greg and Array

## Problem Summary

| Item | Description |
|------|-------------|
| Array | `a[1..n]` of integers |
| Operations | `m` operations, each `(lᵢ, rᵢ, dᵢ)` adds `dᵢ` to `a[lᵢ..rᵢ]` |
| Queries | `k` queries, each `(xᵢ, yᵢ)` applies operations `xᵢ..yᵢ` |
| Goal | Find final array after all queries |

---

## Key Idea

| Technique | Purpose |
|-----------|---------|
| Difference Array #1 | Count how many times each operation is executed |
| Difference Array #2 | Apply weighted operations to the original array |
| Result | Reduces complexity from `O(n·m·k)` to `O(n + m + k)` |

---

## Approach (Pseudocode)

```

read n, m, k
read array a[1..n]

read operations:
for i = 1 to m:
read l[i], r[i], d[i]

Step 1: Count how many times each operation runs

diffOps[1..m+2] = 0

for each query (x, y):
	diffOps[x] += 1
	diffOps[y+1] -= 1

times = 0
for i = 1 to m:
	times += diffOps[i]
	d[i] = d[i] * times      # weight each operation by its frequency

Step 2: Apply weighted operations to array a

diffArray[1..n+2] = 0

for i = 1 to m:
	diffArray[l[i]] += d[i]
	diffArray[r[i]+1] -= d[i]

add = 0
for i = 1 to n:
	add += diffArray[i]
	a[i] += add

print a[1..n]

```

---

## Example 1

**Input:**
```

3 3 3
1 2 3
1 2 1
1 3 2
2 3 4
1 2
1 3
2 3

```

**Step 1 — Count operation executions:**

| Query | Operations Used |
|-------|-----------------|
| (1,2) | 1, 2 |
| (1,3) | 1, 2, 3 |
| (2,3) | 2, 3 |

| Operation | Count | Original `d` | Weighted `d` |
|-----------|-------|--------------|--------------|
| op1 | 2 | 1 | 2 |
| op2 | 3 | 2 | 6 |
| op3 | 2 | 4 | 8 |

**Step 2 — Apply to array `a = [1, 2, 3]`:**

| Operation | Range | Value | Array After |
|-----------|-------|-------|-------------|
| op1 | (1,2) | +2 | `[3, 4, 3]` |
| op2 | (1,3) | +6 | `[9, 10, 9]` |
| op3 | (2,3) | +8 | `[9, 18, 17]` |

**Output:**
```

9 18 17

```

---

## Example 2

**Input:**
```

1 1 1
1
1 1 1
1 1

```

**Explanation:**

| Step | Detail |
|------|--------|
| Array | `a = [1]` |
| Operation | add `1` to index 1 |
| Query | apply operation 1 once |

**Output:**
```

2

```

---

## Example 3

**Input:**
```

4 3 6
1 2 3 4
1 2 1
2 3 2
3 4 4
1 2
1 3
2 3
1 2
1 3
2 3

```

**Step 1 — Operation counts:**

| Operation | Count | Original `d` | Weighted `d` |
|-----------|-------|--------------|--------------|
| op1 | 3 | 1 | 3 |
| op2 | 4 | 2 | 8 |
| op3 | 3 | 4 | 12 |

**Step 2 — Apply to `a = [1, 2, 3, 4]`:**

| Operation | Range | Value | Array After |
|-----------|-------|-------|-------------|
| op1 | (1,2) | +3 | `[4, 5, 3, 4]` |
| op2 | (2,3) | +8 | `[4, 13, 11, 4]` |
| op3 | (3,4) | +12 | `[5, 18, 31, 20]` |

**Output:**
```

5 18 31 20

```

---

## Complexity

| Step | Time | Space |
|------|------|-------|
| Read input | O(n + m + k) | O(n + m) |
| Count operations | O(m + k) | O(m) |
| Apply to array | O(n + m) | O(n) |
| **Total** | **O(n + m + k)** | **O(n + m)** |

---

## Notes

| Note | Detail |
|------|--------|
| Data type | Use `long long` — values can grow up to `10⁵ × 10⁵ × 10⁵` |
| Core trick | Difference array for range updates in `O(1)` per update |
| Category | Offline range updates |

---