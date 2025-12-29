# Problem 339A – Helpful Maths

## Requirement

You are given a string representing a sum of **single-digit numbers** separated by `'+'`.

- Each number is either `1`, `2`, or `3`
- The numbers are given in **random order**

Example:
```

3+2+1

```

---

## Goal

Rearrange the numbers in the sum so that they appear in **non-decreasing order**,  
and output the resulting sum in the same format.

---

## Input

- A single string `s`
  - Contains digits (`1`, `2`, `3`) and `'+'` characters

---

## Output

- The reordered sum string

---

## Examples

### Example 1

**Input**
```

3+2+1

```

**Output**
```

1+2+3

```

---

### Example 2

**Input**
```

1+1+3+1+3

```

**Output**
```

1+1+1+3+3

```

---

### Example 3

**Input**
```

2

```

**Output**
```

2

```

---

## Solution Idea

1. Extract all digits from the string and store them in a list.
2. Sort the list in non-decreasing order.
3. Rebuild the string by joining the sorted numbers with `'+'`.

---

## Key Observation

- `'+'` characters are only separators and should be ignored during sorting.
- Only the digits need to be sorted.

---

## Complexity

- **Time Complexity:** `O(n log n)`
- **Space Complexity:** `O(n)`

---
