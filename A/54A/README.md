# Problem 54A – Presents

## 🧩 Problem Overview
The Hedgehog will receive presents over the next **N days** under two rules:

- 🎉 On each **holiday**, he **must** receive a present.
- ⏳ He will receive presents **at least every K days**  
  (i.e., the gap between any two presents cannot exceed `K` days).

> ⚠️ Day `0` already has a present (given today), but **it is NOT counted** in the answer.

---

## 📥 Input
- Two integers: `N` and `K`
- A list of integers representing **holiday days** (from `1` to `N`)

---

## 📤 Output
- Print a single integer:  
  👉 the **minimum number of presents** the Hedgehog will receive over the next `N` days

---

## 🧠 Key Idea (Greedy)
We simulate the days from `1` to `N` and track the **last day a present was given**.

At each day:
- If it is a **holiday** → give a present
- Else if we reached the limit (`K` days without a present) → give a present

We only give presents **when necessary** to keep the total minimal.

---

## 🔍 Examples

### Example 1

Input: 5 2 1 3

Output: 3

### Explanation

| Day | Holiday | Action |
|-----|--------|--------|
| 1   | ✅     | 🎁     |
| 2   | ❌     | -      |
| 3   | ✅     | 🎁     |
| 4   | ❌     | -      |
| 5   | ❌     | 🎁 (to satisfy K constraint) |

---

### Example 2

Input: 10 1 3 6 7 8

Output: 10

### Explanation
Since `K = 1`, the Hedgehog must receive a present **every day**.

---

## 🧾 Pseudocode

```
read N, K 
read holiday days

mark all holiday days in a boolean array

last = 0 presents = 0

for i from 1 to N: 
	if i is a holiday: 
		presents++ last = i 
	else if i - last == K: 
		presents++ last = i

print presents
```

---

## ⚡ Complexity

- Time: `O(N)`
- Space: `O(N)`

---

## 🎯 Summary

- Always give presents on holidays
- Ensure no gap exceeds `K` days
- Use a greedy approach to minimize the total number of presents