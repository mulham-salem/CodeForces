# Problem 293A – Weird Game

## Problem Summary

Two players, **Yaroslav (First)** and **Andrey (Second)**, each have a binary string of length `2n`. They take turns (First starts) picking an index from `1` to `2n` that hasn't been picked before. When a player picks index `i`, they write down the character at position `i` from **their own** string.

After all `2n` moves, each player arranges their collected characters into a binary number (leading zeros allowed). The player with the **larger number wins**, or it's a **Draw** if equal. Both play optimally.

---

## Key Insight

Each index `i` falls into one of four categories:

| Category     | `s[i]` | `t[i]` | Meaning                                  |
|--------------|--------|--------|------------------------------------------|
| `both`       | `1`    | `1`    | Either player who picks it gains a `1`   |
| `firstOnly`  | `1`    | `0`    | Only First gains a `1` here              |
| `secondOnly` | `0`    | `1`    | Only Second gains a `1` here             |
| `none`       | `0`    | `0`    | Nobody gains anything useful             |

The score difference is what matters. Both players want to **maximize their own `1`s** and **deny the opponent `1`s**.

---

### Optimal Strategy

On each turn:

- **First's turn:** Take a `1` if possible, preferring `both` (denies Second a `1`). Otherwise take `firstOnly`. If no `1` is available, waste a move on `secondOnly` or `none`.
- **Second's turn:** Same logic mirrored — prefer `both`, then `secondOnly`, then waste on `firstOnly` or `none`.

This greedy approach is optimal because every `1` is worth exactly one point, and denying the opponent a `1` is equivalent to gaining one in the difference.

---

## Algorithm

1. Count how many indices are `both`, `firstOnly`, `secondOnly`, `none`.
2. Simulate `2n` turns:
   - On even turn (First): consume from `both` → `firstOnly` → `secondOnly` → `none`.
   - On odd turn (Second): consume from `both` → `secondOnly` → `firstOnly` → `none`.
3. Compare `first` vs `second` scores → print `"First"`, `"Second"`, or `"Draw"`.

---

## Complexity

- **Time:** `O(n)` — one pass to count + one pass to simulate.
- **Space:** `O(1)` — only counters used.

---

## Examples

### Example 1
```

n = 2
s = 0111
t = 0001

```
Counts: `both = 1`, `firstOnly = 2`, `secondOnly = 0`, `none = 1`

Simulation → First = 2, Second = 0 → **First wins** ✅

---

### Example 2
```

n = 3
s = 110110
t = 001001

```
Counts: `both = 1`, `firstOnly = 3`, `secondOnly = 0`, `none = 2`

Simulation → First = 3, Second = 1 → **First wins** ✅

---

### Example 3
```

n = 3
s = 111000
t = 000111

```
Counts: `both = 0`, `firstOnly = 3`, `secondOnly = 3`, `none = 0`

Simulation → First = 3, Second = 3 → **Draw** ✅

---

## Pseudocode

```
READ n
READ s
READ t

both        <- 0
firstOnly   <- 0
secondOnly  <- 0
none        <- 0

FOR i FROM 0 TO 2*n - 1 DO
	IF s[i] == '1' AND t[i] == '1' THEN
		both <- both + 1
	ELSE IF s[i] == '1' THEN
		firstOnly <- firstOnly + 1
	ELSE IF t[i] == '1' THEN
		secondOnly <- secondOnly + 1
	ELSE
		none <- none + 1
	END IF
END FOR

first  <- 0
second <- 0

FOR turn FROM 0 TO 2*n - 1 DO
	IF turn MOD 2 == 0 THEN
		// First's turn
		IF both > 0 THEN
			both <- both - 1
			first <- first + 1
		ELSE IF firstOnly > 0 THEN
			firstOnly <- firstOnly - 1
			first <- first + 1
		ELSE IF secondOnly > 0 THEN
			secondOnly <- secondOnly - 1
		ELSE
			none <- none - 1
	END IF
	ELSE
		// Second's turn
		IF both > 0 THEN
			both <- both - 1
			second <- second + 1
		ELSE IF secondOnly > 0 THEN
			secondOnly <- secondOnly - 1
			second <- second + 1
		ELSE IF firstOnly > 0 THEN
			firstOnly <- firstOnly - 1
		ELSE
			none <- none - 1
	END ELSE
END FOR

IF first > second THEN
	PRINT "First"
ELSE IF second > first THEN
	PRINT "Second"
ELSE
	PRINT "Draw"
```

---

## Notes

- The strings are always length `2n`, so both players get exactly `n` moves each.
- The greedy works because each `1` contributes equally to the score — there is no "positional" advantage (numbers are rearranged freely).
- Leading zeros don't affect comparison since both players have the same number of digits (`n`).

---