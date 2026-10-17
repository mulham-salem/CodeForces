# Problem 335A – Banana

## Problem Summary

Piegirl wants to form a target string `s` by buying identical sticker sheets. Each sheet contains exactly `n` characters (all sheets are the same string of length `n`). She can take any subset of stickers from the sheets and rearrange them in any order to build `s`.

**Goal:** Find the **minimum number of sheets** needed, and output **one valid sheet string** of length `n`. If it's impossible, print `-1`.

---

## Key Observations

- Let `cnt[c]` be how many times character `c` appears in `s`.
- If the number of **distinct characters** in `s` exceeds `n`, it's impossible → output `-1`.
- For a sheet to be usable with `k` sheets, if it holds `x[c]` copies of character `c`, we need:
  - `k * x[c] >= cnt[c]` for every character `c`
  - `sum(x[c]) = n` (sheet length)
- To minimize `k`, we want each `x[c]` to be roughly `ceil(cnt[c] / k)`.

---

## Approach

1. **Feasibility check:** If `distinct_chars(s) > n` → print `-1`.
2. **Binary search on `k`** (number of sheets):
   - For a given `k`, the minimum sheet length needed is:
     ```
     needed(k) = sum over c of ceil(cnt[c] / k)
     ```
   - If `needed(k) <= n`, then `k` sheets are feasible.
   - Find the smallest such `k`.
3. **Construct the sheet:**
   - Put `ceil(cnt[c] / k)` copies of each character `c` on the sheet.
   - Fill remaining slots with any letter (e.g., `'a'`).

---

## Example 1

**Input:**
```

banana
4

```

**Reasoning:**
- `cnt: b=1, a=3, n=2`, distinct = 3 ≤ 4 ✓
- `k=1`: `1+3+2 = 6 > 4` ✗
- `k=2`: `1+2+1 = 4 ≤ 4` ✓ → minimum `k = 2`
- Sheet: `b×1, a×2, n×1` → `"baan"`

**Output:**
```

2
baan

```

---

## Example 2

**Input:**
```

banana
3

```

**Reasoning:**
- distinct = 3 ≤ 3 ✓
- `k=1`: `6 > 3` ✗
- `k=2`: `4 > 3` ✗
- `k=3`: `1+1+1 = 3 ≤ 3` ✓ → `k = 3`
- Sheet: `b×1, a×1, n×1` → `"abn"` (any permutation works)

**Output:**
```

3
nab

```

---

## Example 3

**Input:**
```

banana
2

```

**Reasoning:**
- distinct = 3 > 2 → **impossible**

**Output:**
```

-1

```

---

## Pseudocode

```

read s, n

count frequency of each character in s → cnt
distinct = number of distinct characters in s

if distinct > n:
print -1
return

# Binary search on k = number of sheets

lo = 1, hi = length(s), best_k = hi

while lo <= hi:
mid = (lo + hi) / 2
needed = 0
for each character c in cnt:
needed += ceil(cnt[c] / mid)
if needed <= n:
best_k = mid
hi = mid - 1
else:
lo = mid + 1

k = best_k

# Build sheet string

sheet = ""
for each character c in cnt:
x = ceil(cnt[c] / k)
append c, x times, to sheet

while length(sheet) < n:
append 'a' to sheet

sort(sheet)          # optional, for readability
print k
print sheet

```

---

## Complexity

| Step | Time |
|------|------|
| Frequency counting | **O(\|s\|)** |
| Binary search | **O(\|s\| · log\|s\|)** |
| Sheet construction | **O(n)** |

**Overall:** `O(|s| · log|s| + n)` — well within limits for `|s|, n ≤ 1000`.
