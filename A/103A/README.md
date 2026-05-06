# Problem 103A – Testing Pants for Sadness

## 🧠 Problem Summary
You are given a test with `n` questions.  
Each question `i` has `a[i]` possible answers, and **exactly one is correct**.

- Questions must be answered **in order (1 → n)**.
- Each selection counts as **one click**.
- If you select a **wrong answer**, the test resets to question 1.
- You **remember** previous wrong answers and never repeat them.

👉 Find the **minimum number of clicks in the worst case**.

---

## 📥 Input
- Integer `n` — number of questions  
- Array `a` of size `n`  
  - `a[i]` = number of answer choices for question `i`

---

## 📤 Output
- A single integer: **minimum number of clicks (worst case)**

---

## 💡 Key Idea

For each question:
- You may try `(a[i] - 1)` wrong answers before finding the correct one.
- Each wrong attempt forces you to **restart from the beginning**.
- Reaching question `i` requires solving **`i + 1` questions**.

👉 So each wrong attempt at question `i` costs `(i + 1)` clicks.

---

## 🧮 Formula Insight

For each question `i` (0-based):

Clicks contributed by question i = (a[i] - 1) × (i + 1) + 1

- `(a[i] - 1)` → number of wrong attempts  
- `(i + 1)` → cost of restarting and reaching question `i` again  
- `+1` → final correct attempt  

---

## 🧪 Examples

### Example 1

Input: 2 1 1

Output: 2

Explanation:
- Each question has only one choice → always correct  
- Total clicks = 2

---

### Example 2

Input: 2 2 2

Output: 5

Explanation:
- Q1: 1 wrong + 1 correct → 2 clicks  
- Q2: 1 wrong (cost 2 clicks) + 1 correct → 3 clicks  
- Total = 5

---

### Example 3

Input: 1 10

Output: 10

Explanation:
- 9 wrong + 1 correct → 10 clicks

---

## 🧾 Pseudocode
```
read n read array a

ans = 0

for i from 0 to n-1: 
	ans += (a[i] - 1) * (i + 1) + 1

print ans
```
---

## 🚀 Complexity

- Time: `O(n)`
- Space: `O(1)` (excluding input)

---

## 🎯 Summary

- Each wrong answer causes a full restart
- Earlier questions are repeated many times
- Total clicks can be computed directly using a formula

---