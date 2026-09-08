# Problem 283A – Cows and Sequence

## Problem Statement
Bessie and the cows are playing with a sequence. Initially, the sequence contains just the number `0`. They perform `n` operations, each of one of three types:

1. **Add** integer `xᵢ` to the first `aᵢ` elements of the sequence.
2. **Append** integer `kᵢ` to the end of the sequence (size increases by 1).
3. **Remove** the last element of the sequence (only allowed if there are at least two elements).

After each operation, output the **average** of all numbers in the sequence.

### Constraints
- `1 ≤ n ≤ 2·10⁵`
- `|xᵢ|, |kᵢ| ≤ 10³`
- All operations are guaranteed to be valid.

### Example
**Input**
```

5
2 1
3
2 3
2 1
3

```

**Output**
```

0.500000
0.000000
1.500000
1.333333
1.500000

```

---

## Solution Approach (Pseudocode)

We need to support:
- Range add on prefix.
- Append at the end.
- Pop from the end.
- Query the average of the whole sequence.

A naive approach would be too slow. Instead, we use an **efficient lazy propagation trick**:

### Key Idea
- Maintain an array `val[i]` = actual value of the `i`-th element.
- Maintain an auxiliary array `add[i]` = pending addition to be applied to **all elements from position 1 to i**.
- When we do a prefix add of `x` to first `a` elements, we just do:
```

add[a] += x
sum += a * x

```
- When appending a new element `k`:
```

sz++
val[sz] = k
add[sz] = 0
sum += k

```
- When removing the last element:
```

// first, apply any pending additions to this element
val[sz] += add[sz]
sum -= val[sz]

// propagate the pending addition to the previous element
add[sz-1] += add[sz]

sz--

```

### Pseudocode

```

Initialize:
val[1] = 0
add[1] = 0
sum = 0
size = 1

For each operation:
	if type == 1:
		read a, x
		add[a] += x
		sum += a * x

	else if type == 2:
		read k
		size++
		val[size] = k
		add[size] = 0
		sum += k

	else if type == 3:
		// apply pending addition to last element
		val[size] += add[size]
		sum -= val[size]

		// propagate addition to previous element
		add[size-1] += add[size]
		size--

	output sum / size as floating point with 6 decimal places

```

---

## Complexity
- Time: `O(n)` for all operations.
- Space: `O(n)` for the two arrays.

---

## Notes
- The trick works because we only ever need to remove the last element, so we can propagate lazy additions backwards.
- The answer precision requires printing with `6` decimal places.

---