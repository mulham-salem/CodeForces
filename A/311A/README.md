# Problem 311A – The Closest Pair

## Problem Summary

Given `n` points in the plane, the following brute-force algorithm finds the closest pair:

```text
input n
for i from 1 to n
    input point i into p[i]
sort p[] by x, then by y
d = INF
tot = 0
for i from 1 to n
    for j from i+1 to n
        ++tot
        if (p[j].x - p[i].x >= d) break
        d = min(d, distance(p[i], p[j]))
output d
```

Here tot represents the running time. We must generate n distinct points such that `tot > k`.
If impossible, output `no solution`.

---

## Key Observation

· The maximum possible value of tot is when the inner loop never breaks early — i.e., all pairs are checked.
· `Total pairs = n * (n - 1) / 2`.
· If this maximum is `<= k`, it's impossible to exceed `k` → output `no solution`.

**Construction When Possible**

If `n * (n - 1) / 2 > k`, we need points where the inner loop never breaks early.
The break condition is:

```text
if (p[j].x - p[i].x >= d) break
```

If we place all points on a vertical line `(x = 0)`, then:

· `p[j].x - p[i].x = 0` always.
· `d` starts at `INF`, then becomes the smallest distance found so far (which is `>= 1` because points are distinct integers).
· Since `0 < d` always, the break never triggers.
· Thus `tot = n * (n - 1) / 2`, which is `> k`.

**So the construction is:**

```text
(0, 0), (0, 1), (0, 2), ..., (0, n-1)
```

All coordinates satisfy `|x|, |y| <= 10^9` for `n <= 2000`.

---

## Algorithm

```text
read n, k
maxTot = n * (n - 1) / 2
if maxTot <= k:
    print "no solution"
else:
    for i = 0 to n-1:
        print 0, i
```

---

## Examples

### Example 1

**Input:**

```text
4 3
```

**Output:**

```text
0 0
0 1
0 2
0 3
```

· `maxTot = 4*3/2 = 6 > 3` → `possible`.
· Points are collinear on `x = 0`.
· `tot = 6 > 3` → `TLE achieved`.

---

### Example 2

**Input:**

```text
2 100
```

**Output:**

```text
no solution
```

· `maxTot = 2*1/2 = 1 <= 100` → `impossible to exceed k`.

---

## Complexity

· **Time:** `O(n)` to output points.
· **Space:** `O(1)` extra.

---

## Pseudocode

```text
read n, k
maxTot = n * (n - 1) / 2
if maxTot <= k:
    print "no solution"
    return
for i = 0 to n-1:
    print 0, i
```

---