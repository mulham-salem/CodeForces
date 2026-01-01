# Problem 486A – Calculating Function

## Requirement
You are given:

- An integer **n**.  

Define the function:

```

f(n) = n/2      if n is even
f(n) = -((n+1)/2)  if n is odd

```

Your task is to **compute f(n)**.

---

## Input
- Integer **n**  

---

## Output
- One integer — value of `f(n)`

---

## Examples

### Example 1
**Input**
```

6

```

**Output**
```

3

```

**Explanation**

6 is even → f(6) = 6/2 = 3

---

### Example 2
**Input**
```

7

```

**Output**
```

-4

```

**Explanation**

7 is odd → f(7) = -((7+1)/2) = -8/2 = -4

---

### Example 3
**Input**
```

0

```

**Output**
```

0

```

**Explanation**

0 is even → f(0) = 0/2 = 0

---

## Solution Idea
1. Check if **n is even**:
   - Return n / 2
2. If **n is odd**:
   - Return -((n+1)/2)

---

## Important Notes
- Integer division is required.
- Negative results occur for odd positive integers.

---

## Complexity
- **Time Complexity:** O(1)  
- **Space Complexity:** O(1)

---

## Key Insight
The function alternates between positive and negative integers based on parity:
- even → positive half  
- odd → negative half of next integer