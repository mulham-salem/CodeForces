# Problem 278A – Circle Line

## Problem Explanation

We have `n` stations arranged in a circle. The distances between consecutive stations are given:

- `d1` between station 1 and 2  
- `d2` between station 2 and 3  
- ...  
- `dn` between station n and 1  

Trains run in both directions. We need to find the **shortest** distance between two given stations `s` and `t`.

Since the line is circular, there are exactly two possible paths:

1. **Clockwise**: From `s` to `t` moving forward.
2. **Counterclockwise**: The other way around (the total circle length minus the clockwise distance).

We compute both and take the smaller one.

---

## Example Walkthrough

### Example 1
```

n = 4
d = [2, 3, 4, 9]
s = 1, t = 3

```
- Clockwise path (1→2→3): `2 + 3 = 5`
- Counterclockwise path (1→4→3): `9 + 4 = 13`
- Shortest = `min(5, 13) = 5` ✅

---

### Example 2
```

n = 4
d = [5, 8, 2, 100]
s = 4, t = 1

```
- Clockwise (4→1): `100`
- Counterclockwise (4→3→2→1): `2 + 8 + 5 = 15`
- Shortest = `min(100, 15) = 15` ✅

---

### Example 3
```

n = 3
d = [1, 1, 1]
s = 3, t = 1

```
- Clockwise (3→1): `1`
- Counterclockwise (3→2→1): `1 + 1 = 2`
- Shortest = `min(1, 2) = 1` ✅

---

### Example 4
```

s = 1, t = 1

```
- Distance = `0` (same station) ✅

---

## Solution Approach (Pseudo-code)

```

1. Read n
2. Read array d[0..n-1], sum all values → total
3. Read s, t
4. If s > t, swap them to make s ≤ t
5. Compute clockwise distance:
   · sum d[i] for i = s-1 to t-2
6. Counterclockwise distance = total - clockwise
7. Answer = min(clockwise, counterclockwise)
8. Print answer

```

---

## Complexity

- **Time:** `O(n)` – just one loop to sum the clockwise path  
- **Space:** `O(1)` – only a few integer variables

---