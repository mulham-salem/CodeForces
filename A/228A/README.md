# Problem 228A – Is your horseshoe on the other hoof?

## Requirement

You are given **four integers**, each representing the color of a horseshoe.

The horse needs **four horseshoes of different colors**.

**Goal:**  
Determine how many horseshoes must be **replaced** so that all four horseshoes have **distinct colors**.

---

## Input

- Four integers `a`, `b`, `c`, `d`
  - Each integer represents a color
  - `1 ≤ a, b, c, d ≤ 10^9`

---

## Output

- One integer: the number of horseshoes that need to be replaced

---

## Examples

### Example 1

**Input**
```

1 7 3 3

```

**Output**
```

1

```

**Explanation**
```

The colors are: {1, 7, 3, 3}
Color 3 is repeated once.
So, 1 horseshoe must be replaced.

```

---

### Example 2

**Input**
```

1 1 1 1

```

**Output**
```

3

```

**Explanation**
```

All horseshoes have the same color.
To make all four colors different,
3 horseshoes must be replaced.

```

---

### Example 3

**Input**
```

1 2 3 4

```

**Output**
```

0

```

**Explanation**
```

All colors are already distinct.
No replacement is needed.

```

---

## Solution Idea

1. Count how many **distinct colors** are present among the four horseshoes.
2. Since we need exactly **4 different colors**:
   - `replacements = 4 - number_of_distinct_colors`
3. Print the result.

---

## Key Notes

- Only the **number of distinct values** matters.
- Order of input does not matter.

---

## Complexity

- **Time Complexity:** `O(1)`
- **Space Complexity:** `O(1)`

---