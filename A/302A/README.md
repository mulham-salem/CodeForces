# Problem 302A – Eugeny and Array

## Problem Summary
Given an array of `n` integers where each element is either `1` or `-1`, answer `m` queries.  
Each query gives a range `[l, r]`. You need to determine if the elements inside this range can be rearranged so that their sum equals `0`.  
Output `1` if possible, otherwise `0`.

---

## Key Idea
- To make the sum equal to `0`, we need the same number of `1`s and `-1`s.
- Therefore, the length of the subarray must be **even**.
- Let `len = r - l + 1`. We need `len / 2` ones and `len / 2` negatives (where negative means `-1`).
- The answer depends only on the **length** of the query and the **total counts** in the whole array.
- Because we can rearrange the whole array arbitrarily, we just need enough `1`s and `-1`s in the entire array to form a subarray of that length with equal counts.
- Condition: `len` is even, and `ones >= len/2` and `negatives >= len/2`.

---

## Example
**Input:**
```

2 3
1 -1
1 1
1 2
2 2

```
- Total ones = 1, negatives = 1.
- Query 1: len=1 (odd) → 0
- Query 2: len=2, need 1 one and 1 negative → available → 1
- Query 3: len=1 (odd) → 0

**Output:**
```

0
1
0

```

---

## Pseudocode
```

read n, m
read array a
ones = count of 1 in a
negatives = n - ones

for each query (l, r):
	len = r - l + 1
	if len is odd:
		print 0
	else:
		need = len / 2
	if ones >= need and negatives >= need:
		print 1
	else:
		print 0

```

---

## Time Complexity
- **Reading input:** `O(n + m)`
- **Processing queries:** `O(1)` per query → `O(m)` total
- **Overall:** `O(n + m)`
- **Space Complexity:** `O(1)` extra space (only counters)

---