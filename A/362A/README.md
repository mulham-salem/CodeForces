# Problem 362A – Two Semiknights Meet

## 📌 Problem Summary

Two **semiknights** are placed on an `8 × 8` chessboard. A semiknight moves in any of these four directions:

- 2 squares forward + 2 squares right
- 2 squares forward + 2 squares left
- 2 squares backward + 2 squares right
- 2 squares backward + 2 squares left

Both semiknights move **simultaneously** (one move each per turn). They can meet if they land on the **same square at the same time**. A meeting counts **only if the square is good** (`.` or `K`). Bad squares (`#`) can be passed through but **cannot** be meeting points.

Given multiple boards, determine for each board whether the two semiknights can ever meet on a good square.

---

## 💡 Key Observation

Each semiknight's move changes **both** its row and column by exactly `±2`. This means:

- The **row parity** never changes (row stays even/odd).
- The **column parity** never changes (column stays even/odd).

More importantly, look at the coordinates **modulo 4**. Since every move changes a coordinate by `±2`, and both knights move simultaneously, the **difference** between their positions changes by a multiple of `4` in each coordinate (because `±2 - (±2)` gives `0`, `±4`).

Therefore:

> **Two semiknights can meet if and only if:**
```

|r1 - r2| % 4 == 0  AND  |c1 - c2| % 4 == 0

```

If this condition holds, they can always arrange to meet on some good square (the K squares are guaranteed to be good). Otherwise, they can never meet.

---

## 🧪 Examples

### Example 1 (from statement) → YES

```
........
........
......#.
K..##..#
.......#
...##..#
......#.
K.......
```

· Knight 1: (4, 1) → 0-indexed (3, 0)
· Knight 2: (8, 1) → 0-indexed (7, 0)

```
|3 - 7| = 4 → 4 % 4 = 0 ✅
|0 - 0| = 0 → 0 % 4 = 0 ✅
```

→ YES

---

### Example 2 (from statement) → NO

```
........
........
..#.....
..#..#..
..####..
...##...
........
....K#K#
```

· Knight 1: (8, 5) → (7, 4)
· Knight 2: (8, 7) → (7, 6)

```
|7 - 7| = 0 → 0 % 4 = 0 ✅
|4 - 6| = 2 → 2 % 4 = 2 ❌
```

→ NO

---

## 🧾 Pseudocode

```text
read t
for each test case:
    read 8x8 board
    find positions of both 'K' → (r1, c1) and (r2, c2)
    if abs(r1 - r2) % 4 == 0 AND abs(c1 - c2) % 4 == 0:
        print "YES"
    else:
        print "NO"
```

---

## ⏱ Complexity

· **Time:** `O(1)` per test case (fixed 8×8 board)
· **Space:** `O(1)`
