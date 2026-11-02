# Problem 355A – Vasya and Digital Root

## Problem Summary

Given two integers `k` and `d`, find **any** number with exactly `k` digits (no leading zeros) whose **digital root** equals `d`. If no such number exists, print `No solution`.

The **digital root** `dr(n)` is obtained by repeatedly summing the digits of `n` until a single digit remains:
- `dr(n) = S(n)` if `S(n) < 10`
- `dr(n) = dr(S(n))` otherwise

where `S(n)` is the sum of digits of `n`.

### Key Fact
For any number `n > 0`, the digital root satisfies:
```

dr(n) = 1 + ((n - 1) mod 9)

```
which means `dr(n) = 0` only when `n = 0` itself.

---

## Constraints

- `1 ≤ k ≤ 1000`
- `0 ≤ d ≤ 9`

---

## Examples

**Example 1**
```

Input:
4 4
Output:
5881

```
Explanation: `dr(5881) = dr(22) = 4`

---

**Example 2**
```

Input:
5 1
Output:
36172

```
Explanation: `dr(36172) = dr(19) = dr(10) = 1`

---

**Example 3**
```

Input:
1 0
Output:
0

```
Explanation: The only 1-digit number with digital root `0` is `0` itself.

---

**Example 4**
```

Input:
3 0
Output:
No solution

```
Explanation: A positive number (≥ 10) can never have digital root `0`.

---

## Approach / Idea

1. **Special case `d == 0`:**
   - Only the number `0` has digital root `0`.
   - So it's valid only when `k == 1` (output `0`).
   - Otherwise, print `No solution`.

2. **General case `d > 0`:**
   - If `k == 1`, simply output `d` (a single digit equal to `d`).
   - Otherwise, construct a `k`-digit number:
     - First digit: `1`
     - Middle `k - 2` digits: all `0`
     - Last digit: `d - 1`
   - This gives sum of digits = `1 + (d - 1) = d`, and since `1 ≤ d ≤ 9`, the digital root equals `d`.

---

## Pseudocode

```

read k, d

if d == 0:
	if k == 1:
		print 0
	else:
		print "No solution"
		return

if k == 1:
	print d
	return

print 1
repeat (k - 2) times:
print 0
print (d - 1)

```

---

## Complexity

- **Time:** `O(k)` — building the output string of length `k`.
- **Space:** `O(1)` — apart from the output itself.

---

## Notes

· Any valid construction is accepted — the problem allows any number satisfying the conditions.
· The trick is realizing that `dr = 0` is only possible for the number `0` itself.
· The construction `1 0 0 ... 0 (d-1)` guarantees the digit sum equals `d`, hence the digital root is `d`.
