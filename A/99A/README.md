# Problem 99A – Help Far Away Kingdom

## 🧠 Overview
You are given a decimal number as a **string**. Your task is to round it to the nearest integer following special rules defined by the King.

The number can be very large (up to 1000 characters), so you must **avoid using floating-point types** and work directly with strings.

---

## ⚙️ Rules

Let:
- `I` = integer part
- `F` = fractional part

### Case 1: Last digit of `I` is NOT `9`
- If the fractional part is **less than 0.5** → result = `I`
- If the fractional part is **greater than or equal to 0.5** → result = `I + 1`

### Case 2: Last digit of `I` is `9`
- Rounding is **not allowed**
- Output:

GOTO Vasilisa.

---

## 🔍 Key Observations

- You only need:
  - The **last digit** of the integer part
  - The **first digit** of the fractional part
- No need to process the entire fractional value
- No carry handling is required (because we skip cases ending with `9`)

---

## 📥 Input

- A single string in the format:

integer_part.fractional_part

- Length ≤ 1000
- Exactly one dot `.`
- No leading zeros (except `"0"`)

---

## 📤 Output

- Print the rounded integer (without leading zeros), or:

GOTO Vasilisa.

---

## 🧪 Examples

| Input                              | Output                 | Explanation |
|-----------------------------------|------------------------|------------|
| `0.0`                              | `0`                    | Fraction < 0.5 |
| `1.49`                             | `1`                    | Fraction < 0.5 |
| `1.50`                             | `2`                    | Fraction ≥ 0.5 |
| `2.71828182845904523536`           | `3`                    | First fractional digit = 7 |
| `3.14159265358979323846`           | `3`                    | First fractional digit = 1 |
| `12345678901234567890.1`           | `12345678901234567890` | No rounding |
| `123456789123456789.999`           | `GOTO Vasilisa.`       | Ends with 9 |

---

## 🧩 Pseudocode
```
read input string s

split s into: integerPart (before '.') fractionalPart (after '.')

if last digit of integerPart == '9': 
	print "GOTO Vasilisa." 
else: 
	if first digit of fractionalPart >= '5': 
		increase last digit of integerPart by 1 
	print integerPart
```
---

## ⏱ Complexity

- Time: O(n)
- Memory: O(n)

---

## 💡 Notes

- Work entirely with strings
- Avoid floating-point precision issues
- Problem is simple once edge case (`9`) is handled

---