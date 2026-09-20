# Problem 300A – Array

## 📌 Problem Statement

Vitaly has an array of `n` **distinct** integers. He wants to divide it into **three non-empty sets** such that:

| Set | Condition |
|-----|-----------|
| **Set 1** | Product of all elements **< 0** |
| **Set 2** | Product of all elements **> 0** |
| **Set 3** | Product of all elements **= 0** |

Every element must belong to **exactly one** set.
It is guaranteed that at least one valid solution exists.

---

## 💡 Key Idea

- **Set 1** needs an **odd** number of negatives → put **one negative** in it.
- **Set 3** needs at least one zero → put **all zeros** in it.
- **Set 2** gets everything else → its negatives count must be **even** so the product is positive.

If the remaining negatives (after taking one for Set 1) are **odd**, move one extra negative to **Set 3** (the zero already inside keeps its product = 0). This makes Set 2's negative count even.

---

## 🧠 Pseudocode

```

read n
read array a

neg  = all negative numbers in a
pos  = all positive numbers in a
zero = all zeros in a

set1 = [ neg[0] ]          // one negative
set3 = [ all zeros ]

idx = 1                    // next unused negative index

if (neg.size() - 1) is odd:
set3.push( neg[idx] )
idx = idx + 1

set2 = neg[idx .. end] + pos   // remaining negatives + all positives

print set1
print set2
print set3

```

---

## 🔍 Examples

### Example 1
**Input:**
```

3
-1 2 0

```
**Output:**
```

1 -1
1 2
1 0

```
- Set 1: `-1` → product = **-1 < 0** ✓
- Set 2: `2` → product = **2 > 0** ✓
- Set 3: `0` → product = **0** ✓

---

### Example 2
**Input:**
```

4
-1 -2 -3 0

```
**Output:**
```

1 -1
2 -3 -2
1 0

```
- Set 1: `-1` → product = **-1 < 0** ✓
- Set 2: `-3 × -2 = 6 > 0` ✓
- Set 3: `0` → product = **0** ✓

---

### Example 3 (even negatives case)
**Input:**
```

4
-1 -2 3 0

```
**Output:**
```

1 -1
1 3
2 0 -2

```
- Set 1: `-1` → product = **-1 < 0** ✓
- Set 2: `3` → product = **3 > 0** ✓
- Set 3: `0 × -2 = 0` ✓

Here, `neg.size() - 1 = 1` (odd), so we moved `-2` to Set 3.

---

## ⏱ Complexity

- **Time:** `O(n)`
- **Space:** `O(n)`

---

## ✅ Constraints
- `3 ≤ n ≤ 100`
- `|a[i]| ≤ 10^3`
- All elements are **distinct**

---