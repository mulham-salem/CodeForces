# Problem 467A – George and Accommodation

## Requirement
George is looking for an apartment.  

You are given:

- An integer **n** — the number of apartments available.
- An integer **k** — the minimum number of free rooms George needs.
- **n** integers **a₁, a₂, …, aₙ** — the number of free rooms in each apartment.  

Your task is to count how many apartments have **at least k free rooms**.

---

## Input
- Integer **n** and integer **k**
- **n** integers — the number of free rooms in each apartment

---

## Output
- One integer — number of apartments suitable for George

---

## Examples

### Example 1
**Input**
```

5 3
3 1 4 1 5

```

**Output**
```

3

```

**Explanation**

Apartments with at least 3 free rooms: 3, 4, 5 → count = 3

---

### Example 2
**Input**
```

4 2
1 1 1 1

```

**Output**
```

0

```

**Explanation**

All apartments have fewer than 2 free rooms → 0 suitable

---

## Solution Idea
1. Initialize a counter to 0.
2. Traverse the list of apartments.
3. For each apartment, check if free rooms ≥ k:
   - If yes, increment the counter.
4. Output the counter.

---

## Important Notes
- Only the **number of free rooms** matters.
- Exact equality (free rooms = k) counts as suitable.
- Order of apartments does not matter.

---

## Complexity
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

---

## Key Insight
This is a simple counting problem:
> Count all apartments with at least k free rooms.

