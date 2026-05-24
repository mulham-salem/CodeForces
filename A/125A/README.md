# Problem 125A – Measuring Lengths in Baden

## Description
In Baden:

- `1 inch = 3 centimeters`
- `1 foot = 12 inches`

Given a length in centimeters, convert it to:
- maximum possible number of feet
- remaining inches

The result must be rounded to the nearest whole inch.

---

## Input
A single integer `n` — the length in centimeters.

### Constraints
- `1 ≤ n ≤ 10000`

---

## Output
Print two integers:

- number of feet
- remaining inches

---

## Examples

### Example 1

#### Input
```text
42
```

#### Output
```text
1 2
```

#### Explanation
- `42 cm = 14 inches`
- `14 inches = 1 foot + 2 inches`

---

### Example 2

#### Input
```text
5
```

#### Output
```text
0 2
```

#### Explanation
- `5 / 3 ≈ 1.67`
- rounded to `2 inches`

---

## Idea
1. Convert centimeters to inches using rounding.
2. Convert total inches into:
   - feet
   - remaining inches

---

## Pseudocode

```text
read n

inches = (n + 1) / 3

feet = inches / 12
remaining = inches % 12

print feet and remaining
```

---

## Complexity
- Time: `O(1)`
- Memory: `O(1)`

---