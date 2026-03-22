# Problem 50A – Domino piling

## 🧩 Problem Summary

You are given a rectangular board of size **M × N**. You also have an unlimited number of **2 × 1 dominoes**. Each domino covers exactly two adjacent squares.

Your task is to determine the **maximum number of dominoes** that can be placed on the board such that:
- Each domino covers exactly two squares
- No dominoes overlap
- All dominoes are placed fully inside the board

---

## 💡 Key Idea

Each domino covers **2 squares**, so the problem reduces to:

> How many pairs of squares can we form from the board?

The total number of squares is:

M × N

So the maximum number of dominoes is:

floor((M × N) / 2)

---

## 📥 Input
A single line containing two integers:

M N

- `1 ≤ M ≤ N ≤ 16`

---

## 📤 Output
Print a single integer — the maximum number of dominoes that can be placed.

---

## 🔍 Examples

### Example 1

Input: 2 4

Output: 4

### Example 2

Input: 3 3

Output: 4

---

## 🧠 Explanation

- Each domino uses **2 squares**
- If the total number of squares is **even**, all can be covered
- If **odd**, one square will remain unused

---

## ⚙️ Pseudocode
```
read M, N 
total_squares = M * N 
result = total_squares // 2 
print result
```
---

## 🚀 Complexity
```
- Time Complexity: **O(1)**
- Space Complexity: **O(1)**
```
---

## ✅ Conclusion

The solution is based on a simple mathematical observation:

Maximum dominoes = (M × N) // 2

---