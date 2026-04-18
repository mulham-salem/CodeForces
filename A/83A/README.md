# Problem 83A – Magical Array

## 🧩 Problem Summary
You are given an array of integers. Your task is to count the number of **magical subarrays**.

A subarray is called **magical** if:
> The minimum value equals the maximum value.

### 💡 Key Insight
If `min = max`, then **all elements in the subarray are equal**.

So the problem reduces to:
> Count all subarrays consisting of **identical elements only**.

---

## 📥 Input
- Integer `n` — number of elements `(1 ≤ n ≤ 100000)`
- Array `a₁, a₂, ..., aₙ` `(-10⁹ ≤ aᵢ ≤ 10⁹)`

---

## 📤 Output
- A single integer: number of **magical subarrays**

---

## 🔍 Examples

### Example 1

Input: 4 2 1 1 4

Subarrays with equal elements:

[2], [1], [1], [4], [1,1]

Output:

5

---

### Example 2

Input: 5 -2 -2 -2 0 1

Groups:
- `[-2, -2, -2]` → 6 subarrays
- `[0]` → 1
- `[1]` → 1

Output:

8

---

## ⚡ Approach

Traverse the array and group **consecutive equal elements**.

For each group of length `k`, the number of valid subarrays is:

k * (k + 1) / 2

Accumulate the result for all groups.

---

## 🧠 Pseudocode
```
read n 
read array a

k = 1 
ans = 0

for i from 1 to n-1: 
	if a[i] == a[i-1]: 
		k++ 
	else: 
		ans += k * (k + 1) / 2 
		k = 1

ans += k * (k + 1) / 2

print ans
```
---

## ⏱ Complexity
- Time: **O(n)**
- Space: **O(1)**

---

## ✅ Notes
- Every single element counts as a valid subarray.
- Use 64-bit integer (`long long`) to avoid overflow.

---