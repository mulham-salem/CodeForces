# Problem 584A – Olesya and Rodion

## Requirement
You are given:

- Three integers:
  - `n` — the desired length of the number
  - `a` — the minimum digit in the number
  - `b` — the maximum digit in the number

You need to construct **any n-digit number** such that **all digits are either a or b**.

If it is impossible, output `-1`.

---

## Input
```

n a b

```

Where:
- 1 ≤ n ≤ 1000
- 0 ≤ a, b ≤ 9

---

## Output
- A single n-digit number consisting only of digits `a` and `b`, or
- `-1` if no such number exists.

---

## Explanation
- Any combination of digits `a` and `b` is allowed.
- The number must have exactly `n` digits.
- Leading zeros are allowed only if `a` or `b` is `0` (except n=1).

---

## Example 1

### Input
```

3 1 2

```

### Output
```

111

```

Other valid outputs: `112`, `121`, `122`, `211`, `212`, `221`, `222`

---

## Example 2

### Input
```

2 0 0

```

### Output
```

00

```

---

## Solution Idea
1. Any combination of `a` and `b` digits of length `n` is valid.
2. The simplest approach:
   - Print `n` copies of `a` (or `b`)  
   - This guarantees the solution if n ≥ 1.
3. If both `a` and `b` are zero and n > 1, it’s still valid as leading zeros are allowed in this problem.

---

## Important Notes
- Multiple valid answers exist.
- You may output any valid number.
- No loops needed if you just print one repeated digit.

---

## Complexity
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

---

## Key Insight
This is a **constructive problem**: any sequence of length `n` using `a` and `b` works.  
You don’t need to check all combinations; just pick one digit to repeat `n` times.
