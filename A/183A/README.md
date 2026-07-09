# Problem 183A – Headquarters

## Problem Description

A car moves on a 2D grid from the gang's headquarters to an ice cream stall located at point `(0, 0)`.

The car makes `n` movements, but the GPS recorder does not know the exact direction of each movement.

Instead, every movement is recorded as a string representing possible directions:

- `UL` → the movement was either `U` or `L`
- `UR` → the movement was either `U` or `R`
- `DL` → the movement was either `D` or `L`
- `DR` → the movement was either `D` or `R`
- `ULDR` → the movement was one of the four directions

The records are given in chronological order.

The task is to find how many different points could be the starting position of the car.

---

## Input

The first line contains:

n

The number of movements.

The next `n` lines contain one movement description.

Each description is one of:

UL UR DL DR ULDR

---

## Output

Print one integer:

The number of possible positions of the headquarters.

---

## Examples

### Example 1

#### Input

3 UR UL ULDR

#### Explanation

Each movement has multiple possible directions.

After considering all possible choices, there are 9 different displacements that can lead the car to `(0,0)`.

Therefore, there are 9 possible headquarters locations.

#### Output

9

---

### Example 2

#### Input

2 DR DL

#### Explanation

The possible movement sequences create 4 different final displacements.

Since the destination is fixed at `(0,0)`, every displacement corresponds to one possible starting point.

#### Output

4

---

## Approach

Trying every possible movement sequence is impossible because `n` can be as large as `200000`.

Instead of generating paths, we maintain the range of all possible displacements.

For every movement we track:

- Minimum and maximum `x`
- Minimum and maximum `y`
- Minimum and maximum `x + y`
- Minimum and maximum `x - y`

The values `x + y` and `x - y` are useful because they represent diagonal constraints and allow us to filter valid points efficiently.

For every possible headquarters position `(x, y)`:

x must be inside the possible x range y must be inside the possible y range

x + y must be inside the possible x+y range

x - y must be inside the possible x-y range

The solution iterates over all possible `x` values and calculates the valid interval of `y` values using these constraints.

Finally, it checks the parity condition because:

x + y x - y

must have the same parity to produce integer coordinates.

---

## Key Observations

The final position of the car is always:

(0,0)

If the total displacement of a chosen path is:

(dx, dy)

then the starting position must be:

(-dx, -dy)

Therefore, counting possible starting points is equivalent to counting all possible final displacements.

---

## Complexity Analysis

Let `n` be the number of movements.

- Time Complexity: `O(n + R)`

where `R` is the range of possible `x` values.

- Space Complexity: `O(n)`

for storing the movement list.

---
