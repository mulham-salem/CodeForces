# Problem 723A – The New Year: Meeting Friends

## Requirement
You are given the positions of **three friends** on a number line.

- Three integers **a**, **b**, **c** — the positions of the friends.

All friends want to meet at **one single point**.
Moving costs distance (absolute difference).

Your task is to find the **minimum total distance**
all three friends need to travel to meet.

---

## Input
- Three integers **a**, **b**, **c**

---

## Output
- One integer — the minimum total distance.

---

## Examples

### Example 1
**Input**
```

7 1 4

```

**Output**
```

6

```

**Explanation**

Positions:
- 1, 4, 7

Best meeting point is **4** (the middle one):

- |1 − 4| = 3  
- |4 − 4| = 0  
- |7 − 4| = 3  

Total distance = **3 + 0 + 3 = 6**

---

### Example 2
**Input**
```

3 3 3

```

**Output**
```

0

```

**Explanation**

All friends are already at the same position.
No one needs to move.

---

## Solution Idea
- Sort the three positions.
- The optimal meeting point is always the **middle value**.
- Compute the distance from the middle to the other two.

Why?
Because the **median** minimizes the sum of absolute distances.

---

## Important Notes
- Only three numbers → sorting is trivial.
- Meeting at the smallest or largest position gives a larger total distance.

---

## Complexity
- **Time Complexity:** `O(1)` (only three values)
- **Space Complexity:** `O(1)`

---

## Key Insight
The sum of absolute distances is minimized when everyone meets
at the **median position**.
For three friends, that is simply the middle value after sorting.