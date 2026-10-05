# Problem 321A – Ciel and Robot

## Problem Summary

A robot starts at `(0, 0)` and executes a command string `s` **infinitely**, repeating it over and over. Each character is a move:

| Char | Move |
|------|------|
| `U`  | `(x, y) → (x, y+1)` |
| `D`  | `(x, y) → (x, y-1)` |
| `L`  | `(x, y) → (x-1, y)` |
| `R`  | `(x, y) → (x+1, y)` |

Given target `(a, b)`, determine whether the robot will **ever** land exactly on `(a, b)`.

**Constraints:** `-10^9 ≤ a, b ≤ 10^9`, `1 ≤ |s| ≤ 100`

---

## Key Idea

1. **Simulate one full cycle** of `s` and compute the net displacement `(dx, dy)` per cycle.
2. For **every position** visited inside one cycle (including start), check if we can reach `(a, b)` by repeating the cycle `k` times (`k ≥ 0`):
   - Need: `x + k·dx = a` and `y + k·dy = b`
   - Solve for `k` and verify it's a **non-negative integer** and consistent across both axes.
3. **Special cases:**
   - If `(dx, dy) = (0, 0)` → the robot loops forever; just check if any visited position equals `(a, b)`.
   - If only one of `dx, dy` is zero → check the non-zero axis only.

---

## Example 1

```

Input:
2 2
RU

```

Cycle `RU`: positions visited → `(0,0) → (1,0) → (1,1)`, net `(dx, dy) = (1, 1)`.

- Check `(1,1)`: need `1 + k = 2` and `1 + k = 2` → `k = 1` ✅

**Output:** `Yes`

---

## Example 2

```

Input:
1 2
RU

```

Cycle `RU`: positions `(0,0), (1,0), (1,1)`, net `(1,1)`.

- `(0,0)`: `k = 1` for x, `k = 2` for y → mismatch ❌
- `(1,0)`: `k = 0` for x, `k = 2` for y → mismatch ❌
- `(1,1)`: `k = 0` for x, `k = 1` for y → mismatch ❌

**Output:** `No`

---

## Example 3

```

Input:
-1 1000000000
LRRLU

```

Cycle net `(dx, dy) = (0, 1)`. Since `dx = 0`, only check `x == -1` and `(b - y) % 1 == 0` with `k ≥ 0`. Position `(-1, 0)` after `LRR` satisfies it with `k = 10^9`.

**Output:** `Yes`

---

## Example 4

```

Input:
0 0
D

```

Start position `(0,0)` already matches target.

**Output:** `Yes`

---

## Pseudocode

```

read a, b
read s

Step 1: compute net displacement per cycle

dx = 0, dy = 0
for c in s:
	update (dx, dy) according to c

Step 2: check start position

if (0, 0) == (a, b): print "Yes"; exit

Step 3: check each position in one cycle

x = 0, y = 0

for c in s:
	update (x, y) according to c
	rx = a - x
	ry = b - y

	if dx == 0 and dy == 0:
		if rx == 0 and ry == 0: print "Yes"; exit
	else if dx == 0:
		if rx == 0 and ry % dy == 0 and ry / dy >= 0:
			print "Yes"; exit
	else if dy == 0:
		if ry == 0 and rx % dx == 0 and rx / dx >= 0:
			print "Yes"; exit
	else:
		if rx % dx == 0 and ry % dy == 0
		   and rx / dx == ry / dy
		   and rx / dx >= 0:
			print "Yes"; exit

print "No"

```

---

## Complexity

| Metric | Value |
|--------|-------|
| Time   | `O(abs(s))` |
| Space  | `O(1)`   |

---