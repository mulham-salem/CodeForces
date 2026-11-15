# Problem 360A – Levko and Array Recovery

## Problem Summary

You are given `n` (array size) and `m` (number of operations). The original array is lost, but you have a record of all operations performed on it in order. Operations are of two types:

| Type | Description |
|------|-------------|
| `1 l r d` | Add `d` to every element in range `[l, r]` |
| `2 l r m` | Query the maximum element in range `[l, r]`, and the recorded result is `m` |

You need to reconstruct **any** valid initial array (values within `|ai| ≤ 10^9`) such that replaying all operations produces exactly the recorded results. If impossible, output `NO`.

---

## Approach (Brief)

### Phase 1 — Build candidate array using accumulated additions

- Maintain `add[i]` = total sum of type‑1 increments applied to position `i` **so far** (from the beginning up to the current operation).
- Maintain `ans[i]` = the maximum allowed initial value for position `i`, initialized to `INF = 1e9`.

For each operation:

- **Type 1** `(l, r, d)`:
  - For every `j` in `[l, r]`: `add[j] += d`
  - This means any future type‑2 query on `j` must account for this accumulated addition.

- **Type 2** `(l, r, m)`:
  - For every `j` in `[l, r]`: `ans[j] = min(ans[j], m - add[j])`
  - Because at the moment of the query, the actual value at `j` is `initial[j] + add[j]`, and the maximum over the range must equal `m`.  
    So each element in the range must satisfy: `initial[j] + add[j] ≤ m` → `initial[j] ≤ m - add[j]`.

After processing all operations, `ans[i]` is an upper bound on the initial value at position `i`.  
We set `initial[i] = ans[i]`.

### Phase 2 — Validate

Simulate all operations again using the constructed initial array:

- Type 1: add `d` to range.
- Type 2: compute max over range and compare with recorded `m`.

If any mismatch → `NO`.  
Otherwise → `YES` and print the array.

---

## Example 1

**Input:**
```

4 5
1 2 3 1
2 1 2 8
2 3 4 7
1 1 3 3
2 3 4 8

```

**Phase 1 trace:**

- Start: `ans = [INF, INF, INF, INF]`, `add = [0, 0, 0, 0]`
- Op1: type 1, `[2,3] +1` → `add = [0,1,1,0]`
- Op2: type 2, `[1,2] max = 8` →  
  `ans[1] = min(INF, 8-0) = 8`  
  `ans[2] = min(INF, 8-1) = 7`
- Op3: type 2, `[3,4] max = 7` →  
  `ans[3] = min(INF, 7-1) = 6`  
  `ans[4] = min(INF, 7-0) = 7`
- Op4: type 1, `[1,3] +3` → `add = [3,4,4,0]`
- Op5: type 2, `[3,4] max = 8` →  
  `ans[3] = min(6, 8-4) = 4`  
  `ans[4] = min(7, 8-0) = 7`

Result: `ans = [8, 7, 4, 7]`

**Phase 2 validation:**

- Op1: add 1 to [2,3] → `[8, 8, 5, 7]`
- Op2: max[1,2] = max(8,8) = 8 ✅
- Op3: max[3,4] = max(5,7) = 7 ✅
- Op4: add 3 to [1,3] → `[11, 11, 8, 7]`
- Op5: max[3,4] = max(8,7) = 8 ✅

Output: `YES` and `8 7 4 7` (or `4 7 4 7` as in sample — both valid, since any array satisfying constraints is accepted).

---

## Example 2

**Input:**
```

4 5
1 2 3 1
2 1 2 8
2 3 4 7
1 1 3 3
2 3 4 13

```

Same as above but last query is `13` instead of `8`.

**Phase 1** gives `ans[3] = min(6, 13-4) = 6`, `ans[4] = min(7, 13-0) = 7`.  
So `ans = [8, 7, 6, 7]`.

**Phase 2 validation:**

- After Op4: `[11, 11, 10, 7]`
- Op5: max[3,4] = max(10,7) = 10 ≠ 13 → **NO** ❌

---

## Pseudocode

```

INF = 1e9
read n, m
ops = list of m operations

ans = array of n filled with INF
add = array of n filled with 0

// Phase 1: build upper bounds
for each op in ops:
if op.type == 1:
for j in op.l .. op.r:
add[j] += op.d
else:
for j in op.l .. op.r:
ans[j] = min(ans[j], op.m - add[j])

// Phase 2: validate
current = copy of ans
for each op in ops:
if op.type == 1:
for j in op.l .. op.r:
current[j] += op.d
else:
mx = max(current[op.l .. op.r])
if mx != op.m:
print "NO"
exit

print "YES"
print ans

```

---

## Complexity

- **Time:** `O(n·m)` — each operation touches at most `n` elements (n, m ≤ 5000 → ≤ 25·10⁶ operations, fits in 1s).
- **Space:** `O(n + m)` — arrays for `ans`, `add`, and operations.

---

## Notes

- The constructed array may differ from the sample output because **any valid array** is accepted.
- `INF = 1e9` ensures initial values stay within the allowed `|ai| ≤ 10^9` bound (and `ans` only decreases from `INF`).
- Using `long long` avoids overflow when accumulating `add` values (max `5000 × 10^4 = 5·10^7`, still safe in `int`, but `long long` is safer with `m - add` where `m` can be `5·10^7`).