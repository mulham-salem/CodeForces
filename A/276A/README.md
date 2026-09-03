# Problem 276A – Lunch Rush

## Problem Overview

Three Rabbits have **k** units of time for lunch. They have a list of **n** restaurants.  
For each restaurant `i`, two values are given:

- `fᵢ` – the base joy if they have enough time.
- `tᵢ` – the time needed to eat there.

**Joy calculation:**
- If `tᵢ ≤ k` → joy = `fᵢ`
- If `tᵢ > k` → joy = `fᵢ - (tᵢ - k)` (penalty for extra time)

They must choose **exactly one** restaurant.  
Find the **maximum possible joy** (can be negative).

---

## Examples

### Example 1
**Input:**
```

2 5
3 3
4 5

```
- Restaurant 1: `3 ≤ 5` → joy = 3  
- Restaurant 2: `5 ≤ 5` → joy = 4  

**Output:** 
```
4
```

---

### Example 2
**Input:**
```

4 6
5 8
3 6
2 3
2 2

```
- (5,8): `5 - (8-6) = 3`  
- (3,6): `3`  
- (2,3): `2`  
- (2,2): `2`  

**Output:** 
```
3
```

---

### Example 3
**Input:**
```

1 5
1 7

```
- `1 - (7-5) = -1`  

**Output:** 
```
-1
```

---

## Solution Approach (Pseudocode)

```

Read n, k
Initialize maxJoy = -∞

For each restaurant i from 1 to n:
Read f, t
If t <= k:
joy = f
Else:
joy = f - (t - k)
maxJoy = max(maxJoy, joy)

Print maxJoy

```

---

## Complexity

- **Time:** `O(n)` – single pass over all restaurants.  
- **Space:** `O(1)` – only a few variables used.

---