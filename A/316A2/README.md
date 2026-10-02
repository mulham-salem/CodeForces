# Problem 316A2 – Special Task

## Problem Summary

You are given a string `s` that represents a hint for a safe code. The safe code:
- Consists only of digits (`0-9`).
- Has **no leading zeroes** (the first character cannot be `0`).
- Has the **same length** as `s`.

Each character in `s` has a meaning:
- `?` → any digit from `0` to `9`.
- `0-9` → that exact digit must appear at that position.
- `A-J` → each letter represents a digit. **Same letters must map to the same digit**, and **different letters must map to different digits**.

The task is to count how many valid safe codes match the given hint.

---

## Examples

### Example 1

**Input:**
```

AJ

```

**Output:**
```

81

```

**Explanation:**
- `A` and `J` are two distinct letters, so they must map to two distinct digits.
- The first character cannot be `0`, so `A` has `9` choices (`1-9`).
- After choosing `A`, `J` has `9` remaining choices (since digits must be distinct).
- Total: `9 × 9 = 81`.

---

### Example 2

**Input:**
```

1?AA

```

**Output:**
```

100

```

**Explanation:**
- `1` is fixed at position 1.
- `?` can be any digit → `10` choices.
- `A` appears twice, so both positions must have the same digit.
- `A` has `10` choices (it can be any digit, including `0`, since it's not the first character).
- Total: `10 × 10 = 100`.

---

## Approach

1. **Count distinct letters** (`A-J`) that appear in the string.
2. **Count `?` characters** (excluding position 0, since the first character has special rules).
3. **Handle the first character separately:**
   - If `s[0] == '?'` → `9` choices (cannot be `0`).
   - If `s[0]` is a letter → that letter has `9` choices (cannot be `0`).
   - If `s[0]` is a digit → no restriction from the first character itself.
4. **Assign digits to letters without repetition:**
   - If the first character is a letter, it already used one choice from `9`, so remaining letters get `9, 8, 7, ...` choices.
   - Otherwise, letters get `10, 9, 8, ...` choices.
5. **Multiply by `10` for each `?`** (except the first character if it's `?`, which was already handled).
6. **Output the result as a big integer** (since the answer can exceed `64-bit` for large inputs).

---

## Pseudocode

```

read string s
n = length(s)

used[10] = false
letters = 0
questions = 0

for i from 0 to n-1:
	c = s[i]
	if c is between 'A' and 'J':
		if not used[c - 'A']:
			used[c - 'A'] = true
			letters = letters + 1
	if i > 0 and c == '?':
		questions = questions + 1

ans = 1
choices = 0

if s[0] is between 'A' and 'J':
	ans = 9
	choices = 9
	
	for i from 1 to letters-1:
		ans = ans * choices
		choices = choices - 1
		
else if s[0] == '?':
	ans = 9
	choices = 10
	for i from 0 to letters-1:
		ans = ans * choices
		choices = choices - 1
		
else:
	choices = 10
	for i from 0 to letters-1:
		ans = ans * choices
		choices = choices - 1

for i from 0 to questions-1:
	ans = ans * 10

print ans

```

---

## Complexity

- **Time:** `O(n)` where `n = |s| ≤ 10^5`.
- **Space:** `O(1)` (only a fixed-size array of 10 booleans).

---

## Notes

- The answer can be very large (up to `10^100000`), so a **big integer** implementation is required in languages like C++.
- Be careful with the first character: it cannot be `0`, which reduces choices for letters or `?` at position 0.
- Letters are only `A-J` (10 letters), so at most 10 distinct letters can appear.

---