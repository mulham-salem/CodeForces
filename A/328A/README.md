# Problem 328A – IQ Test

## Problem Summary

Given **four integers** representing a sequence, determine whether it forms:

- An **arithmetic progression** → output the next term.
- A **geometric progression** → output the next term.
- Neither → output `42`.

Also, if the next term is **not an integer**, output `42`.

### Input
Four integers between `1` and `1000`.

### Output
The next element of the progression, or `42`.

---

## Examples

### Example 1
**Input:**
```

836 624 412 200

```
**Output:**
```

-12

```
**Reason:** Arithmetic progression with common difference `-212`.

---

### Example 2
**Input:**
```

1 334 667 1000

```
**Output:**
```

1333

```
**Reason:** Arithmetic progression with common difference `333`.

---

## Pseudocode

```

READ a, b, c, d

IF (b - a == c - b) AND (c - b == d - c):
	PRINT d + (d - c)
	
ELSE IF (b * b == a * c) AND (c * c == b * d):
	IF (d * c) MOD b == 0:
		PRINT (d * c) / b
	ELSE:
		PRINT 42
		
ELSE:
	PRINT 42

```

---

## Notes

- Use `long long` for multiplication to avoid overflow.
- Geometric progression checks only ratios between consecutive terms.
- If the ratio produces a non-integer next term, answer is `42`.

---