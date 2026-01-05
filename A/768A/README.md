# Problem 768A – Oath of the Night’s Watch

## Problem Summary
The Night’s Watch has n brothers standing in a line.
Each brother either wants to sit (`0`) or stand (`1`).

Your task:

Determine the minimum number of brothers who need to **change their position**
so that all sitting brothers are **to the left** of all standing brothers.

---

## Key Idea
This is a classic "minimum swaps to partition" problem.

- Count the number of inversions:
  - A sitting brother (`0`) after a standing brother (`1`) needs to move.
- Iterate through the line and compute the minimal number of moves.

Simpler approach:
- Count prefix sums of standing brothers and suffix sums of sitting brothers.
- The minimal sum of moves gives the answer.

---

## Example 1

Input
4  
1 0 1 0

Explanation
Initial: 1 0 1 0  
Goal: all 0s to the left, 1s to the right.

One solution:
- Swap positions of 0 at index 2 with 1 at index 1
- Swap positions of 0 at index 4 with 1 at index 3

Minimum moves = 2

Output
2

---

## Example 2

Input
3  
0 0 1

Explanation
Already all 0s to the left and 1s to the right.

Output
0

---

## Pseudocode
read n
read array brothers

left_ones = 0
right_zeros = count of zeros in the array

min_moves = right_zeros

for i from 0 to n-1:
    if brothers[i] == 1:
        left_ones += 1
    else:
        right_zeros -= 1
    min_moves = min(min_moves, left_ones + right_zeros)

print min_moves

---

## Final Notes
- Greedy / prefix-suffix counting problem
- Time complexity: O(n)
- Space complexity: O(n) or O(1) with optimized variables
- Simple logic but careful counting needed