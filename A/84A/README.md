# Problem 84A – Toy Army

## 🧠 Overview
Two players, **Valera** and **Arcady**, each start with `n` soldiers (`n` is even).  
The game lasts exactly **3 turns**:

1. Valera
2. Arcady
3. Valera

In each turn:
- Every alive soldier shoots **one enemy soldier**
- All shots happen **simultaneously**
- Every shot **kills** its target
- Multiple soldiers can target the same enemy (but it still counts as one kill)
- Dead soldiers cannot act in future turns

---

## 🎯 Objective
Compute the **maximum total number of soldiers killed** after the 3 turns.

---

## 📥 Input
- A single integer `n`  
- Constraints:
  - `2 ≤ n ≤ 10^8`
  - `n` is **even**

---

## 📤 Output
- A single integer → maximum number of killed soldiers

---

## 💡 Key Insight
To maximize total kills:
- Avoid wasting shots on the same target
- Balance the number of kills across turns
- Ensure enough soldiers remain alive for future turns

The optimal strategy leads to the formula:

max kills = 3n / 2

---

## 🧪 Examples

### Example 1
**Input**
```
2
```
**Output**
```
3
```

**Explanation**
- Turn 1: Valera kills 1
- Turn 2: Arcady kills 1
- Turn 3: Valera kills 1  
➡️ Total = 3

---

### Example 2
**Input**
```
4
```
**Output**
```
6
```
---

## ⚙️ Pseudocode
```
read n 
result = (3 * n) / 2 
print result
```

---

## ⏱️ Complexity
- Time: `O(1)`
- Memory: `O(1)`

---