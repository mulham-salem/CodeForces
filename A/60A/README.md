# Problem 60A – Where Are My Flakes?

## 🧩 Problem Summary

You are given `n` boxes arranged in a row (from `1` to `n`). The cereal flakes are hidden in **exactly one box**, but you don't know which one.

You are also given `m` hints. Each hint restricts the possible location of the flakes.

Your task is to determine:

- The **minimum number of boxes** that could still contain the flakes after applying all hints.
- Or determine that the hints are **contradictory** (no valid box exists).

---

## 📥 Input

- First line: two integers `n` and `m`
  - `n`: number of boxes
  - `m`: number of hints

- Next `m` lines: each line is a hint in one of the forms:
  - `"To the left of i"`
  - `"To the right of i"`

---

## 📤 Output

- Print a single integer:
  - Number of possible boxes that may contain the flakes
  - Or `-1` if the hints are contradictory

---

## 💡 Key Idea

Each hint reduces the range of valid boxes:

- `"To the left of i"` → valid range becomes `[1, i-1]`
- `"To the right of i"` → valid range becomes `[i+1, n]`

We maintain a **current valid range `[L, R]`** and update it based on each hint.

- If at the end `L > R` → no valid box → output `-1`
- Otherwise → answer is `R - L + 1`

---

## 🧪 Examples

### Example 1

Input: 2 1 To the left of 2

Output: 1

---

### Example 2

Input: 3 2 To the right of 1 To the right of 2

Output: 1

---

### Example 3

Input: 3 1 To the left of 3

Output: 2

---

### Example 4 (Contradiction)

Input: 3 2 To the left of 2 To the right of 1

Output: -1

---

## 🧠 Pseudocode

```
initialize L = 1, R = n

for each hint: extract i from hint

if hint is "left":
    R = min(R, i - 1)
else if hint is "right":
    L = max(L, i + 1)

if L > R: 
	print -1 
else: 
	print (R - L + 1)
```
---

## ⏱ Complexity

```
- Time: `O(m)`
- Space: `O(1)`
```

---