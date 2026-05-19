# Problem 119A – Epic Game

## Overview

Two players, Simon and Antisimon, play a game using a pile of stones.

- Simon has a fixed number `a`
- Antisimon has a fixed number `b`
- The pile initially contains `n` stones

Players take turns removing stones from the pile:

- Simon moves first
- On each turn, the player removes:

```math
gcd(player_number, remaining_stones)
```

stones from the pile.

The player who cannot make a valid move loses.

---

## Input

The input contains three integers:

```text
a b n
```

Where:

- `a` → Simon's number
- `b` → Antisimon's number
- `n` → Initial number of stones

---

## Output

Print:

- `0` → if Simon wins
- `1` → if Antisimon wins

---

## Example 1

### Input

```text
3 5 9
```

### Simulation

| Turn | Player | Removed Stones | Remaining Stones |
|------|----------|----------------|------------------|
| 1 | Simon | gcd(3, 9) = 3 | 6 |
| 2 | Antisimon | gcd(5, 6) = 1 | 5 |
| 3 | Simon | gcd(3, 5) = 1 | 4 |
| 4 | Antisimon | gcd(5, 4) = 1 | 3 |
| 5 | Simon | gcd(3, 3) = 3 | 0 |

Antisimon cannot make the next move, so Simon wins.

### Output

```text
0
```

---

## Example 2

### Input

```text
1 1 100
```

### Explanation

Since:

```math
gcd(1, x) = 1
```

each player removes exactly one stone every turn.

Because `100` is even, Antisimon removes the last stone, so Simon loses.

### Output

```text
1
```

---

## Key Idea

The problem is a simple simulation.

At every turn:

1. Compute the `gcd`
2. Remove that amount from the pile
3. Switch turns
4. If a player cannot remove stones, he loses

---

## Pseudocode

```text
while true:

    simon_move = gcd(a, n)

    if n < simon_move:
        print 1
        break

    n -= simon_move


    antisimon_move = gcd(b, n)

    if n < antisimon_move:
        print 0
        break

    n -= antisimon_move
```

---

## Complexity Analysis

| Type | Complexity |
|------|-------------|
| Time Complexity | O(number of turns × log(n)) |
| Memory Complexity | O(1) |

---