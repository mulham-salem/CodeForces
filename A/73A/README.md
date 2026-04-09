# Problem 73A – The Elder Trolls IV: Oblivon

## Problem Description

Vasya needs to cut an "Unkillable Slug" shaped as a rectangular parallelepiped of size `x × y × z`.  
He has a maximum of `k` cuts. Each cut can slice through the entire slab along a plane parallel to one of its sides.  
The monster dies when it is divided into enough parts.  

**Goal:** Determine the **maximum number of parts** Vasya can obtain using at most `k` cuts.

---

## Input

Four integers:

x y z k

- `1 ≤ x, y, z ≤ 10^6`  
- `0 ≤ k ≤ 10^9`

---

## Output

- Single integer: maximum number of pieces.

---

## Examples

| Input       | Output |
|------------|--------|
| 2 2 2 3    | 8      |
| 2 2 2 1    | 2      |
| 3 3 3 4    | 12     |

**Explanation:**  

- Example 1: 3 cuts along three perpendicular axes → 2 * 2 * 2 = 8 pieces.  
- Example 2: 1 cut → splits only one axis → 2 pieces.  
- Example 3: 4 cuts → distribute along axes: 2 * 2 * 3 = 12 pieces.

---

## Notes

- After each cut, all parts remain in place.  
- Cuts can be distributed among any dimensions but cannot exceed the size of that dimension minus one.

---

## Pseudocode

```
function max_pieces(x, y, z, k): 
	sort dimensions: d0 <= d1 <= d2 
	ans = 1 
	for a in 0..min(d0-1, k): 
		rem = k - a 
		candidate_b = [0, min(d1-1, rem), rem//2, rem//2+1, max(0, rem-(d2-1)), max(0, rem-(d2-1))+1] 
		for b in candidate_b: 
			if b < 0 or b > d1-1 or b > rem: 
				continue 
			c = min(d2-1, rem - b) 
			if c < 0: 
				continue 
			pieces = (a+1)(b+1)(c+1) 
			ans = max(ans, pieces) 
	return ans
```
---
