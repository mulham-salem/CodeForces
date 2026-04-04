# Problem 66A – Petya and Java

## 🧠 Problem Summary
Given a **positive integer `n`** (up to 100 digits), determine the **smallest data type** that can store it.

Available types (in order):
- `byte`
- `short`
- `int`
- `long`
- `BigInteger` (fallback, no limits but slower)

Each type has a fixed maximum value, and you must choose the **first type that fits `n`**.

---

## 📥 Input
- A single string `n`
- Constraints:
  - `1 ≤ length(n) ≤ 100`
  - No leading zeros
  - Always positive

---

## 📤 Output
Print one of the following:

byte short int long BigInteger

---

## 📊 Data Type Limits

| Type  | Max Value |
|------|----------|
| byte | 127 |
| short | 32767 |
| int | 2147483647 |
| long | 9223372036854775807 |
| BigInteger | unlimited |

---

## 💡 Key Idea

Since `n` can be very large:
- Store it as a **string**
- Compare it with limits using:
  1. **Length comparison**
  2. **Lexicographical comparison** (if lengths are equal)

---

## 🔍 Examples

### Example 1

Input: 127

- Fits in `byte` (≤ 127)

Output: byte

---

### Example 2

Input: 130

- Bigger than `byte`
- Fits in `short`

Output: short

---

### Example 3

Input: 123456789101112131415161718192021222324

- Bigger than `long`
- Requires unlimited storage

Output: BigInteger

---

## ⚙️ Pseudocode

```
function canFit(n, maxValue): 
	if length(n) < length(maxValue): 
		return true 
	if length(n) > length(maxValue): 
		return false 
	return n <= maxValue

read n as string

if canFit(n, "127"): 
	print "byte" 
else if canFit(n, "32767"): 
	print "short" 
else if canFit(n, "2147483647"): 
	print "int" 
else if canFit(n, "9223372036854775807"): 
	print "long" 
else: 
	print "BigInteger"
```
---

## ⚠️ Notes
- Do **not** convert `n` to integer types (it may overflow)
- String comparison works correctly **only after checking length**

---