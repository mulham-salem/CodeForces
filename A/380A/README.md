# Problem 380A – Sereja and Prefixes

## Problem Summary

Sereja builds a sequence in `m` stages. Each stage is one of two types:

- **Type 1** `1 x` — append a single number `x` to the end of the sequence.
- **Type 2** `2 l c` — take the first `l` elements of the current sequence and append them `c` times.

So if the current sequence is `a₁, a₂, ..., aₙ`, after type 2 it becomes:

```

a₁, a₂, ..., aₙ, [a₁, ..., aₗ], [a₁, ..., aₗ], ... (c times)

```

The final sequence can be **huge** (up to ~10¹⁵ elements), so we cannot build it entirely. We are given `n` queries — positions (1-indexed) — and must output the value at each position. The positions are given in strictly increasing order.

---

## Key Idea

We cannot store the whole sequence, but we can:

1. **Store the operations** with their cumulative length (`len`) and the previous length (`prevLen`).
2. **Store only the first `LIMIT = 100000` elements** explicitly in an array `a`. Since every query position either falls inside this small prefix or can be reduced to it, this is enough.
3. For a query position `p`:
   - If `p ≤ LIMIT`, answer directly from `a`.
   - Otherwise, **binary search** for the first operation whose `len ≥ p`. This tells us which operation "produced" position `p`.
     - If it's **type 1**, the answer is `x`.
     - If it's **type 2** with parameters `(l, prevLen)`, then position `p` came from a copy of the prefix. Map it back:
       ```
       p = (p - prevLen - 1) % l + 1
       ```
       and answer `a[p-1]`.

Because type-2 operations only copy a prefix of length `l ≤ 10⁵`, every query eventually reduces to an index inside the stored prefix `a`.

---

## Why `LIMIT = 100000`?

- Every `l ≤ 10⁵` (given constraint), and every type-1 element is a single number.
- So any position in the final sequence can be traced back to one of the first `10⁵` elements.
- Storing those `10⁵` elements is enough to answer all queries in O(log m) each.

---

## Example Walkthrough

**Input:**
```

6
1 1
1 2
2 2 1
1 3
2 5 2
1 4
16
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16

```

Build the sequence step by step (length in parentheses):

| Stage | Operation | Sequence after | Length |
|-------|-----------|----------------|--------|
| 1 | `1 1` | `1` | 1 |
| 2 | `1 2` | `1 2` | 2 |
| 3 | `2 2 1` | `1 2 1 2` | 4 |
| 4 | `1 3` | `1 2 1 2 3` | 5 |
| 5 | `2 5 2` | `1 2 1 2 3 1 2 1 2 3 1 2 1 2 3` | 15 |
| 6 | `1 4` | `... 4` | 16 |

Now answer positions `1..16`:

- Positions `1..10` are within the stored prefix → `1 2 1 2 3 1 2 1 2 3`
- Position `11`: falls in stage 5 (type 2, `l=5`, `prevLen=5`).
  `(11 - 5 - 1) % 5 + 1 = 1` → `a[0] = 1`
- Position `12`: `(12-5-1)%5+1 = 2` → `a[1] = 2`
- ... and so on.
- Position `16`: falls in stage 6 (type 1) → `4`

**Output:**
```

1 2 1 2 3 1 2 1 2 3 1 2 1 2 3 4

```

---

## Pseudocode

```

read m
ops = []
a = []              // stores first LIMIT elements
currentLength = 0

for i in 1..m:
	read type
	if type == 1:
		read x
		oldLength = currentLength
		currentLength += 1
		ops.append({type=1, len=currentLength, prevLen=oldLength, x=x})
		if len(a) < LIMIT:
			a.append(x)
	else:
		read l, c
		oldLength = currentLength
		currentLength += l * c
		ops.append({type=2, len=currentLength, prevLen=oldLength, x=l})
		added = min(l * c, LIMIT - len(a))
		for j in 0..added-1:
			a.append(a[j % l])

read n
for each query position p:
	if p <= len(a):
		print a[p-1]
	else:
		idx = binary_search_first ops[idx].len >= p
		if ops[idx].type == 1:
			print ops[idx].x
		else:
			l = ops[idx].x
			prevLen = ops[idx].prevLen
			p = (p - prevLen - 1) % l + 1
			print a[p-1]

```

---

## Complexity

- **Preprocessing:** O(m + LIMIT) — building `a` and `ops`.
- **Each query:** O(log m) for binary search.
- **Total:** O(m + n log m), well within limits for `m, n ≤ 10⁵`.

---

## Notes / Pitfalls

- Use **`long long`** for lengths and positions — the sequence can exceed `10¹⁴`.
- The positions are **strictly increasing**, but the solution doesn't rely on that (it works for any order).
- `a` only needs the first `LIMIT` elements; type-2 operations copy from the **beginning**, so `a[j % l]` is always valid.
- Do **not** use `%lld` in C++ I/O; use `cin`/`cout` or `%I64d`.
- Binary search finds the **first** operation whose cumulative length covers `p` — this is the operation that created that element.