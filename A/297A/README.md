# Problem 297A – Parity Game

## 📌 Problem Summary

You are given two binary strings `a` and `b`. You can perform two operations on `a` any number of times:

1. **Append `parity(a)`** to the end of `a`.
   - `parity(a) = 1` if the number of `'1'`s in `a` is **odd**, otherwise `0`.
2. **Remove the first character** of `a` (only if `a` is not empty).

Determine whether it is possible to transform `a` into `b`.

---

## 💡 Key Idea

The only limited resource is the number of `'1'`s.

- `'0'`s can always be added freely (parity can be `0`).
- The **length** and **order** of characters don't matter — we can remove from the front and append to the back.

### Maximum Number of `'1'`s We Can Reach

| Case | Max `'1'`s |
|------|-------------|
| `cntA` is **even** | `cntA` |
| `cntA` is **odd**  | `cntA + 1` |

Why?
- If `cntA` is even → parity = `0` → we can only append `0`s → no new `1`s.
- If `cntA` is odd → parity = `1` → we can append **one** extra `1`, making it even, and then we're stuck.

### Condition

```

YES  if  cntB <= cntA + (cntA % 2)
NO   otherwise

```

---

## 🧪 Examples

### Example 1
```

a = "01011"   →  cntA = 3 (odd)  →  max = 4
b = "0110"    →  cntB = 2

```
`2 <= 4` → **YES** ✅

### Example 2
```

a = "0011"    →  cntA = 2 (even) →  max = 2
b = "1110"    →  cntB = 3

```
`3 > 2` → **NO** ❌

---

## 🧾 Pseudocode

```

read a, b

cntA = number of '1' in a
cntB = number of '1' in b

if cntA is odd:
	cntA = cntA + 1

if cntB <= cntA:
	print "YES"
else:
	print "NO"

```

---

## ⏱️ Complexity

- **Time:** `O(|a| + |b|)`
- **Space:** `O(1)`

---