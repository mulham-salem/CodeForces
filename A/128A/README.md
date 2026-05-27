# Problem 128A – Statues

## Idea

Maria starts at the bottom-left corner of an `8×8` board and wants to reach Anna at the top-right corner.

The board also contains moving statues (`S`).

- Maria moves first.
- After each move, all statues move one row downward.
- If a statue reaches Maria's cell, she loses.
- If Maria reaches Anna, she wins.

The task is to determine whether Maria can survive and reach Anna.

---

## Input

- 8 lines representing the chessboard.
- Each line contains 8 characters.

### Symbols

| Symbol | Meaning |
|---|---|
| `.` | Empty cell |
| `M` | Maria |
| `A` | Anna |
| `S` | Statue |

---

## Output

Print:

| Output | Meaning |
|---|---|
| `WIN` | Maria can reach Anna |
| `LOSE` | Maria cannot survive |

---

## Example 1

### Input

```text
.......A
........
........
........
........
........
........
M.......
```

### Output

```text
WIN
```

### Explanation

There are no statues, so Maria can safely reach Anna.

---

## Example 2

### Input

```text
.......A
........
........
........
........
........
SS......
M.......
```

### Output

```text
LOSE
```

### Explanation

The statues move downward and eventually block or catch Maria.

---

## Approach

We use **BFS (Breadth-First Search)**.

Each state contains:

- Maria's row
- Maria's column
- Current time

At every step:

1. Try all 9 possible moves.
2. Check if the position is safe now.
3. Check if it will remain safe after statues move.
4. Push valid states into the queue.

Since statues move every second, time is important in the search.

---

## Pseudocode

```text
Start BFS from Maria's position

while queue is not empty:

    get current state

    if current cell contains a statue:
        skip

    if time >= 8:
        return WIN

    try all 9 moves:

        if outside board:
            skip

        if current cell has statue:
            skip

        if next turn statue reaches cell:
            skip

        if state not visited:
            mark visited
            push into queue

return LOSE
```

---

## Complexity

| Type | Complexity |
|---|---|
| Time | `O(8 × 8 × 9)` |
| Memory | `O(8 × 8 × 9)` |

---