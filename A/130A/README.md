# Problem 130A – Hexagonal Numbers

## Description
Hexagonal numbers are figurate numbers calculated using the following formula:

```text
h(n) = 2 * n^2 - n
```

Given an integer `n`, you need to find the `n-th` hexagonal number.

---

## Input
The input contains a single integer:

- `n` `(1 ≤ n ≤ 100)`

---

## Output
Print the `n-th` hexagonal number.

---

## Examples

### Input
```text
2
```

### Output
```text
6
```

### Explanation
```text
h(2) = 2 * (2^2) - 2
     = 2 * 4 - 2
     = 8 - 2
     = 6
```

---

### Input
```text
5
```

### Output
```text
45
```

### Explanation
```text
h(5) = 2 * (5^2) - 5
     = 2 * 25 - 5
     = 50 - 5
     = 45
```

---

## Idea
Use the formula directly to calculate the answer.

---

## Pseudocode

```text
read n

answer = 2 * n * n - n

print answer
```

---

## Complexity Analysis

- Time Complexity: `O(1)`
- Memory Complexity: `O(1)`

---