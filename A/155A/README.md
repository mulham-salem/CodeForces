# Problem 155A – Amazing Performances

## Requirement

You are given the results of `n` games played by a participant.

Each game has a score.
The **first game** sets both the initial **minimum** and **maximum** score.

A game is considered **amazing** if its score is:
- **Strictly greater** than all previous scores, or
- **Strictly smaller** than all previous scores.

Your task is to count how many **amazing performances** occurred.

---

## Input

- Integer `n` — number of games  
- `n` integers — scores of the games in order

---

## Output

- One integer — number of amazing performances

---

## Examples

### Example 1

**Input**
```

5
100 50 200 150 300

```

**Output**
```

3

```

**Explanation**
```

First score: 100
(min = 100, max = 100)

50  → smaller than min → amazing
200 → greater than max → amazing
150 → between min and max → not amazing
300 → greater than max → amazing

Total amazing performances = 3

```

---

### Example 2

**Input**
```

4
10 10 10 10

```

**Output**
```

0

```

**Explanation**
```

All scores are equal.
No score is strictly greater or strictly smaller.

```

---

## Solution Idea

1. The **first score** initializes:
   - minimum score so far
   - maximum score so far

2. For each next score:
   - If it is **greater than the current maximum** → amazing
   - If it is **smaller than the current minimum** → amazing

3. Update the minimum or maximum when an amazing performance occurs.

4. Count how many times this happens.

---

## Important Notes

- The first game is **never counted** as amazing.
- Comparisons must be **strict** (`>` or `<`).
- You do **not** need to compare with all previous scores.
- Keeping only the current minimum and maximum is enough.

---

## Complexity

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## Key Insight

If a score is higher than the best so far, or lower than the worst so far,
then it is automatically better or worse than **all previous scores**.
