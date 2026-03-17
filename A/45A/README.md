# Problem 45A – Codecraft III

## 🧩 Problem Summary
You are given the current month and an integer `k` representing how many months will pass.  
Your task is to determine the name of the month after `k` months.

The months follow the standard order:
January → February → March → April → May → June → July → August → September → October → November → December

The sequence is cyclic, meaning after December comes January again.

---

## 💡 Idea
Treat the months as a circular list of size 12.

1. Find the index of the current month.
2. Move forward by `k` steps.
3. Use modulo `12` to wrap around the year.

---

## 🔄 Examples

### Example 1

**Input**

```
November
3
```

**Explanation**
- November → December (+1)
- January (+2)
- February (+3)

**Output**

```
February
```

---

### Example 2

**Input**

```
May 24
```

**Explanation**
- 24 months = 2 full cycles (12 + 12)
- You end up in the same month

**Output**

```
May
```

---

## 🧠 Pseudocode

```
months = [January, February, ..., December]

read current_month read k

find index of current_month in months

new_index = (index + k) mod 12

print months[new_index]
```

---

## ⏱ Complexity

```
- Time: O(12) ≈ O(1)
- Memory: O(1)
```
---

## 📌 Notes
- The modulo operation ensures correct cycling through months.
- No need for complex data structures; a simple array/vector is enough.