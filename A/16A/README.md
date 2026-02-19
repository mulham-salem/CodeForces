# Problem 16A – Flag

## 📝 Problem Summary

You are given a flag represented as an **n × m grid**.  
Each cell contains a digit from `0` to `9` representing a color.

The flag follows a new ISO standard if:

1. **Each row is uniform** → all cells in a row must have the same color.
2. **Adjacent rows must have different colors** → row `i` must not have the same color as row `i-1`.

If both conditions are satisfied, print `YES`. Otherwise, print `NO`.

---

## 📥 Input

- Two integers `n` and `m` (1 ≤ n, m ≤ 100)
- `n` lines follow, each containing `m` digits (`0–9`)

---

## 📤 Output

- `YES` if the flag satisfies the standard  
- `NO` otherwise

---

## ✅ Valid Example

### Input
```

3 3
000
111
222

```

### Explanation
- Each row has only one color ✔
- Adjacent rows have different colors ✔

### Output
```

YES

```

---

## ❌ Invalid Example (Adjacent Rows Same)

### Input
```

3 3
000
000
111

```

### Explanation
- Row 1 and Row 2 have the same color ❌

### Output
```

NO

```

---

## ❌ Invalid Example (Row Not Uniform)

### Input
```

3 3
000
111
002

```

### Explanation
- Third row contains more than one color ❌

### Output
```

NO

```

---

## 🧠 Key Observations

- Only **adjacent rows** need to be different.
- It is allowed for non-adjacent rows to have the same color.
- Time complexity is **O(n × m)**.

---

## 🔎 Pseudocode

```

read n, m
read grid

for each row i from 0 to n-1:

# Check if row is uniform
for each column j from 1 to m-1:
    if grid[i][j] != grid[i][0]:
        print "NO"
        stop

# Check adjacent row color difference
if i > 0 and grid[i][0] == grid[i-1][0]:
    print "NO"
    stop

print "YES"

```
