# Problem 34A – Reconnaissance 2

## Requirement
You are given:

- An integer **n** — the number of soldiers.
- An array of **n integers** — the heights of the soldiers.

The soldiers are standing **in a circle**, which means:
- Soldier `i` is adjacent to soldier `i + 1`
- Soldier `n` is adjacent to soldier `1`

Your task is to find **two adjacent soldiers** whose **absolute height difference** is **minimum**.

---

## Input
- Integer **n**
- **n integers** — heights of the soldiers

---

## Output
- Two integers — the **1-based indices** of the adjacent soldiers
  with the smallest height difference.

---

## Examples

### Example 1
**Input**
```

5
10 13 15 10 20

```

**Output**
```

2 3

```

**Explanation**

Adjacent differences:

- |10 − 13| = 3  
- |13 − 15| = 2 ✅  
- |15 − 10| = 5  
- |10 − 20| = 10  
- |20 − 10| = 10  (last with first)

The minimum difference is **2**, between soldiers **2** and **3**.

---

### Example 2
**Input**
```

4
1 100 50 2

```

**Output**
```

4 1

```

**Explanation**

Adjacent differences:

- |1 − 100| = 99  
- |100 − 50| = 50  
- |50 − 2| = 48  
- |2 − 1| = 1 ✅ (last with first)

The minimum difference is between soldiers **4** and **1**.

---

## Solution Idea
- Traverse the soldiers in order.
- Compute the absolute difference between each adjacent pair.
- Keep track of the smallest difference found.
- Store the indices of the pair that gives this minimum.
- Finally, compare the **last** soldier with the **first** one.

---

## Important Notes
- Indices are **1-based**, not 0-based.
- The soldiers form a **circle**, not a straight line.
- Only **adjacent** soldiers are compared.

---

## Complexity
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## Key Insight
Because only adjacent soldiers matter and the formation is circular,
a single pass through the array (plus one final comparison) is sufficient.
