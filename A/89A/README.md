# Problem 89A – Robbery

## 🧩 Problem Statement

Joe breaks into a bank vault containing `n` cells arranged in a line, each storing some number of diamonds. However, a security system monitors the vault.

Every minute, the system checks the sum of every pair of adjacent cells:
- (a1 + a2), (a2 + a3), ..., (a[n-1] + a[n])

If any of these sums changes compared to the previous check, the alarm is triggered.

Joe can move diamonds between cells or to/from his pocket, but he is limited to:
- at most `m` operations per minute
- `k` total minutes

Each operation is either:
- moving 1 diamond between cells
- moving 1 diamond to his pocket (steal)
- moving 1 diamond from pocket back to a cell

Joe’s goal is to maximize the number of diamonds he steals while ensuring the security system is never triggered.

---

## 💡 Key Idea

To avoid triggering the alarm, all adjacent sums must remain constant:

a_i + a_{i+1} = S

This forces the array into an alternating structure:

- even indices → same value `x`
- odd indices → same value `y`
- where `x + y = S`

---

## ⚙️ Observations

### 1. If `n = 1`
There are no constraints from adjacency checks, so Joe can take as many diamonds as allowed:
- limited by `m * k`

---

### 2. If `n` is even
The system fully constrains the array, leaving no freedom to steal safely.

Result:
- Answer is `0`

---

### 3. If `n` is odd
There is exactly one degree of freedom:
- Joe can repeatedly reduce all even-indexed cells by 1 (and adjust odd indices accordingly)
- Each such “layer removal” costs a fixed number of operations

He can perform this operation up to:
- limited by available diamonds
- limited by total operations `m * k`

---

## 🧠 Strategy Summary

For odd `n`:
- Identify the minimum value among even-indexed cells
- Determine how many full reduction layers can be performed under operation constraints
- Each layer increases stolen diamonds by 1

---

## 📥 Input

- `n` → number of cells
- `m` → max operations per minute
- `k` → number of minutes
- `a[i]` → diamonds in each cell

Constraints:
- `1 ≤ n ≤ 10^4`
- `1 ≤ m, k ≤ 10^9`
- `0 ≤ a[i] ≤ 10^5`

---

## 📤 Output

Print the maximum number of diamonds Joe can steal.

---

## 📌 Examples

### Example 1

Input: 2 3 1 2 3

Output: 0

Explanation:
- `n` is even → no valid safe stealing strategy.

---

### Example 2

Input: 3 2 2 4 1 3

Output: 2

Explanation:
- `n` is odd → one flexible structure exists
- Joe can perform repeated safe reductions while preserving adjacency sums
- Total steal limited by both constraints and available operations

---

## 🚀 Pseudocode (Solution Outline)
```
read n, m, k 
read array a

if n == 1: return min(a[0], m * k)

if n is even: return 0

S = a[0] + a[1]

let evenCount = (n + 1) / 2

minEven = minimum value among even indices

opsPerLayer = evenCount maxLayersByOps = (m * k) / opsPerLayer

answer = min(minEven, maxLayersByOps)

print answer
```
---

## 🧩 Complexity

- Time: O(n)
- Memory: O(1) extra (besides input array)

---

## 🔥 Summary

The problem reduces to a structural observation:
- Even `n`: fully constrained → no profit
- Odd `n`: one free transformation dimension → repeatable safe reductions

Maximizing the answer becomes a balance between:
- available diamonds
- operation limits
- structural constraints of alternating sums

---