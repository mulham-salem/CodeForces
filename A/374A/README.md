# Problem 374A – Inna and Pink Pony

## Problem Summary

Given an `n × m` chessboard, a candy starts at position `(i, j)`. The only allowed moves are diagonal jumps of size `(±a, ±b)`:

- `(x - a, y - b)`
- `(x + a, y - b)`
- `(x - a, y + b)`
- `(x + a, y + b)`

The goal is to reach **any corner** of the board: `(1,1)`, `(1,m)`, `(n,1)`, or `(n,m)` — using the **minimum number of moves**, without leaving the board at any step.

If it's impossible, print `Poor Inna and pony!`.

---

## Key Idea

For each corner, let:

- `dx` = absolute vertical distance from start to that corner
- `dy` = absolute horizontal distance from that corner

Two conditions must hold:

1. `dx % a == 0` and `dy % b == 0` — otherwise the corner is unreachable.
2. Let `p = dx / a` and `q = dy / b`. We need `p % 2 == q % 2` — because each move changes both row and column parity in the same way (both coordinates move by `a` and `b` simultaneously, so the *parity of the number of vertical and horizontal jumps must match*).

The number of moves needed for this corner is then `max(p, q)` — since we can interleave moves; some moves may overshoot a coordinate and come back, which is exactly what `max` accounts for.

---

### Special Cases

- If a distance is `0` (already aligned in that coordinate), we still need to be able to "waste" moves by moving back and forth. That's only possible if the candy can actually move along that axis: `i - a >= 1 || i + a <= n` (for rows) and `j - b >= 1 || j + b <= m` (for columns).
- If the start is already a corner, answer is `0`.

---

## Example

**Input:**
```

5 7 1 3 2 2

```

**Walkthrough:**

Check corner `(1,7)`:
- `dx = |1-1| = 0`, `dy = |3-7| = 4`
- `0 % 2 == 0` ✓, `4 % 2 == 0` ✓
- `p = 0`, `q = 2`, both even ✓
- Moves needed = `max(0, 2) = 2`

Path: `(1,3) → (3,5) → (1,7)` — 2 moves. ✅

Check corner `(5,7)`:
- `dx = 4`, `dy = 4`
- `p = 2`, `q = 2`, same parity ✓
- Moves = `2`

So minimum is `2`.

**Output:**
```

2

```

---

## Pseudocode

```

read n, m, i, j, a, b
ans = infinity

corners = [(1,1), (1,m), (n,1), (n,m)]

canMoveRow = (i - a >= 1) or (i + a <= n)
canMoveCol = (j - b >= 1) or (j + b <= m)

for each corner (r, c) in corners:
	dx = abs(i - r)
	dy = abs(j - c)

	if dx % a != 0 or dy % b != 0:
		continue

	p = dx / a
	q = dy / b

	if p % 2 != q % 2:
		continue

	moves = max(p, q)

	if moves > 0:
		if p == 0 and not canMoveRow:
			continue
		if q == 0 and not canMoveCol:
			continue

	ans = min(ans, moves)

if ans == infinity:
	print "Poor Inna and pony!"
else:
	print ans

```

---

## Complexity

- **Time:** `O(1)` — only 4 corners are checked.
- **Space:** `O(1)`.

---

## Notes

- The parity condition is the subtle part: since every move changes row by `a` and column by `b` at the same time, the number of vertical "jumps" and horizontal "jumps" must have the same parity.
- The `max(p, q)` works because the extra moves on the shorter axis can be done as back-and-forth pairs (which preserve parity).
- The `canMoveRow` / `canMoveCol` checks handle the edge case where one coordinate already matches the corner but the candy cannot make any move along that axis to "burn" extra moves.
