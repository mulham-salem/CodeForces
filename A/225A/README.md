# Problem 225A – Dice Tower

## Requirement

You are given a dice tower game.

- A standard dice has numbers from `1` to `6`.
- Opposite faces on a dice always sum to `7`.

You are given:
- An integer `n` — the number of moves.
- An integer `x` — the number on the **top face** of the dice at the start.
- Then `n` pairs of integers `(a, b)` representing the two **visible side faces** after each move.

**Goal:**  
Determine whether the dice configuration is **possible** after all moves.

Print `"YES"` if the configuration is possible, otherwise print `"NO"`.

---

## Input

- First line: integer `n` — number of moves
- Second line: integer `x` — top face number
- Next `n` lines: two integers `a` and `b` — visible side faces

Constraints:
- `1 ≤ n ≤ 100`
- All dice values are between `1` and `6`

---

## Output

- Print `"YES"` if the situation is possible
- Print `"NO"` otherwise

---

## Rules to Remember

- The **bottom face** is always `7 - top`.
- The two visible side faces **cannot** be:
  - the top face
  - the bottom face

---

## Examples

### Example 1

**Input**
```

2
1
2 3
4 5

```

**Output**
```

YES

```

**Explanation**
```

Initial top = 1 → bottom = 6
Move 1: visible faces 2 and 3 (valid)
Move 2: visible faces 4 and 5 (valid)
All moves are consistent.

```

---

### Example 2

**Input**
```

1
6
6 1

```

**Output**
```

NO

```

**Explanation**
```

Top = 6 → bottom = 1
Visible faces cannot include top or bottom,
but (6, 1) includes both → invalid.

```

---

## Solution Idea

1. Keep track of the current **top face**.
2. For each move:
   - Compute `bottom = 7 - top`.
   - If `a` or `b` equals `top` or `bottom`, print `"NO"`.
   - Otherwise, the move is valid and the top face remains unchanged.
3. If all moves are valid, print `"YES"`.

---

## Complexity

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---