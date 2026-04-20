# Problem 86A – Reflection

## 🧠 Problem Summary
You are given a range of integers `[l, r]`.

For each number `n`, define its **reflection** `ψ(n)` by replacing every digit `d` with `(9 - d)`.

- Example:
  - `192 → 807`
  - `91 → 08 → 8` (leading zeros are removed)

The **weight** of a number is:

weight(n) = n × ψ(n)

### 🎯 Goal
Find the **maximum weight** among all numbers `n` such that:

l ≤ n ≤ r

---

## 📥 Input

l r

- `1 ≤ l ≤ r ≤ 10^9`

---

## 📤 Output
- A single integer: the **maximum value of `n × ψ(n)`**

---

## 🔍 Examples

### Example 1

Input: 3 7

| n | ψ(n) | weight |
|--|--|--|
| 3 | 6 | 18 |
| 4 | 5 | 20 ✅ |
| 5 | 4 | 20 |
| 6 | 3 | 18 |
| 7 | 2 | 14 |

Output: 20

---

### Example 2

Input: 1 1

- `ψ(1) = 8`
- `weight = 1 × 8 = 8`

Output: 8

---

### Example 3

Input: 8 10

| n | ψ(n) | weight |
|--|--|--|
| 8 | 1 | 8 |
| 9 | 0 | 0 |
| 10 | 89 | 890 ✅ |

Output: 890

---

## 💡 Key Insight

Brute force is impossible because the range can be up to `10^9`.

The maximum value of `n × ψ(n)` occurs at special numbers that balance:
- large `n`
- and large `ψ(n)`

These numbers typically have the form:

a × 10^k − 1

Examples:

9, 19, 29, ..., 99, 199, 299, ..., 999, ...

These candidates:
- end with many `9`s
- produce strong balance between `n` and its reflection

---

## 🚀 Strategy

Instead of checking all numbers:
1. Check the boundaries (`l` and `r`)
2. Generate candidates of the form:

a × 10^k − 1

3. Keep only those within `[l, r]`
4. Compute their weights and take the maximum

---

## 🧩 Pseudo Code
```
function reflect(n): result = 0 multiplier = 1

while n > 0:
    digit = n % 10
    result += (9 - digit) * multiplier
    multiplier *= 10
    n /= 10

return result

read l, r

ans = max(l * reflect(l), r * reflect(r))

for a from 1 to 9: 
	p = 1 
	while true: 
		candidate = a * p - 1
		if candidate > r:
				break
		if candidate >= l:
			ans = max(ans, candidate * reflect(candidate))
		p *= 10

print ans
```

---

## 📌 Complexity

- Time: `O(100)` 
- Space: `O(1)`

---

## 🧠 Takeaway

- Avoid brute force on large ranges
- Look for **patterns in digits**
- Smart candidate generation is the key 🚀

---