# Problem 791A – Bear and Big Brother

## Requirement
You are given two integers:

- **a** — Limak's weight
- **b** — Bob's weight

Every year:
- Limak's weight is multiplied by **3**
- Bob's weight is multiplied by **2**

Your task is to find the **minimum number of years** needed
so that Limak becomes **strictly heavier** than Bob.

---

## Input
Two integers **a** and **b**  
(1 ≤ a ≤ b ≤ 10)

---

## Output
One integer — the number of years needed.

---

## Example 1
**Input**
```

4 7

```

**Output**
```

2

```

**Explanation**

Year 0:
- Limak = 4
- Bob = 7

Year 1:
- Limak = 4 × 3 = 12
- Bob = 7 × 2 = 14

Year 2:
- Limak = 12 × 3 = 36
- Bob = 14 × 2 = 28

After 2 years, Limak is heavier than Bob.

---

## Example 2
**Input**
```

1 1

```

**Output**
```

1

```

**Explanation**

Year 1:
- Limak = 1 × 3 = 3
- Bob = 1 × 2 = 2

Limak becomes heavier after 1 year.

---

## Solution Idea
Simulate the process year by year:

- Each year:
  - Multiply Limak's weight by 3
  - Multiply Bob's weight by 2
- Count how many years pass
- Stop when Limak's weight becomes strictly greater than Bob's

---

## Algorithm
1. Initialize a counter `years = 0`
2. While `a ≤ b`:
   - a = a × 3
   - b = b × 2
   - years++
3. Output `years`

---

## Complexity
- **Time Complexity:** O(years)
- **Space Complexity:** O(1)

---

## Key Insight
Because Limak grows faster (×3) than Bob (×2),
he will always eventually become heavier.
A simple simulation is enough.