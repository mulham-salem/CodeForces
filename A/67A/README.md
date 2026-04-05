# Problem 67A – Partial Teacher

## 🧩 Problem Summary
A teacher gives toffees to `n` students standing in a queue based on their relative marks.

Each adjacent pair of students is compared using a string `s` of length `n-1`:
- `'L'` → left student has higher marks
- `'R'` → right student has higher marks
- `'='` → both have equal marks

### 🎯 Goal
Assign toffees to each student such that:
- Every student gets **at least 1 toffee**
- All constraints from `s` are satisfied
- The **total number of toffees is minimized**

---

## 📥 Input
- Integer `n` — number of students (2 ≤ n ≤ 1000)
- String `s` of length `n-1`

---

## 📤 Output
- `n` integers representing the number of toffees given to each student

---

## 🧪 Examples

### Example 1

Input: 5 LRLR

Output: 2 1 2 1 2

**Explanation:**
- 1 > 2 → 2 > 1  
- 2 < 3 → 1 < 2  
- 3 > 4 → 2 > 1  
- 4 < 5 → 1 < 2  

---

### Example 2

Input: 5 =RRR

Output: 1 1 2 3 4

**Explanation:**
- 1 = 2 → same toffees  
- Increasing sequence due to `'R'` relations  

---

## 💡 Approach (Greedy)

We use a **two-pass greedy strategy**:

1. **Left → Right pass**
   - Handle `'R'` and `'='` relations
2. **Right → Left pass**
   - Handle `'L'` and `'='` relations

This ensures all constraints are satisfied while keeping the total minimal.

---

## 🧠 Pseudocode

```
Input n
Input string s

Create array candies of size n
Initialize all values to 1

// Left to Right
for i from 0 to n-2:
    if s[i] == 'R':
        candies[i+1] = candies[i] + 1
    else if s[i] == '=':
        candies[i+1] = candies[i]

// Right to Left
for i from n-2 down to 0:
    if s[i] == 'L':
        candies[i] = max(candies[i], candies[i+1] + 1)
    else if s[i] == '=':
        candies[i] = max(candies[i], candies[i+1])

Output candies
```

---

## ⚡ Complexity

Time: O(n)

Space: O(n)



---

## 🚀 Notes

Each student starts with 1 toffee

Use max() to avoid breaking previous constraints

Two passes are necessary because constraints depend on both directions

---