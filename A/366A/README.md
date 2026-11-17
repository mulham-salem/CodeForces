# Problem 366A – Dima and Guards

## Problem Summary

Dima wants to sneak Inna through one of **4 guardposts**. Each guardpost has **2 guards**. To pass, both guards must be bribed with either a chocolate bar or a box of juice.

For each guard, you are given:
- Minimum acceptable price for a chocolate bar
- Minimum acceptable price for a box of juice

The shop sells items of **any integer price ≥ 1**. Dima must spend **exactly `n` rubles** total — buying **one gift for each of the two guards** in the chosen post.

Find any guardpost where this is possible, and output:
- The guardpost number
- The price of the first guard's gift
- The price of the second guard's gift

If impossible for all posts, output `-1`.

---

## Key Insight

For each guard, the **cheapest acceptable gift** is:

```

min(chocolatePrice, juicePrice)

```

For a guardpost to be valid, the sum of the two cheapest gifts must be **≤ n**. If so, we can always distribute the remaining money by increasing one gift's price (since any price ≥ 1 is available, and the guard accepts anything ≥ her minimum).

So the condition per post is:

```

min(a, b) + min(c, d) <= n

```

If satisfied, pick `firstGift = min(a, b)` and `secondGift = n - firstGift`.

> ⚠️ Note: `secondGift` will automatically be ≥ `min(c, d)` because the sum condition guarantees it.

---

## Example 1

**Input:**
```

10
5 6 5 6
6 6 7 7
5 8 6 6
9 9 9 9

```

**Check each post:**

| Post | min(a,b) | min(c,d) | Sum | ≤ 10? |
|------|----------|----------|-----|-------|
| 1    | 5        | 5        | 10  | ✅    |
| 2    | 6        | 7        | 13  | ❌    |
| 3    | 5        | 6        | 11  | ❌    |
| 4    | 9        | 9        | 18  | ❌    |

**Output:**
```

1 5 5

```

---

## Example 2

**Input:**
```

10
6 6 6 6
7 7 7 7
4 4 4 4
8 8 8 8

```

**Check each post:**

| Post | min(a,b) | min(c,d) | Sum | ≤ 10? |
|------|----------|----------|-----|-------|
| 1    | 6        | 6        | 12  | ❌    |
| 2    | 7        | 7        | 14  | ❌    |
| 3    | 4        | 4        | 8   | ✅    |
| 4    | 8        | 8        | 16  | ❌    |

Post 3 works. `firstGift = 4`, `secondGift = 10 - 4 = 6`.

**Output:**
```

3 4 6

```

---

## Example 3

**Input:**
```

5
3 3 3 3
3 3 3 3
3 3 3 3
3 3 3 3

```

Every post needs at least `3 + 3 = 6 > 5`.

**Output:**
```

-1

```

---

## Pseudocode

```

READ n
FOR post = 1 TO 4:
READ a, b, c, d
firstMin  = MIN(a, b)
secondMin = MIN(c, d)

IF firstMin + secondMin <= n:
    firstGift  = firstMin
    secondGift = n - firstGift
    PRINT post, firstGift, secondGift
    EXIT
	
PRINT -1

```

---

## Complexity

- **Time:** O(1) — only 4 posts checked
- **Space:** O(1) — constant extra memory
