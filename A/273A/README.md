# Problem 273A – Dima and Staircase

## Problem Description

Dima has a staircase consisting of `n` stairs. The first stair is at height `a1`, the second at `a2`, and so on. The heights are given in non-decreasing order (`a1 ≤ a2 ≤ ... ≤ an`).

Dima throws rectangular boxes vertically down onto the staircase from above. The `i-th` box has:
- **Width `wi`**: covers the first `wi` stairs (stairs 1 through `wi`)
- **Height `hi`**: the vertical size of the box

Each box falls vertically until either:
1. The **bottom of the box touches the top of a stair**, or
2. The **bottom of the box touches the top of a previously thrown box**

**Important**: Only horizontal side touches count (corner touches are ignored). A box of width `wi` cannot touch stair number `wi + 1`.

For each box, determine the **height of the bottom of the box** after it lands.

---

## Input Format

- **First line**: `n` (1 ≤ n ≤ 10⁵) — number of stairs
- **Second line**: `n` integers `a1, a2, ..., an` — non-decreasing stair heights (1 ≤ ai ≤ 10⁹)
- **Third line**: `m` (1 ≤ m ≤ 10⁵) — number of boxes
- **Next `m` lines**: each contains two integers `wi, hi` (1 ≤ wi ≤ n, 1 ≤ hi ≤ 10⁹)

---

## Output Format

Print `m` integers — the landing height of the bottom of each box, in the order they were thrown. Each answer on a new line.

---

## Examples

### Example 1
**Input**:
```

5
1 2 3 6 6
4
1 1
3 1
1 1
4 3

```

**Output**:
```

1
3
4
6

```

**Explanation**:
- Box 1 (`w=1, h=1`): Touches stair 1 → bottom at `1`
- Box 2 (`w=3, h=1`): Touches highest among stairs 1-3 (height `3`) → bottom at `3`
- Box 3 (`w=1, h=1`): Touches previous box (height `3 + 1 = 4`) → bottom at `4`
- Box 4 (`w=4, h=3`): Touches highest among stairs 1-4 (height `6`) → bottom at `6`

---

### Example 2
**Input**:
```

3
1 2 3
2
1 1
3 1

```

**Output**:
```

1
3

```

---

### Example 3
**Input**:
```

1
1
5
1 2
1 10
1 10
1 10
1 10

```

**Output**:
```

1
3
13
23
33

```

**Explanation**: 
Only one stair (height `1`). 
Boxes stack on top of each other. 
Each new box lands on top of the previous one, adding its height.

---

## Solution Approach

### Key Observations

1. For a box of width `w`, it can only touch stairs `1` through `w`.
2. The box will stop at the **highest point** within its covered area — either:
   - The highest stair among `1...w`
   - The top of the highest previously placed box in that area
3. Since all boxes cover a **prefix** of the staircase (starting from stair 1), we only need to track:
   - The maximum height reached by the **most recent box** (`current_height`)
   - The maximum stair height among the first `w` stairs

### Optimization

Instead of scanning stairs `1...w` for each box (which would be O(n·m)), we precompute prefix maximums:
- Transform the stair height array so that `a[i]` = max height among stairs `1...i+1`
- This allows O(1) lookup for the highest stair in any prefix

### Algorithm (Pseudo-code)

```

Read n
Read array a[0...n-1]

// Convert to prefix maximums
for i = 1 to n-1:
a[i] = max(a[i], a[i-1])

Read m
current_height = 0  // top of the last thrown box

for each box (w, h):
base_height = a[w-1]         // highest stair in covered range
bottom_height = max(current_height, base_height)
print bottom_height
current_height = bottom_height + h   // new top after this box

```

---

### Complexity
- **Time**: `O(n + m)`
- **Space**: `O(n)`

---

## Notes

- Use 64-bit integers (`long long`) since heights can exceed 32-bit range.
- The prefix maximum transformation is crucial for performance with large inputs.
- The variable `current_height` always represents the top of the **last thrown box**, not the maximum overall height.

---