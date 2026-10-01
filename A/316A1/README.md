# Problem 316A1 – Special Task

## Problem Summary

You are given a string `s` representing a safe code hint. The code consists of digits with no leading zero. Each character in `s` gives a rule:

- `?` → any digit from `0` to `9`
- digit (`0`–`9`) → that exact digit must be placed there
- letter (`A`–`J`) → all occurrences of the same letter must be the same digit, and different letters must have different digits.

The first character of the safe code cannot be `0`.

Count how many valid safe codes match the hint.

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

- `A` is at position 1 and cannot be `0` → 9 choices.
- `J` is at position 2 and must be different from `A` → 9 choices (including `0`).
- Total = `9 × 9 = 81`.

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

- First character is fixed to `1`.
- `?` can be any digit → 10 choices.
- `A` appears twice and must be the same digit, but it is not the first character, so it can be any digit → 10 choices.
- Total = `10 × 10 = 100`.

---

## Key Observations

1. Fixed digits in the string do not affect the count except that they occupy positions.
2. `?` positions always multiply the answer by `10`, unless it is the first character, in which case it multiplies by `9` (since leading zero is not allowed).
3. Letters `A`–`J` are distinct from each other and must be assigned different digits.
4. If the first character is a letter, that letter cannot be `0`, so it has `9` choices instead of `10`.
5. Remaining distinct letters get `9, 8, 7, ...` choices depending on how many letters exist and whether the first letter is among them.

---

## Pseudocode

```

read string s
n = length(s)

letters_set = empty set
for each character c in s:
	if c is between 'A' and 'J':
		add c to letters_set

letters_count = size of letters_set
answer = 1

// Handle first character
if s[0] == '?':
	answer = answer * 9
else if s[0] is a letter:
	answer = answer * 9

// Handle remaining '?' characters
for i from 1 to n-1:
	if s[i] == '?':
		answer = answer * 10

	// Assign digits to distinct letters
if s[0] is a letter:
	// First letter already used 9 choices
	remaining_choices = 9
	
	for i from 1 to letters_count - 1:
		answer = answer * remaining_choices
		remaining_choices = remaining_choices - 1
	
else:
	// No letter at first position
	remaining_choices = 10
	for i from 0 to letters_count - 1:
		answer = answer * remaining_choices
		remaining_choices = remaining_choices - 1

print answer

```

---

## Complexity

- **Time:** `O(n)` where `n = |s|`
- **Space:** `O(1)` (only a fixed-size set for letters `A`–`J`)

---