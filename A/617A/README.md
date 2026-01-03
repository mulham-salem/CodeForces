# Problem 617A – Elephant

## Requirement
You are given:

- An integer `n` — the distance (in meters) the elephant needs to travel.

The elephant can make **jumps of fixed lengths**: 1, 2, 3, 4, or 5 meters.  

Your task is to determine the **minimum number of jumps** needed for the elephant to cover exactly `n` meters.

---

## Input
```

n

```
Where:
- 1 ≤ n ≤ 10^9

---

## Output
One integer — the minimum number of jumps needed.

---

## Explanation
- The elephant wants to minimize jumps.
- So it should **use the largest possible jumps (5 meters) first**, then smaller jumps for the remainder.

---

## Solution Idea
1. Divide `n` by 5 to get full jumps:  
```

full_jumps = n / 5

```
2. Check the remainder:  
```

remainder = n % 5

```
- If remainder > 0 → need **one extra jump** for the leftover distance.

3. Total jumps:
```

total_jumps = full_jumps + (remainder > 0 ? 1 : 0)

```

---

## Example 1

### Input
```

5

```

### Output
```

1

```
Explanation:
- 5 meters → exactly one 5-meter jump.

---

## Example 2

### Input
```

12

```

### Output
```

3

```
Explanation:
- 12 ÷ 5 = 2 full jumps (10 meters)  
- Remainder = 2 → need 1 more jump  
- Total = 2 + 1 = 3

---

## Important Notes
- Always prioritize **biggest jumps**.
- Only one extra jump is needed if remainder exists.

---

## Complexity
- **Time Complexity:** O(1)
- **Space Complexity:** O(1)

---

## Key Insight
Greedy approach works: **maximize 5-meter jumps** first, then add at most one smaller jump for the leftover distance.
