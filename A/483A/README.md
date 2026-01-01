# Problem 483A – Counterexample

## Requirement
You are given:

- Two integers **l** and **r** representing a range `[l, r]`.

Your task is to find **any two integers a and b** such that:

1. `l ≤ a < b ≤ r`  
2. `a` divides `b` (i.e., `b % a == 0`)

If no such pair exists, print `-1 -1`.

---

## Input
- Two integers: `l` and `r`  

---

## Output
- Two integers `a` and `b` satisfying the conditions, or `-1 -1` if impossible.

---

## Examples

### Example 1
**Input**
```

2 10

```

**Output**
```

2 4

```

**Explanation**

- 2 divides 4  
- Both numbers are within [2,10]  
- a < b → valid

Other valid outputs: 3 6, 4 8, etc.

---

### Example 2
**Input**
```

5 5

```

**Output**
```

-1 -1

```

**Explanation**

- Only one number in the range → impossible to pick a < b.

---

### Example 3
**Input**
```

7 12

```

**Output**
```

7 14

```

**Explanation**

- 7 divides 14, but 14 > r → invalid  
- Need `b ≤ r` → choose a = 8, b = 8*2 = 16 → still >12 → no valid pair  
- Actually valid solution does not exist → `-1 -1`

---

## Solution Idea
- The **smallest valid pair** is always `a = l`, `b = 2 * l`  
- If `2 * l ≤ r`, print `l 2*l`  
- Otherwise, print `-1 -1`

---

## Important Notes
- Only **one valid pair** is required.  
- Multiples beyond `2*l` are unnecessary.  
- Edge cases occur when `2*l > r`.

---

## Complexity
- **Time Complexity:** O(1)  
- **Space Complexity:** O(1)

---

## Key Insight
For any range `[l,r]`, the first possible counterexample is `(l, 2*l)`.  
If `2*l` exceeds `r`, no valid pair exists.
