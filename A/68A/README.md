# Problem 68A – Irrational problem

## 🧠 Overview
You are given four **distinct integers** `p1, p2, p3, p4` and a range `[a, b]`.

Define a function:

f(x) = x % p1 % p2 % p3 % p4

However, the order of applying the modulo operations is **unknown**.  
All **24 permutations (4!)** of `(p1, p2, p3, p4)` are equally possible.

---

## 🎯 Goal
For each integer `x` in `[a, b]`, count how many permutations satisfy:

f(x) = x

If **at least 7 permutations** keep `x` unchanged, then `x` is considered valid.

👉 Output the total number of such valid `x`.

---

## 💡 Key Idea
- The order of modulo operations affects the result.
- If at any step `x >= p[i]`, the value may decrease.
- We simulate all permutations and count how many preserve `x`.

---

## 📥 Input

p1 p2 p3 p4 a b

- `p1, p2, p3, p4` → distinct integers  
- `a, b` → range limits  

**Constraints:**
- `1 ≤ pi ≤ 1000`
- `0 ≤ a ≤ b ≤ 31415`

---

## 📤 Output
A single integer — the number of values `x ∈ [a, b]` such that  
at least **7 permutations** satisfy `f(x) = x`.

---

## 🔍 Examples

### Example 1

Input: 2 7 1 8 2 8

Output: 0

**Explanation:**
- Since one of the values is `1`, any permutation will eventually apply `% 1`
- `x % 1 = 0`, so `f(x)` can never equal `x` (for x ≥ 2)

---

### Example 2

Input: 20 30 40 50 0 100

Output: 20

**Explanation:**
- For all `x < 20`, we have:

x % pi = x

- So all 24 permutations preserve `x`
- Valid values: `0 → 19` → total = **20**

---

### Example 3

Input: 31 41 59 26 17 43

Output: 9

**Explanation:**
- Some values remain unchanged under enough permutations
- Others get reduced during modulo operations
- Only 9 values satisfy the condition

---

## 🧪 Pseudocode

```
read p1, p2, p3, p4, a, b

generate all permutations of [p1, p2, p3, p4]

answer = 0

for x from a to b: count = 0

for each permutation perm:
    cur = x

    for i from 0 to 3:
        cur = cur % perm[i]

    if cur == x:
        count++

if count >= 7:
    answer++

print answer
```

---

## ⏱ Complexity
- Permutations: `24`
- For each `x`: try all permutations
- Total ≈ `O((b - a) * 24 * 4)` → efficient for given constraints

---

## 🚀 Notes
- A brute-force approach is sufficient due to small limits
- Understanding how modulo affects values is key to solving the problem efficiently

---