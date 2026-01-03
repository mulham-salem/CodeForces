# Problem 682A – Alyona and Numbers

## Requirement
You are given:

- Two integers:
  - `n` — the length of the number Alyona has
  - `t` — a positive integer to multiply

Your task:

- Find the **smallest n-digit number** that is divisible by `t`.

Constraints:
- If no such number exists, print `-1`.

---

## Input
```

n t

```
Where:
- 1 ≤ n ≤ 100  
- 1 ≤ t ≤ 10

---

## Output
- A single number: smallest n-digit number divisible by `t`, or `-1` if impossible

---

## Explanation

### Key Observations
1. Smallest n-digit number = `10^(n-1)`  
   (except n=1, where smallest = 1)
2. If t = 10:
   - n must be ≥ 2 to make divisible by 10
   - Else impossible for n=1
3. If t ≠ 10:
   - Always possible: just print `t` followed by `n-1` zeros

---

## Example 1

### Input
```

2 3

```

### Output
```

12

```
Explanation:
- Smallest 2-digit number divisible by 3 = 12

---

## Example 2

### Input
```

1 10

```

### Output
```

-1

```
Explanation:
- No 1-digit number divisible by 10

---

## Solution Idea
1. Handle `t = 10` separately:
   - If n = 1 → print -1  
   - Else → print 1 followed by n-1 zeros
2. For t ≠ 10:
   - Print `t` followed by n-1 zeros
3. This guarantees **smallest n-digit number divisible by t**

---

## Important Notes
- Only 1 or 2 cases to handle
- Simple string/number construction

---

## Complexity
- **Time Complexity:** O(n) (to print number of length n)  
- **Space Complexity:** O(1) (excluding output)

---

## Key Insight
- For t ≠ 10 → prepend t, fill rest with zeros → smallest number  
- For t = 10 → need n ≥ 2 to be valid
