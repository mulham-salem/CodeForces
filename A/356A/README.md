# Problem 356A – Knight Tournament

## Overview

There are `n` knights numbered from `1` to `n`. The tournament consists of `m` fights. In the i-th fight, all knights still in the game whose numbers are in the range `[l_i, r_i]` fight each other, and only knight `x_i` survives (the rest are eliminated). The winner of the last fight is the tournament champion.

For every knight, we must determine **who eliminated them** — that is, the knight number that beat them. The champion's answer is `0`.

---

## Key Idea

A naive simulation is too slow: each fight could scan up to `n` knights, giving `O(n·m)` in the worst case (up to `9·10^10` operations). We need something faster.

**Observation:** Once a knight is eliminated, they never participate in any future fight. So each knight is "removed" from the active set exactly once.

This suggests a **Disjoint Set Union (DSU)** trick often called "next pointer" / "linked list with path compression":

- Maintain `parent[i]` = the next **alive** knight at position `≥ i`.
- Initially `parent[i] = i` for all `i` (everyone alive).
- `Find(i)` returns the smallest alive knight `≥ i` (with path compression).
- When knight `i` is eliminated in a fight won by `x`, we set `ans[i] = x` and **link** `i` to `i+1`: `parent[i] = Find(i+1)`.

For each fight `(l, r, x)`:
1. Start at `i = Find(l)`.
2. While `i <= r`:
   - If `i == x` (the winner), skip them: `i = Find(i+1)`.
   - Otherwise, `i` loses to `x`: set `ans[i] = x`, union `i` with `i+1`, and move on.
3. Continue until `i > r`.

Since each knight is removed at most once, the total work is nearly linear.

---

## Example

### Example 1

```

n = 4, m = 3
Fights:
1 2 1
1 3 3
1 4 4

```

- Fight 1: range `[1,2]`, winner `1`. Knight `2` loses to `1` → `ans[2] = 1`. Alive: `{1,3,4}`.
- Fight 2: range `[1,3]`, winner `3`. Knight `1` loses to `3` → `ans[1] = 3`. Alive: `{3,4}`.
- Fight 3: range `[1,4]`, winner `4`. Knight `3` loses to `4` → `ans[3] = 4`. Alive: `{4}`.

Output: `3 1 4 0`

---

### Example 2

```

n = 8, m = 4
Fights:
3 5 4
3 7 6
2 8 8
1 8 1

```

- Fight 1: `[3,5]`, winner `4` → `ans[3] = 4`, `ans[5] = 4`.
- Fight 2: `[3,7]`, winner `6` → `ans[4] = 6`, `ans[7] = 6` (3 and 5 already eliminated).
- Fight 3: `[2,8]`, winner `8` → `ans[2] = 8`, `ans[6] = 8`.
- Fight 4: `[1,8]`, winner `1` → `ans[8] = 1` (only `1` and `8` remain).

Output: `0 8 4 6 4 8 6 1`

---

## Pseudocode

```

read n, m
ans[1..n] = 0
parent[1..n+1] = 1..n+1        // sentinel n+1

function Find(x):
	if parent[x] == x: return x
	parent[x] = Find(parent[x])
	return parent[x]

for each fight (l, r, x):
	i = Find(l)
	while i <= r:
		if i == x:
			i = Find(i + 1)      // winner survives, skip
		else:
			ans[i] = x           // i loses to x
			parent[i] = Find(i + 1)  // remove i from alive set
			i = Find(i)

print ans[1..n]

```

---

## Complexity

- **Time:** `O((n + m) · α(n))` — each knight is eliminated once, each fight triggers one `Find`, and path compression makes operations near-constant (`α` is the inverse Ackermann function).
- **Space:** `O(n)` for `parent` and `ans`.

---

## Notes

- The sentinel `n+1` in `parent` prevents out-of-bounds when the last knight is eliminated.
- The winner `x` must **not** be marked as eliminated during their own fight — hence the `if (i == x) skip` branch.
- This "next alive pointer" DSU is a classic pattern for problems involving **range deletions** or **skipping already-processed elements**.

