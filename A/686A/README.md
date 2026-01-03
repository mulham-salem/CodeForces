# Problem 686A – Free Ice Cream

## Requirement
You are given:

- Two integers:
  - `n` — number of ice cream portions available
  - `m` — number of friends requesting ice cream
- An array of `m` integers — each integer represents the **amount of ice cream** a friend wants

Your task:

- Determine **whether all friends can get the ice cream they requested** without exceeding the total `n` portions.

---

## Input
```

n m
a1 a2 ... am

```
Where:
- 1 ≤ n, m ≤ 100  
- 1 ≤ ai ≤ 100

---

## Output
- Print `"YES"` if all friends can be served  
- Print `"NO"` otherwise

---

## Explanation
- Sum all requested portions  
- If total ≤ `n` → YES  
- Else → NO

---

## Example 1

### Input
```

3 2
1 2

```

### Output
```

YES

```
Explanation:
- Total requested = 1 + 2 = 3 ≤ 3 → YES

---

## Example 2

### Input
```

3 2
2 2

```

### Output
```

NO

```
Explanation:
- Total requested = 4 > 3 → NO

---

## Solution Idea
1. Read `n` and `m`  
2. Read array of requests  
3. Sum all requests  
4. Compare with `n` and output `"YES"` or `"NO"`

---

## Important Notes
- Simple sum check  
- No sorting or loops beyond reading array

---

## Complexity
- **Time Complexity:** O(m)  
- **Space Complexity:** O(1) extra (excluding input array)

---

## Key Insight
- Problem reduces to **checking if the sum of requests ≤ n**
