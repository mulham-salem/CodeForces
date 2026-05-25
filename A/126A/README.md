# Problem 126A – Hot Bath

## Idea

Bob wants to fill a bath using two taps:

- Cold water tap with temperature `t1`
- Hot water tap with temperature `t2`

We need to choose:

- `y1` units from the cold tap
- `y2` units from the hot tap

Such that:

1. The final temperature is **not less than** `t0`
2. The temperature is as close as possible to `t0`
3. If multiple answers exist, choose the one with the **maximum total flow** (`y1 + y2`)

---

## Final Temperature Formula

```text
(y1 * t1 + y2 * t2) / (y1 + y2)
```

---

## Observation

For every possible amount of hot water `y2`:

- Compute the maximum valid cold water `y1`
- Ensure the temperature is still `>= t0`
- Compare with the best answer found so far

Instead of checking all pairs `(y1, y2)`,
we iterate only over `y2`.

---

## Example 1

### Input
```text
10 70 100 100 25
```

### Output
```text
99 33
```

### Explanation

Using:

- `99` cold units
- `33` hot units

Produces:

```text
(99 * 10 + 33 * 70) / (99 + 33) = 25
```

Perfect temperature.

---

## Example 2

### Input
```text
300 500 1000 1000 300
```

### Output
```text
1000 0
```

### Explanation

Cold water already has temperature `300`,
which equals `t0`.

So using only cold water is optimal,
and we maximize flow speed.

---

## Pseudocode

```text
best answer = none

for every possible y2:

    compute best possible y1

    while temperature < t0:
        decrease y1

    if current solution is better:
        save it

print best answer
```

---

## Complexity

```text
Time:  O(x2)
Memory: O(1)
```

---