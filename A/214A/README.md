# Problem 214A – System of Equations

## Problem Description
You are given two integers `n` and `m`.  
Count how many pairs of non-negative integers `(a, b)` satisfy the following system of equations:

a² + b = n  
a + b² = m  

Where:
- a ≥ 0
- b ≥ 0

---

## Input
A single line containing two integers `n` and `m`.

Constraints:
- 1 ≤ n, m ≤ 1000

---

## Output
Print a single integer — the number of valid pairs `(a, b)`.

---

## Observations
From the equations:
- a² ≤ n → a ≤ √n
- b² ≤ m → b ≤ √m

So we only need to check small values of `a` and `b`.

---

## Solution Approach
1. Read `n` and `m`
2. Loop over `a` from `0` to `√n`
3. Loop over `b` from `0` to `√m`
4. If both equations are satisfied, increase the counter
5. Print the final count

---

## Examples

Input:
```

9 3

```

Output:
```

1

```

Valid pair:
```

(3, 0)

```

---

Input:
```

14 28

```

Output:
```

1

```

Valid pair:
```

(3, 5)

```

---

Input:
```

4 20

```

Output:
```

0

````

---

## Time Complexity

O(√n × √m)

---

## Notes

This brute-force solution is efficient enough due to the small constraints.
