# Problem 367A – Sereja and Algorithm

## Problem Summary

Sereja has an algorithm that takes a string `q` (consisting only of characters `x`, `y`, `z`) and repeatedly does the following:

1. Find any substring of **3 consecutive characters** that is **NOT** one of: `"zyx"`, `"xzy"`, `"yxz"`. If no such substring exists, **terminate**.
2. Randomly rearrange the letters of that substring, then go back to step 1.

The algorithm is considered **correct** on a string if there is a **non-zero probability** that it terminates (i.e., it can reach a state where every 3-character substring is one of the three "good" permutations).

You are given a string `s` of length `n` and `m` queries. For each query `(l, r)`, determine if the algorithm works correctly on the substring `s[l..r]`.

---

## Key Insight

The three "good" substrings are exactly the cyclic rotations of `"zyx"`:
- `zyx`
- `xzy`
- `yxz`

Notice that in every good substring, **all three characters appear exactly once** — one `x`, one `y`, one `z`.

If a string can be rearranged (via the random swaps) into a form where **every** window of 3 consecutive characters is a permutation of `xyz`, then the counts of `x`, `y`, `z` must be **as balanced as possible**.

### Why?

- Each good window of length 3 contains exactly one of each character.
- Sliding the window by one position, the leaving and entering characters must match in a way that keeps counts balanced.
- This is only possible if the total counts of `x`, `y`, `z` differ by **at most 1**.

---

### Special Cases

- If the substring length is **less than 3**, the algorithm terminates immediately → **YES**.
- Otherwise, the answer is **YES** iff `max(count_x, count_y, count_z) - min(count_x, count_y, count_z) <= 1`.

---

## Examples

| Query | Substring | Counts (x,y,z) | Max−Min | Answer |
|-------|-----------|----------------|---------|--------|
| `5 5` | `"x"` | (1,0,0) | — (len < 3) | YES |
| `1 3` | `"zyx"` | (1,1,1) | 0 | YES |
| `1 11` | `"zyxxxxxxyyz"` | (7,3,1) | 6 | NO |
| `1 4` | `"zyxx"` | (2,1,1) | 1 | YES |
| `3 6` | `"xxxx"` | (4,0,0) | 4 | NO |

---

## Pseudocode

```

read string s
n = length(s)

build prefix sums:
prefX[i] = number of 'x' in s[0..i-1]
prefY[i] = number of 'y' in s[0..i-1]
prefZ[i] = number of 'z' in s[0..i-1]

read m
for each query (l, r):
	len = r - l + 1
	if len < 3:
		print "YES"
		continue
		
	x = prefX[r] - prefX[l-1]
	y = prefY[r] - prefY[l-1]
	z = prefZ[r] - prefZ[l-1]
	
	mx = max(x, y, z)
	mn = min(x, y, z)
	
	if mx - mn <= 1:
		print "YES"
	else:
		print "NO"

```

---

## Complexity

- **Time:** `O(n + m)` — prefix sums build in `O(n)`, each query answered in `O(1)`.
- **Space:** `O(n)` — three prefix arrays.
