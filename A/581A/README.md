# Problem 581A – Vasya the Hipster

## Requirement
You are given:

- Two integers `a` and `b`
- `a` represents the number of red socks
- `b` represents the number of blue socks

Each day, Vasya wears **two socks of different colors** if possible.
If not possible, he wears **two socks of the same color**.

Your task is to determine:
1. The number of days Vasya can wear **different-colored socks**
2. The number of days Vasya can wear **same-colored socks**

---

## Input
```

a b

```

---

## Output
Two integers:
```

x y

```

Where:
- `x` = days wearing different-colored socks
- `y` = days wearing same-colored socks

---

## Explanation

### Different-colored socks
Each such day consumes:
- 1 red sock
- 1 blue sock

So:
```

x = min(a, b)

```

---

### Same-colored socks
After using different-colored pairs:
```

remaining = max(a, b) - min(a, b)

```

Each same-colored day consumes **2 socks**:
```

y = remaining / 2

```

---

## Example 1

### Input
```

3 1

```

### Output
```

1 1

```

Explanation:
- 1 day → different colors
- Remaining socks: 2 red → 1 same-color day

---

## Example 2

### Input
```

7 7

```

### Output
```

7 0

```

Explanation:
- All days with different colors
- No socks left

---

## Solution Idea
1. Take the minimum of `a` and `b` for different-colored days.
2. Subtract used socks.
3. Divide remaining socks by 2 to get same-colored days.
4. Output the results.

---

## Important Notes
- Integer division is used.
- No loops or complex logic needed.

---

## Complexity
- **Time Complexity:** O(1)
- **Space Complexity:** O(1)

---

## Key Insight
Different-colored pairs are limited by the smaller sock count.
Same-colored pairs can only be formed from leftover socks.
