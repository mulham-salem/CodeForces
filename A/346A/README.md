# Problem 346A – Alice and Bob

## Problem Summary

Alice and Bob play a game with a set of **n distinct integers**. On each turn, a player must pick two numbers `x` and `y` from the set such that their absolute difference `|x - y|` is **not** already in the set, then add that difference to the set. If a player cannot make a valid move, they lose. **Alice moves first**, and both play optimally.

Determine the winner.

---

## Key Insight

The game's final state is fixed regardless of move order: eventually the set becomes **all multiples of `g` from `g` up to `max`**, where:

- `g = gcd(a₁, a₂, ..., aₙ)` — the greatest common divisor of all initial numbers
- `max = max(a₁, ..., aₙ)`

So the total number of elements at the end is `max / g`.

Since the game starts with `n` elements, the total number of moves that will be played is:

```

moves = (max / g) - n

```

- If `moves` is **odd** → Alice makes the last move → **Alice wins**
- If `moves` is **even** → Bob makes the last move → **Bob wins**

---

## Examples

**Example 1**
```

n = 2
set = {2, 3}

```
- `g = gcd(2, 3) = 1`, `max = 3`
- moves = `3/1 - 2 = 1` (odd) → **Alice**

Alice adds `|3 - 2| = 1`. Set becomes `{1, 2, 3}`. Bob has no move. Alice wins. ✅

---

**Example 2**
```

n = 2
set = {5, 3}

```
- `g = gcd(5, 3) = 1`, `max = 5`
- moves = `5/1 - 2 = 3` (odd) → **Alice**

---

**Example 3**
```

n = 3
set = {5, 6, 7}

```
- `g = gcd(5, 6, 7) = 1`, `max = 7`
- moves = `7/1 - 3 = 4` (even) → **Bob**

---

## Pseudocode

```

read n
read array a[0..n-1]

mx = max(a)
g  = 0
for each x in a:
	g = gcd(g, x)

moves = (mx / g) - n

if moves is odd:
	print "Alice"
else:
	print "Bob"

```

---

## Complexity

- **Time:** `O(n log(max))` — dominated by the GCD computations
- **Space:** `O(n)` for storing the array
