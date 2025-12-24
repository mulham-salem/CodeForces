# Problem 148A – Insomnia cure

## Requirement

A princess is being attacked by dragons.

She uses several spells, each one affects dragons whose numbers are divisible by a certain value.

You are given four integers `k`, `l`, `m`, `n` and one integer `d`:

- Every `k`-th dragon is damaged by the first spell
- Every `l`-th dragon is damaged by the second spell
- Every `m`-th dragon is damaged by the third spell
- Every `n`-th dragon is damaged by the fourth spell

Dragons are numbered from `1` to `d`.

**Goal:**  
Find how many dragons are damaged by **at least one** spell.

---

## Input

- Five integers: `k`, `l`, `m`, `n`, `d`
  - `1 ≤ k, l, m, n ≤ 10`
  - `1 ≤ d ≤ 100000`

---

## Output

- One integer: the number of damaged dragons

---

## Examples

### Example 1

**Input**
```

1 2 3 4 12

```

**Output**
```

12

```

**Explanation**
```

k = 1 → every dragon is damaged
So all 12 dragons are affected.

```

---

### Example 2

**Input**
```

2 3 4 5 24

```

**Output**
```

17

```

**Explanation**
```

A dragon is damaged if its number is divisible by:
2 or 3 or 4 or 5

We count how many numbers from 1 to 24 satisfy at least one of these conditions.
The total is 17.

```

---

## Solution Idea

1. Initialize a counter to zero.
2. For each dragon number `i` from `1` to `d`:
   - If `i` is divisible by `k` **or**
     divisible by `l` **or**
     divisible by `m` **or**
     divisible by `n`,
     then this dragon is damaged.
3. Count all such dragons.
4. Output the result.

---

## Complexity

- **Time Complexity:** `O(d)`
- **Space Complexity:** `O(1)`

---