# Problem 100A – Carpeting the Room

## 🧩 Problem Statement

You are given:
- A square room of size **n × n**
- **k** square carpets of size **n1 × n1**

Carpets:
- ❌ Cannot be rotated  
- ✅ Can overlap  

👉 Determine if the room can be fully covered.

---

## 📥 Input

n k n1

- n  → room size
- k  → number of carpets
- n1 → carpet size

---

## 📤 Output

YES / NO

- YES → full coverage possible
- NO  → otherwise

---

## 💡 Key Idea

We compute how many carpets are needed per dimension:

tiles_per_side = ceil(n / n1)

Total required carpets:

required = tiles_per_side × tiles_per_side

---

## ⚙️ Pseudocode
```
read n, k, n1

tiles_per_side = ceil(n / n1) 
required = tiles_per_side * tiles_per_side

if k >= required: 
	print "YES" 
else: 
	print "NO"
```
---

## 🧪 Examples

### Example 1

Input: 10 4 6

Output: YES



Explanation: ceil(10 / 6) = 2 required = 2 × 2 = 4 k = 4 → OK

---

### Example 2

Input: 10 2 5

Output: NO



Explanation: ceil(10 / 5) = 2 required = 4 k = 2 → NOT enough

---

## 🚀 Complexity

Time:  O(1) Space: O(1)

---

## 📌 Trick Used

ceil(n / m) = (n + m - 1) / m

Used to avoid floating-point operations in competitive programming.

---