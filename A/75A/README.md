# Problem 75A – Life Without Zeros

## 🧩 Problem Summary
You are given two positive integers `a` and `b`.

1. Compute:

c = a + b

2. Remove all **zero digits ('0')** from:
- `a`
- `b`
- `c`

3. Check if the equation still holds after removing zeros:

a' + b' == c'

---

## 📥 Input
- Line 1: Integer `a`
- Line 2: Integer `b`

**Constraints:**
- `1 ≤ a, b ≤ 10^9`
- No leading zeros

---

## 📤 Output
- Print `"YES"` if the equation remains correct
- Otherwise, print `"NO"`

---

## 🔍 Examples

### Example 1

Input: 101 102

Process: c = 203 a' = 11 b' = 12 c' = 23

Check: 11 + 12 = 23 ✅

Output: YES

---

### Example 2

Input: 105 106

Process: c = 211 a' = 15 b' = 16 c' = 211

Check: 15 + 16 = 31 ≠ 211 ❌

Output: NO

---

## 💡 Key Idea
Simulate a “world without zeros”:
- Remove all `'0'` digits from each number
- Re-check the validity of the equation

---

## 🧠 Pseudocode

```
function removeZeros(x): 
	convert x to string 
	remove all '0' characters 
	if result is empty: 
		return 0 
	return integer value of result

read a, b 
c = a + b

a' = removeZeros(a) 
b' = removeZeros(b) 
c' = removeZeros(c)

if a' + b' == c': 
	print "YES" 
else: 
	print "NO"
	
```

---