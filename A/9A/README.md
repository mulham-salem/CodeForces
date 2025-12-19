# Problem 9A – Die Roll

## Problem Summary
You are given an integer `n` representing the total sum you need to reach by rolling a standard six-sided die.  
Your task is to find **any sequence of dice rolls** (numbers from 1 to 6) that sums exactly to `n`. If multiple sequences exist, any valid one is accepted.

## Input
- Single integer `n` (1 ≤ n ≤ 100)

## Output
- First line: the number of rolls in the sequence
- Second line: the sequence of numbers (space-separated) from 1 to 6, summing exactly to `n`.

## Example

**Input:**
```

8

```

**Output:**
```

2
2 6

```

**Explanation:**
- One possible sequence is rolling a 2 and then a 6, which sums to 8.
- Another valid sequence could be 3 + 5, or 1 + 1 + 6. Any sequence that sums to 8 is accepted.

## Solution Idea
- Start adding 6s until the remaining sum is less than 6, then add the remaining number as the last roll.
- This guarantees the total sum is `n` and each number is between 1 and 6.
- Example for `n=8`: use `6` first (remaining 2), then `2`. Sequence: `6 2`.

