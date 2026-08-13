# Problem 242A – Heads or Tails

## Problem

Vasya and Petya are tossing a coin.

- Vasya tosses the coin `x` times.
- Petya tosses the coin `y` times.
- Every **Head** gives the player one point.
- Every **Tail** gives nobody any points.

Valera knows that:

- Vasya got at least `a` Heads.
- Petya got at least `b` Heads.
- Vasya was the winner.

We need to find **all possible final scores** `(c, d)` that satisfy these conditions.

---

## Input

The input contains four integers:
```
x y a b
```
Where:

| Variable | Meaning |
|----------|---------|
| `x` | Number of times Vasya tosses the coin |
| `y` | Number of times Petya tosses the coin |
| `a` | Minimum number of Heads Vasya got |
| `b` | Minimum number of Heads Petya got |

### Constraints

`1 ≤ a ≤ x ≤ 100`
`1 ≤ b ≤ y ≤ 100`

---

## Output

First, print the number `n` of possible outcomes.

Then print `n` pairs:
```
c d
```
Where:

- `c` = number of Heads Vasya got.
- `d` = number of Heads Petya got.

A pair is valid if:

`a ≤ c ≤ x`
`b ≤ d ≤ y`
`c > d`

The pairs must be printed in **strictly increasing lexicographical order**.

That means:

1. Sort by `c`.
2. If `c` is equal, sort by `d`.

---

## Approach

We simply try every possible number of Heads for both players.

For Vasya:

	c = a ... x

For Petya:

    d = b ... y

For every pair `(c, d)`:

    if c > d

then Vasya has more points than Petya, so the pair is a valid outcome.

Because we iterate `c` from small to large and `d` from small to large, the generated pairs are already in the required lexicographical order.

---

## Example 1

### Input
```
3 2 1 1
```
Possible values are:
```
Vasya: c = 1, 2, 3
Petya: d = 1, 2
```
We keep only pairs where Vasya wins:
```
2 1   ✓
3 1   ✓
3 2   ✓
```
For example:
```
1 1   ✗  Draw
1 2   ✗  Petya wins
2 2   ✗  Draw
```
Therefore there are `3` possible outcomes.

### Output
```
3
2 1
3 1
3 2
```
---

## Example 2

### Input
```
2 4 2 2
```
Vasya must get at least `2` Heads, and he can toss only `2` times.

Therefore:

`c = 2`

Petya must get at least `2` Heads:

`d ≥ 2`

But Vasya must win:

`c > d`

So we would need:

`2 > d`

while at the same time:

`d ≥ 2`

This is impossible.

Therefore there are no valid outcomes.

### Output
```
0
```
---

## Complexity

We try at most `100 × 100` pairs.

### Time Complexity

    O(x × y)

### Space Complexity

    O(n)

where `n` is the number of valid outcomes.

---

## Pseudocode
```
    read x, y, a, b

    ans = empty list

    for c from a to x:
        for d from b to y:
            if c > d:
                add (c, d) to ans

    print size of ans

    for each (c, d) in ans:
        print c, d
```

---