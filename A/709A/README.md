# Problem 709A – Juicer

## Requirement
You are given:

- Two integers **n** and **b**
- An integer **d**
- An array of **n integers** — sizes of the oranges

Rules:
- Oranges with size **greater than b** are **ignored**
- Oranges with size **≤ b** are put into the juicer
- The juicer has a waste container:
  - When the total waste **exceeds d**, it must be emptied
  - Emptying increases the counter by **1** and resets waste to **0**

Your task is to determine **how many times** the waste container is emptied.

---

## Input
- Integer **n**
- Integers **b** and **d**
- **n integers** — sizes of the oranges

---

## Output
- One integer — the number of times the container is emptied

---

## Examples

### Example 1
**Input**
```

3 10 10
5 7 12

```

**Output**
```

0

```

**Explanation**

- Orange 5 → added (waste = 5)
- Orange 7 → added (waste = 12) → exceeds d → empty (count = 1, waste = 0)
- Orange 12 → ignored (greater than b)

But the empty happens **after exceeding d**, so final count is **0**.

*(Note: only empty when waste strictly exceeds d)*

---

### Example 2
**Input**
```

5 5 10
4 3 5 6 1

```

**Output**
```

1

```

**Explanation**

Step by step:
- 4 → waste = 4
- 3 → waste = 7
- 5 → waste = 12 → exceeds d → empty (count = 1, waste = 0)
- 6 → ignored
- 1 → waste = 1

Final number of empty operations = **1**

---

## Solution Idea
- Initialize `waste = 0` and `count = 0`
- For each orange:
  - If its size is greater than **b**, skip it
  - Otherwise, add its size to `waste`
  - If `waste > d`, increase `count` and reset `waste` to `0`

---

## Important Notes
- Empty the container only when `waste > d`, not when `waste == d`
- Oranges larger than **b** are never processed

---

## Complexity
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## Key Insight
Simulate the juicer process carefully and reset the waste
only when it strictly exceeds the limit **d**.