# Problem 35A – Shell Game

## Overview
In this problem, a performer places a small ball under one of three cups.  
Then he performs **three shuffles**, each time swapping the positions of two cups.

Your task is to determine **which cup contains the ball after all the shuffles**.

The cups are always labeled **1 to 3 from left to right**, and after every shuffle they are **renumbered again from left to right**.

## Key Idea
Instead of tracking all cups, we only need to track **the current position of the ball**.

For every shuffle:

- Two cups `a` and `b` are swapped.
- If the ball is under cup `a`, it moves to `b`.
- If the ball is under cup `b`, it moves to `a`.
- Otherwise, the ball stays in the same position.

This way we simply update the ball's position after each swap.

## Example

### Input

```

1
1 2
2 1
2 1

```

### Explanation

Initial position of the ball:

```

ball = 1

```

Shuffle 1 → swap cups `1` and `2`

```

ball moves from 1 → 2

```

Shuffle 2 → swap cups `2` and `1`

```

ball moves from 2 → 1

```

Shuffle 3 → swap cups `2` and `1`

```

ball moves from 1 → 2

```

### Output

```

2

```

## Pseudocode

```
read ball_position

repeat 3 times
read a, b

if ball_position equals a
    ball_position = b
else if ball_position equals b
    ball_position = a

print ball_position

```

## Complexity

- **Time Complexity:** O(1)  
- **Space Complexity:** O(1)

Since the number of shuffles is fixed (3), the algorithm runs in constant time.
