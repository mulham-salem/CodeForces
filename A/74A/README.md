# Problem 74A – Room Leader

## 🧩 Problem Summary
You are given information about `n` contestants in a Codeforces room.  
Each contestant earns points from:
- Solving problems **A, B, C, D, E**
- Performing hacks:
  - `+100` points for each successful hack
  - `-50` points for each unsuccessful hack

Your task is to determine the **room leader**, i.e., the contestant with the **maximum total score**.

It is guaranteed that there is **exactly one leader** (no ties).

---

## 📥 Input
- First line: integer `n` (1 ≤ n ≤ 50) — number of contestants

- Next `n` lines, each contains:

handle plus minus a b c d e

Where:
- `handle` → contestant name (string)
- `plus` → number of successful hacks
- `minus` → number of unsuccessful hacks
- `a, b, c, d, e` → points for problems A–E  
  - If a problem is not solved → value is `0`

---

## 📤 Output
- Print the **handle (name)** of the contestant with the **highest total score**

---

## 🧮 Score Calculation
For each contestant:

total = a + b + c + d + e + (plus × 100) − (minus × 50)

---

## 🔍 Example 1

Input: 2 Ali 1 0 100 200 0 0 0 Omar 0 1 150 100 0 0 0



Calculation: Ali  = 100 + 200 + (1×100) = 400 Omar = 150 + 100 − (1×50) = 200



Output: Ali

---

## 🔍 Example 2

Input: 2 Sara 2 1 300 400 500 0 0 Lina 1 0 300 300 300 300 0



Calculation: Sara = 1200 + 200 − 50 = 1350 Lina = 1200 + 100 = 1300



Output: Sara

---

## 🧠 Approach (Pseudocode)
```
read n

bestScore = very small number 
bestName = ""

repeat n times: 
	read name, plus, minus, a, b, c, d, e

	total = a + b + c + d + e + (plus × 100) − (minus × 50)

	if total > bestScore:
		bestScore = total
		bestName = name

print bestName
```
---

## ⚡ Key Notes
- Scores can be **negative**, so initialize `bestScore` carefully
- No need to store all contestants — one pass is enough
- Guaranteed **unique maximum**, so no tie handling needed

---