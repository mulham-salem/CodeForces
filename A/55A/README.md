# Problem 55A – Flea travel

## Problem Summary

A flea is sitting on one of the `n` hassocks arranged in a circle. After minute `k`, the flea jumps over `k-1` hassocks clockwise. For example, after the first minute the flea jumps to the neighboring hassock, after the second minute it jumps over one hassock, and so on.

Determine if the flea will visit **all hassocks** eventually.

---

## Input

- Single integer `n` (1 ≤ n ≤ 1000) — the number of hassocks.

---

## Output

- Print `"YES"` if the flea will visit all hassocks.  
- Print `"NO"` otherwise.

---

## Examples

**Example 1:**

Input: 1

Output: YES

Explanation: Only one hassock exists, so the flea is already there.

---

**Example 2:**

Input: 3

Output: NO

Explanation: The flea jumps with increasing steps (1,2,3...) modulo 3. It never reaches all positions; some hassocks are skipped indefinitely.

---

## Key Insight

- The flea's position after `k` minutes can be expressed as:

position = (1 + 2 + ... + k) % n = k*(k+1)/2 % n

- The flea will eventually visit **all positions** if and only if `n` is a **power of 2**:

n = 1, 2, 4, 8, 16, ...

- This property can be efficiently checked using the bitwise trick:

if (n & (n-1)) == 0 → YES else → NO

---

## Pseudocode

```
read n

if n is a power of 2: 
	print "YES" 
else: 
	print "NO"
```

- **Checking power of 2:**  
  - Either use `(n & (n-1)) == 0`  
  - Or repeatedly divide n by 2 until n == 1

---

## Summary

- Compute flea positions using triangular numbers modulo n.  
- All positions are reachable **only if n is a power of 2**.  
- Otherwise, some positions are never visited.

---