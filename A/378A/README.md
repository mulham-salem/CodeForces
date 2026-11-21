# Problem 378A – Playing with Dice

## Problem Statement

Two players each write an integer from **1 to 6**, then a standard six-sided dice is thrown. The player whose written number is **closer** to the dice result wins. If both players have the **same difference**, the game is a **draw**.

Given the numbers written by the first player `a` and the second player `b`, count for all possible dice outcomes (1–6) how many times:
- the **first player wins**,
- the game ends in a **draw**,
- the **second player wins**.

A number `a` is closer to `x` than `b` if `|a - x| < |b - x|`.

### Input
A single line with two integers `a` and `b` (1 ≤ a, b ≤ 6).

### Output
Three integers: number of wins for the first player, number of draws, number of wins for the second player.

---

### Examples

**Input:**
```

2 5

```
**Output:**
```

3 0 3

```

**Input:**
```

2 4

```
**Output:**
```

2 1 3

```

---

## Pseudocode

```

READ a, b
SET first = 0, draw = 0, second = 0

FOR i FROM 1 TO 6:
	d1 = ABS(a - i)
	d2 = ABS(b - i)

	IF d1 < d2:
		first = first + 1
	ELSE IF d1 == d2:
		draw = draw + 1
	ELSE:
		second = second + 1
	
PRINT first, draw, second

```

---

### Complexity
- **Time:** O(1) — always 6 iterations.
- **Space:** O(1).
