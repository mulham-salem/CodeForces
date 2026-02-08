# Problem 3A – Shortest path of the king

## 🧠 Problem Overview

The king is alone on a chessboard and needs to move from a starting square **s**
to a target square **t** using the **minimum number of moves**.

In one move, the king can move:
- Horizontally (Left, Right)
- Vertically (Up, Down)
- Diagonally (any combination of horizontal + vertical)

There are **8 possible moves**:
`L, R, U, D, LU, LD, RU, RD`

---

## 📥 Input

- The first line contains the starting square `s`
- The second line contains the target square `t`

Each square is described by:
- A lowercase letter from `a` to `h` (column)
- A digit from `1` to `8` (row)

---

## 📤 Output

- Print the minimum number of moves `n`
- Then print `n` lines, each describing one move
- If multiple answers exist, print any of them

---

## 💡 Key Idea

The king should always move **closer to the target**.

- If both row and column are different → move **diagonally**
- If only one is different → move **straight**
- Each move reduces the distance to the target
- This guarantees the minimum number of moves

---

## 🧩 Examples

### Example 1

**Input**
```

a1
c3

```

**Explanation**

- Move Right + Up twice
- Diagonal moves reduce both directions at once

**Output**
```

2
RU
RU

```

---

### Example 2

**Input**
```

a8
h1

```

**Explanation**

- Always move Right + Down
- Repeat until reaching the target

**Output**
```

7
RD
RD
RD
RD
RD
RD
RD

````

---

## 📝 Pseudo-code

```text
read s, t

convert s and t to numeric coordinates (x1, y1) and (x2, y2)

moves = empty list

while (x1 != x2 OR y1 != y2):
    move = ""

    if x1 < x2:
        move += "R"
        x1++
    else if x1 > x2:
        move += "L"
        x1--

    if y1 < y2:
        move += "U"
        y1++
    else if y1 > y2:
        move += "D"
        y1--

    add move to moves

print number of moves
print all moves
````

---

## ✅ Notes

* No chessboard simulation is needed
* Only simple comparisons and loops
* Time complexity is constant
* Any valid shortest path is accepted

---