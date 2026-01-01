# Problem 431A – Black Square

## Requirement
You are given:

- Four integers **a₁, a₂, a₃, a₄** — the calories burned by stepping on
  squares **1, 2, 3, and 4** respectively.
- A string **s** consisting only of characters `'1'`, `'2'`, `'3'`, `'4'`.

Each character in the string represents stepping on the corresponding square.

Your task is to calculate the **total calories burned**.

---

## Input
- Four integers: **a₁ a₂ a₃ a₄**
- A string **s**

---

## Output
- One integer — the total calories burned

---

## Examples

### Example 1
**Input**
```

1 2 3 4
12314

```

**Output**
```

11

```

**Explanation**

Steps:
- `1` → 1 calorie
- `2` → 2 calories
- `3` → 3 calories
- `1` → 1 calorie
- `4` → 4 calories

Total: `1 + 2 + 3 + 1 + 4 = 11`

---

### Example 2
**Input**
```

1 1 1 1
4444

```

**Output**
```

4

```

**Explanation**

Each step costs 1 calorie.
4 steps → total = 4.

---

## Solution Idea
1. Store the calorie values in an array where:
   - index `0` → square `1`
   - index `1` → square `2`
   - index `2` → square `3`
   - index `3` → square `4`
2. Traverse the string:
   - Convert each character to its corresponding index.
   - Add the calorie value to the total.

---

## Important Notes
- The string can be of any length.
- Only characters `'1'` to `'4'` appear.
- Order matters, repetition is allowed.

---

## Complexity
- **Time Complexity:** O(|s|)
- **Space Complexity:** O(1)

---

## Key Insight
The problem is a direct mapping:
each character in the string contributes a fixed cost that is simply summed.
