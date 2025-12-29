# Problem 344A – Magnets

## Requirement

You are given `n` magnets placed in a row.

Each magnet is described by a string of two characters:

- `"01"`  
- `"10"`

Each magnet can attract or repel the next one depending on their orientation.

---

## Goal

Determine how many **groups of magnets** are formed.

A **group** is defined as a sequence of magnets where each adjacent pair has the **same orientation**.

A new group starts whenever the orientation **changes**.

---

## Input

- An integer `n` — the number of magnets
- `n` lines, each containing a string:
  - `"01"` or `"10"`

---

## Output

- One integer: the number of magnet groups

---

## Examples

### Example 1

**Input**
```

6
10
10
10
01
10
10

```

**Output**
```

3

```

**Explanation**
```

Group 1: 10 10 10
Group 2: 01
Group 3: 10 10

```

---

### Example 2

**Input**
```

4
01
01
01
01

```

**Output**
```

1

```

**Explanation**
```

All magnets have the same orientation, so there is only one group.

```

---

## Solution Idea

1. Read the number of magnets `n`.
2. Read the first magnet and set `groups = 1`.
3. For each next magnet:
   - If it is different from the previous one, increment `groups`.
4. Update the previous magnet.
5. Print the total number of groups.

---

## Key Observation

- Every time the magnet orientation changes, a **new group** is formed.
- The first magnet always starts the first group.

---

## Complexity

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---
