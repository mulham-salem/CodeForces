# Problem 323A – Black-and-White Cube

## Problem Description

You are given a cube of size **k × k × k**, consisting of unit cubes. Two unit cubes are considered neighbours if they share a common face.

You must paint each of the **k³** unit cubes either **black (b)** or **white (w)** such that:

- Each **white** cube has **exactly 2** neighbouring white cubes.
- Each **black** cube has **exactly 2** neighbouring black cubes.

---

## Input

A single integer **k** (1 ≤ k ≤ 100) — the size of the cube.

---

## Output

- Print `-1` if no solution exists.
- Otherwise, print the cube layer by layer. Each layer is a **k × k** matrix. Print **k** layers in total, separated by blank lines (blank lines are optional).
- Use `w` for white and `b` for black.

---

## Examples

### Example 1

**Input:**
```

1

```

**Output:**
```

-1

```

**Explanation:** A single cube has 0 neighbours, so it cannot have exactly 2 neighbours of the same colour.

---

### Example 2

**Input:**
```

2

```

**Output:**
```

bb
ww

bb
ww

```

**Explanation:** For k = 2, we can arrange the cube in 2 layers of 2×2. Each cube ends up with exactly 2 neighbours of the same colour.

---

## Approach

- If **k is odd**, no solution exists → print `-1`.
- If **k is even**, we can construct a valid painting using a pattern based on the parity of coordinates:
  - Colour a cell `b` if `(i + j/2 + z/2) % 2 == 0`, otherwise `w`.
  - This ensures each cube has exactly 2 same-coloured neighbours.

---

## Pseudocode

```

READ k

IF k % 2 != 0:
	PRINT -1
	RETURN

FOR i FROM 0 TO k-1:
	FOR j FROM 0 TO k-1:
		FOR z FROM 0 TO k-1:
			IF (i + j/2 + z/2) % 2 == 0:
				PRINT 'b'
			ELSE:
				PRINT 'w'
		PRINT newline
	PRINT newline

```

---

## Notes

- Only **even k** values have a valid solution.
- The pattern alternates colours in blocks of 2 along two dimensions, and by single steps along the third dimension.
- Output layers are printed one after another; blank lines between layers are ignored by the judge.

---