# Problem 64A – Factorial

## 🧩 Problem Summary
Given an integer `n`, compute its factorial.

The factorial of a number `n` is defined as:

n! = 1 × 2 × 3 × ... × n

---

## 📥 Input
- A single integer `n`  
- Constraint: `1 ≤ n ≤ 10`

---

## 📤 Output
- Print the factorial of `n`

---

## 🔍 Examples

| Input | Output |
|------|--------|
| 3    | 6      |
| 5    | 120    |

---

## 💡 Idea
We initialize a variable `factorial` with `1`, then iterate from `1` to `n`, multiplying the current value each time.

---

## 🧠 Pseudocode

```
read n factorial ← 1

for i from 1 to n do factorial ← factorial × i

print factorial
```
---

## ⏱️ Complexity
- Time Complexity: `O(n)`
- Space Complexity: `O(1)`

---

## 📝 Notes
- The constraints are small, so using a simple loop is sufficient.
- No need for advanced techniques like recursion or big integers.

---