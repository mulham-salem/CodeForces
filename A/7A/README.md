# Problem 7A – Kalevitch and Chess

## 🧠 Problem Summary

You are given an 8×8 chessboard consisting of characters:

- `W` — white square  
- `B` — black square  

Initially, the board is completely white.

You are allowed to perform the following operation any number of times:

- Paint an entire **row** black  
- OR paint an entire **column** black  

Once a square becomes black, it remains black.

Your task is to determine the **minimum number of strokes** (rows + columns) required to obtain the given board configuration.

It is guaranteed that the configuration is achievable.

---

## 🔎 Key Observation

A square can only become black if:

- Its row was painted  
- OR its column was painted  

Therefore:

- If a row consists entirely of `B`, it must have been painted.
- If a column consists entirely of `B`, it must have been painted.

However, there is one important edge case:

> If **all 8 rows** are completely black, then the board is fully black.  
> In this case, the minimum number of strokes is **8**, not 16.

Why?  
Because painting 8 rows is enough — we don’t need to count columns again.

---

## ✅ Strategy

1. Count how many rows contain only `B`
2. Count how many columns contain only `B`
3. If all 8 rows are black → answer = 8  
4. Otherwise → answer = rows + columns  

---

## 📌 Example 1

Input:
```

WWWBWWBW
BBBBBBBB
WWWBWWBW
WWWBWWBW
WWWBWWBW
WWWBWWBW
WWWBWWBW
WWWBWWBW

```

- Full black rows = 1  
- Full black columns = 2  

Minimum strokes = 1 + 2 = **3**

---

## 📌 Example 2

Input:
```

WWWWWWWW
BBBBBBBB
WWWWWWWW
WWWWWWWW
WWWWWWWW
WWWWWWWW
WWWWWWWW
WWWWWWWW

```

- Full black rows = 1  
- Full black columns = 0  

Minimum strokes = **1**

---

## 📌 Example 3 (All Black Board)

```

BBBBBBBB
BBBBBBBB
BBBBBBBB
BBBBBBBB
BBBBBBBB
BBBBBBBB
BBBBBBBB
BBBBBBBB

```

- Full black rows = 8  
- Full black columns = 8  

Correct answer = **8**

---

## 💡 Pseudocode

```

read 8x8 board

rowCount = 0
colCount = 0

for each row i from 0 to 7:
if every cell in row i is 'B':
rowCount++

for each column j from 0 to 7:
if every cell in column j is 'B':
colCount++

if rowCount == 8:
print 8
else:
print rowCount + colCount

```

---

## ⏱ Complexity

- Time Complexity: O(8 × 8) → constant
- Space Complexity: O(1)

---

## 🎯 Final Insight

The board is constructed using complete row or column strokes.  
We only need to detect which rows and columns must have been painted, while carefully handling the fully-black board case.
