# Problem 275A – Lights Out

## Problem Summary
You have a 3x3 grid of lights. Initially, **all lights are ON**.  
You are given a 3x3 matrix of integers (0 or 1), representing how many times each light’s button has been pressed.

Rules:
- Pressing a button toggles the light itself **and** its adjacent neighbors (up, down, left, right).
- If a button is pressed an even number of times, the net effect is as if it was **not pressed** (light returns to its original state).

## Input
- 3x3 matrix of integers (0 or 1), each value `a[i][j]`

## Output
- Final state of the lights (1 = ON, 0 = OFF)
- Format: 3 lines, each line with 3 digits (no spaces)

## Example

**Input:**
```

1 0 0
0 0 0
0 0 1

```

**Output:**
```

001
010
100

```

**Explanation:**
- The top-left light was pressed once: it and its neighbors are toggled → some lights turn OFF.
- The bottom-right light was pressed once: it and its neighbors are toggled → some lights turn OFF.
- Any light affected by an **even** number of presses remains ON.
- Resulting grid after applying all presses:

```

0 0 1
0 1 0
1 0 0

````

## Solution Idea
1. For each light `(i,j)` calculate the **total number of presses affecting it**:
   - itself + neighbors
2. If total presses are **odd** → light is OFF (0)  
   If total presses are **even** → light remains ON (1)
3. Iterate over all lights to build the final grid.

```cpp
final[i][j] = 1 if total_presses % 2 == 0 else 0
````

* Use boundary checks for neighbors to avoid accessing outside the 3x3 grid.
