# Problem 52A – 123-sequence

## 🧩 Problem Summary
You are given a sequence of integers where each element is either `1`, `2`, or `3`.

Your task is to determine the **minimum number of elements you need to change** so that **all elements in the sequence become equal**.

---

## 💡 Key Idea
To minimize the number of changes:
- Count how many times each number (`1`, `2`, `3`) appears.
- Choose the number with the **highest frequency**.
- Change all other elements to this number.

### ✔️ Why?
Because keeping the most frequent number reduces the total number of replacements.

---

## 🧮 Formula

minimum_changes = n - max(count_of_1, count_of_2, count_of_3)

---

## 🔍 Examples

### Example 1

Input: 5 1 1 2 3 1

Output: 2

**Explanation:**
- Count of `1` = 3  
- Count of `2` = 1  
- Count of `3` = 1  
- Best choice is `1`, so change the other 2 elements.

---

### Example 2

Input: 4 2 2 2 2

Output: 0

**Explanation:**
- All elements are already equal → no changes needed.

---

### Example 3

Input: 6 1 2 3 1 2 3

Output: 4

**Explanation:**
- Each number appears 2 times  
- Keep any one of them → change the other 4 elements

---

## ⚙️ Pseudocode

```
read n

initialize c1 = 0, c2 = 0, c3 = 0

for i from 1 to n: read x if x == 1: c1++ else if x == 2: c2++ else: c3++

max_count = max(c1, c2, c3)

result = n - max_count

print result
```

---

## ⏱️ Complexity
```
- Time Complexity: `O(n)`
- Space Complexity: `O(1)`
```

---

## 🏁 Conclusion
The problem reduces to finding the most frequent number in the sequence.  
By keeping it and changing the rest, you achieve the minimum number of operations.

---