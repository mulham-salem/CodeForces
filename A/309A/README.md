# Problem 309A – Morning run

## Problem Summary

There are `n` runners on a circular stadium of length `l`. Each runner starts at a distinct position `a[i]` (clockwise distance from the start line). Every runner independently chooses a direction (clockwise or counter-clockwise) with equal probability, and all run at speed `1 m/s` for `t` seconds.

A **bump** happens whenever two runners occupy the same point at the same moment. A pair can bump multiple times. We need the **expected total number of bumps** over all runner pairs.

---

## Key Observations

- Runners going in the **same direction** never meet (same speed).
- Only runners going in **opposite directions** can bump.
- For a pair with clockwise distance `d`, if they run in opposite directions, they meet once for every integer `k ≥ 0` such that `d + k·l ≤ 2t`.

Let `x = 2t`, and write `x = q·l + r` with `0 ≤ r < l`.

- If `d ≤ r`: number of meetings = `q + 1`
- If `d > r`: number of meetings = `q`

---

## Expectation Formula

Summing over all unordered pairs `(i, j)`:

```

Answer = (q · total_pairs) / 2 + (close_pairs) / 4

```

where:

- `total_pairs = n·(n-1)/2`
- `close_pairs` = count of pairs captured by the two-pointer scan (distances ≤ `r` on the doubled circle)

---

## Counting Close Pairs

Since `a` is sorted, duplicate it into an array `b` of size `2n` where `b[i+n] = a[i] + l`. Then use two pointers to count, for each `i`, how many `j` satisfy `i < j < i+n` and `b[j] - b[i] ≤ r`.

---

## Pseudocode

```

read n, l, t
read sorted array a[0..n-1]

x = 2 * t
q = x / l
r = x % l

total_pairs = n * (n - 1) / 2
close_pairs = 0

if r > 0:
b[0..2n-1] = a[0..n-1] followed by a[0..n-1] + l
j = 1
for i in 0..n-1:
if j < i + 1: j = i + 1
while j < i + n and b[j] - b[i] <= r:
j = j + 1
close_pairs += j - i - 1

answer = total_pairs * q / 2.0 + close_pairs / 4.0
print answer with 10 decimal places

```

---

## Example 1

**Input:**
```

2 5 1
0 2

```

**Output:**
```

0.2500000000

```

---

## Example 2

**Input:**
```

3 7 3
0 1 6

```

**Output:**
```

1.5000000000

```

---

## Complexity

- **Time:** `O(n)` after sorting (input is already sorted)
- **Space:** `O(n)`

---