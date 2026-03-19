# Problem 47A – Triangular numbers

## 🧩 Problem Summary

A **triangular number** is a number that can be written as the sum of the first `k` natural numbers:

1 + 2 + 3 + ... + k

Given an integer `n` (1 ≤ n ≤ 500), determine whether it is a triangular number.

---

## 📥 Input

- A single integer `n`

## 📤 Output

- Print `YES` if `n` is a triangular number  
- Otherwise, print `NO`

---

## 🔍 Examples

### Example 1

Input: 3

Output: YES

Explanation:

1 + 2 = 3

---

### Example 2

Input: 2

Output: NO

Explanation:  
No sequence starting from 1 sums to 2.

---

### Example 3

Input: 6

Output: YES

Explanation:

1 + 2 + 3 = 6

---

## 💡 Idea
Keep adding consecutive numbers starting from 1:
- If the sum becomes equal to `n` → it is triangular
- If the sum exceeds `n` → it is not

---

## 🧠 Pseudocode

```
read n sum = 0

for i from 1 to n: sum = sum + i

if sum == n:
    print "YES"
    stop

if sum > n:
    break

print "NO"
```

---

## ⏱ Complexity

```
- Time: O(n)
- Space: O(1)
```

---