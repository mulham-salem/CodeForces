# Problem 197A – Plate Game

## Idea

The game depends only on whether **at least one plate can fit on the table**.

A plate with radius `r` has a diameter of `2 × r`. Therefore, a plate can be placed only if both table dimensions are at least the plate's diameter.

- If the table cannot hold even one plate, the first player has no move and loses.
- Otherwise, exactly one plate can be placed, so the first player makes the only move and wins.

---

## Algorithm

1. Read `a`, `b`, and `r`.
2. Check whether both `a >= 2 × r` and `b >= 2 × r`.
3. If true, print `"First"`.
4. Otherwise, print `"Second"`.

---

## Example

### Input
```text
5 5 2
```

### Explanation

The plate diameter is `4`, and both table dimensions are at least `4`, so one plate can be placed.

The first player places the only possible plate, leaving no move for the second player.

**Output**
```text
First
```

---

### Input
```text
6 7 4
```

### Explanation

The plate diameter is `8`, which is larger than both table dimensions.

No plate can be placed, so the first player loses immediately.

**Output**
```text
Second
```

---

## Pseudocode

```text
Read a, b, r

IF a >= 2 × r AND b >= 2 × r
    Print "First"
ELSE
    Print "Second"
END IF
```

---

## Complexity Analysis

- **Time Complexity:** `O(1)`
- **Space Complexity:** `O(1)`

---