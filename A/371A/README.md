# Problem 371A – K-Periodic Array

## Problem Statement

You are given an array `a` of length `n` consisting only of the numbers **1** and **2**. The length `n` is divisible by `k`.

An array is called **k-periodic** if it can be formed by repeating some block `b` of length `k` exactly `n/k` times. In other words, elements at positions `i`, `i+k`, `i+2k`, … must all be equal.

Find the **minimum number of elements** you need to change so that the array becomes k-periodic.

---

## Input
- First line: two integers `n` and `k` (`1 ≤ k ≤ n ≤ 100`, `n` divisible by `k`)
- Second line: `n` integers, each is `1` or `2`

---

## Output
- Print the minimum number of changes needed.

---

## Examples

### Example 1
```

Input:
6 2
2 1 2 2 2 1

Output:
1

```
**Explanation:** Change the 4th element from `2` to `1`, giving `[2,1,2,1,2,1]` which is 2-periodic.

---

### Example 2
```

Input:
8 4
1 1 2 1 1 1 2 1

Output:
0

```
**Explanation:** The array is already 4-periodic.

---

### Example 3
```

Input:
9 3
2 1 1 1 2 1 1 1 2

Output:
3

```
**Explanation:** Change every `2` to `1`, giving an all-ones array, which is 3-periodic.

---

## Approach

For each position `i` in the range `[0, k-1]`, all elements at indices `i, i+k, i+2k, …` must be made equal. We count how many are `1` and how many are `2`, then the minimum changes for this position is `min(count1, count2)`. Summing over all `k` positions gives the answer.

---

## Pseudocode

```

read n, k
read array a of size n

answer = 0

for i from 0 to k-1:
	count1 = 0
	count2 = 0

	for j from i to n-1 step k:
		if a[j] == 1:
			count1 = count1 + 1
		else:
			count2 = count2 + 1

	answer = answer + min(count1, count2)

print answer

```

---

## Complexity
- **Time:** `O(n)` — each element is visited exactly once
- **Space:** `O(n)` — for storing the array