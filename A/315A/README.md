# Problem 315A – Sereja and Bottles

## Problem Description

Sereja and his friends went on a picnic with `n` soda bottles. Each bottle has a brand and can be used to open bottles of another (or the same) brand. A bottle can be used to open multiple other bottles, and it doesn't matter if the bottle used for opening is already opened or still closed.  

Your task is to determine **how many bottles cannot be opened by any other bottle**.

### Input

- First line contains integer `n` (1 ≤ n ≤ 100) — number of bottles.
- Next `n` lines each contain two integers `ai` and `bi` (1 ≤ ai, bi ≤ 1000):
  - `ai` — brand of the i-th bottle.
  - `bi` — brand that this bottle can open.

### Output

- Print a single integer — number of bottles that cannot be opened by any other bottle.

---

## Examples

### Example 1

**Input**
```

4
1 1
2 2
3 3
4 4

```

**Output**
```

4

```

**Explanation**

- Each bottle can only open bottles of its own brand.  
- There is **no other bottle** of the same brand to open it.  
- Therefore, all 4 bottles cannot be opened.

---

### Example 2

**Input**
```

4
1 2
2 3
3 4
4 1

```

**Output**
```

0

```

**Explanation**

- Each bottle can open a bottle of another brand.  
- All bottles have at least one other bottle that can open them.  
- Therefore, **all bottles can be opened**, result is 0.

---

## Solution Idea (Pseudocode)

```

Read n
Read arrays a[1..n] and b[1..n]

# Count how many times each brand appears in b[]

Create a map cnt

for i from 1 to n:
cnt[b[i]] += 1

ans = 0
for i from 1 to n:
if cnt[a[i]] == 0:
# No bottle can open this one
ans += 1
else if cnt[a[i]] == 1 and a[i] == b[i]:
# The only bottle that could open it is itself
ans += 1

Print ans

```

### Notes

- A bottle **cannot open itself**.
- The key is to check for each bottle if **any other bottle** can open its brand.
- Counting the occurrences of brands in `b[]` helps determine this efficiently.

---