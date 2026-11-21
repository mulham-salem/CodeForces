# Problem 377A – Maze

## Problem Summary

Pavel has an `n × m` grid maze where each cell is either empty (`.`) or a wall (`#`). The empty cells form **one single connected component** (you can reach any empty cell from any other by moving up/down/left/right through empty cells).

Pavel wants to turn **exactly `k`** empty cells into walls (`X`) — but with a constraint: after the conversion, the **remaining empty cells must still form a single connected area**. We are guaranteed at least one valid solution exists, and we may output any valid answer.

### Input
- First line: `n`, `m`, `k` where `0 ≤ k < s` (`s` = number of empty cells originally).
- Next `n` lines: the maze, with `.` = empty, `#` = wall.

### Output
- Print the modified maze with exactly `k` empty cells changed to `X`, leaving `.` and `#` unchanged elsewhere.

---

## Key Insight

Directly picking `k` cells to remove is tricky — removing the "wrong" cells could **disconnect** the remaining area.

**Flip the perspective:** Instead of removing `k` cells, **keep `s - k` cells** and turn all the rest into walls.

If we run a DFS starting from any empty cell, the DFS visits cells in an order where **every newly visited cell is adjacent to an already-visited one**. So if we simply keep the **first `s - k` cells visited by DFS** and mark the remaining empty cells as `X`, the kept cells are guaranteed to remain connected.

- Kept cells → still `.`
- Unvisited empty cells (after DFS visited `s - k` of them) → become `X`
- Original `#` walls → untouched

---

## Step-by-Step Algorithm

1. Read `n`, `m`, `k`, and the grid.
2. Count `totalEmpty` = number of `.` cells. Let `keep = totalEmpty - k`.
3. Find any empty cell — that's the DFS starting point.
4. Run DFS:
   - Mark the cell visited.
   - If `keep > 0`, decrement `keep` and leave the cell as `.`.
   - Otherwise, change it to `X`.
   - Recurse into the 4 neighbors (only if `.` and unvisited).
5. Print the modified grid.

> **Why is this safe?** DFS visits cells in connected order — the first `keep` cells visited form a connected subset containing the start cell. Every other empty cell becomes a wall, so no disconnected fragment remains.

---

## Example 1

**Input:**
```

3 4 2
#..#
..#.
#...

```

`s = 6`, `k = 2`, so `keep = 4`. DFS starts at `(0,1)` and visits 4 cells to keep; the last 2 empties become `X`.

**Output:**
```

#.X#
X.#.
#...

```

---

## Example 2

**Input:**
```

5 4 5
#...
#.#.
.#..
...#
.#.#

```

`s = 10`, `k = 5`, so `keep = 5`. DFS keeps 5 connected cells and turns the remaining 5 into `X`.

**Output:**
```

#XXX
#X#.
X#..
...#
.#.#

```

---

## Pseudocode

```

read n, m, k
read grid
count totalEmpty ('.' cells)
keep = totalEmpty - k

visited = 2D array of false

function dfs(x, y):
	if (x, y) out of bounds: return
	if grid[x][y] == '#' or visited[x][y]: return

	visited[x][y] = true

	if keep > 0:
		keep = keep - 1        // this cell stays '.'
	else:
		grid[x][y] = 'X'       // this cell becomes a wall

	for each (nx, ny) in [(x-1,y), (x+1,y), (x,y-1), (x,y+1)]:
		dfs(nx, ny)
	
find first '.' cell (sx, sy)
dfs(sx, sy)

print grid

```

---

## Complexity

- **Time:** `O(n · m)` — every cell is visited at most once.
- **Space:** `O(n · m)` — for the `visited` array and the DFS recursion stack (could be deep, up to `n·m`).

> **Note:** For `n, m ≤ 500`, recursion depth may reach `250,000` in the worst case — in C++ this usually still passes with an increased stack or by using an iterative DFS/BFS. BFS with a queue is a safer alternative and produces an equally valid connected ordering.
