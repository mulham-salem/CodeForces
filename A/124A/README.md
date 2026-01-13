# Problem 124A – The number of positions

## Problem Summary
Petr is standing in a line of `n` people, but he does not know his exact position.

He only knows that:
- At least `a` people are standing in front of him
- At most `b` people are standing behind him

The task is to determine how many different positions Petr can occupy.

---

## Key Idea
If Petr stands at position `i` (1-based indexing):

- People in front of him: `i - 1`
- People behind him: `n - i`

From the conditions:
- `i - 1 ≥ a`
- `n - i ≤ b`

Instead of working with `i` directly, we focus on the **minimum number of people that must be in front of Petr**.

There are two constraints:
- From the first condition: at least `a`
- From the second condition: at least `n - 1 - b`

So the actual minimum is:
```

minFront = max(a, n - 1 - b)

```

---

## Counting Valid Positions
If at least `minFront` people are in front of Petr:

- The earliest possible position is `minFront + 1`
- The latest possible position is `n`

Therefore, the number of valid positions is:
```

n - minFront

```

Which simplifies to:
```

n - max(a, n - b - 1)

```

---

## Examples

### Example 1
Input:
```

3 1 1

```

Valid positions:
```

2 3

```

Output:
```

2

```

---

### Example 2
Input:
```

5 2 3

```

Valid positions:
```

3 4 5

```

Output:
```

3

```

---

## Pseudo-code
```

read n, a, b
minFront = max(a, n - 1 - b)
print n - minFront

```

---

## Complexity
- Time complexity: `O(1)`
- Space complexity: `O(1)`