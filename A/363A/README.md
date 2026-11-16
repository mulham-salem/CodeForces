# Problem 363A – Soroban

## 📌 Problem Summary

In Japan, a **Soroban** is an abacus used to represent decimal digits. Each rod represents one digit (0–9).

Each rod consists of **5 beads**:

- **1 go-dama** (leftmost bead, separated by a bar `|`)
  - If shifted **right** (`-O|`), it adds **5**
  - If shifted **left** (`O-|`), it adds **0**
- **4 ichi-damas** (right side of the bar)
  - Each one shifted **left** adds **1**

The value of a digit is:

```

value = (go-dama shifted right ? 5 : 0) + (number of ichi-damas shifted left)

```

The **top rod** represents the **last decimal digit**, going upward toward the first digit.

---

## 🧩 Input

A single integer `n` where `0 ≤ n < 10^9`.

## 🧾 Output

Print the Soroban representation of each digit of `n`, **from the last digit to the first**, one rod per line.

- Use `O` for beads
- Use `-` for empty rod space
- Use `|` for the reckoning bar

---

## 💡 Examples

### Example 1
**Input:**
```

2

```
**Output:**
```

O-|OO-OO

```

### Example 2
**Input:**
```

13

```
**Output:**
```

O-|OOO-O
O-|O-OOO

```

### Example 3
**Input:**
```

720

```
**Output:**
```

O-|-OOOO
O-|OO-OO
-O|OO-OO

```

---

## 🔍 Explanation of the Format

For each digit `d`:

1. If `d >= 5` → go-dama is shifted right → `-O|`
   Else → go-dama is shifted left → `O-|`

2. Let `r = d % 5` (number of ichi-damas shifted left)

3. Print:
   - `r` beads `O`
   - one `-`
   - `4 - r` beads `O`

### Example: digit `7`
- `7 >= 5` → `-O|`
- `r = 7 % 5 = 2`
- Result: `-O|` + `OO` + `-` + `OO` → `-O|OO-OO`

### Example: digit `2`
- `2 < 5` → `O-|`
- `r = 2 % 5 = 2`
- Result: `O-|` + `OO` + `-` + `OO` → `O-|OO-OO`

---

## 🧠 Pseudocode

```

read n

do:
	digit = n mod 10

	if digit >= 5:
		print "-O|"
	else:
		print "O-|"

	r = digit mod 5

	repeat r times:
		print "O"

	print "-"

	repeat (4 - r) times:
		print "O"

	print newline

	n = n / 10

while n > 0

```

---

**Time Complexity:** `O(d)` — We process each digit of the number exactly once, where d is the number of digits.

**Space Complexity:** `O(1)` — We use a constant amount of extra memory, regardless of the number of digits.

---

## ✅ Notes

- The loop is `do-while` so that `n = 0` still prints one rod (`O-|-OOOO`).
- Digits are processed from **least significant to most significant**.
- No leading zeros are printed.
