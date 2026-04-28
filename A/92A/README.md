# Problem 92A – Chips

## 🧩 Problem Summary
There are `n` walruses sitting in a circle, numbered from `1` to `n`.  
A presenter has `m` chips and distributes them in order:

- Walrus `1` gets `1` chip  
- Walrus `2` gets `2` chips  
- ...  
- Walrus `n` gets `n` chips  
- Then the process repeats from walrus `1`

If the presenter cannot give the required number of chips to the current walrus, the process stops.

## 🎯 Goal
Determine how many chips remain with the presenter at the end.

---

## 🔁 Process Explanation
The chips are distributed in a repeating sequence:

1 → 2 → 3 → ... → n → 1 → 2 → ...

At each step:
- If `m >= current_required`, subtract it from `m`
- Otherwise, stop and return `m`

---

## 📥 Input
- Two integers:

n m

### Constraints
- `1 ≤ n ≤ 50`
- `1 ≤ m ≤ 10000`

---

## 📤 Output
- A single integer — the number of remaining chips

---

## 📌 Examples

### Example 1

Input: 4 11

Output: 0

**Explanation:**

11 - 1 = 10 10 - 2 = 8 8  - 3 = 5 5  - 4 = 1 1  - 1 = 0 Next required = 2 → not enough → stop

---

### Example 2

Input: 3 8

Output: 1

**Explanation:**

8 - 1 = 7 7 - 2 = 5 5 - 3 = 2 2 - 1 = 1 Next required = 2 → not enough → stop

---

### Example 3

Input: 17 107

Output: 2

---

## 🧠 Key Idea
Simulate the process using a loop that cycles from `1` to `n`.  
Stop when the remaining chips are less than the required amount.

---

## 📝 Pseudocode
```
read n, m i = 1

while true: if m < i: break

m = m - i
i = i + 1

if i > n:
    i = 1

print m
```

---