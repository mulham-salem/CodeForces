# Problem 173A – Rock-Paper-Scissors

## Overview

Two players repeatedly play **Rock-Paper-Scissors** for **`n`** rounds.

- Nikephoros repeats the moves in string **A** cyclically.
- Polycarpus repeats the moves in string **B** cyclically.

For each round:

- **Rock (R)** beats **Scissors (S)**.
- **Scissors (S)** beats **Paper (P)**.
- **Paper (P)** beats **Rock (R)**.
- If both players choose the same move, the round ends in a draw.

The goal is to determine how many rounds each player loses after exactly **`n`** rounds.

---

## Example

### Input

```text
7
RPS
RSPP
```

### Round Simulation

| Round | Nikephoros | Polycarpus | Result |
|:-----:|:----------:|:----------:|:------:|
| 1 | R | R | Draw |
| 2 | P | S | Nikephoros loses |
| 3 | S | P | Polycarpus loses |
| 4 | R | P | Nikephoros loses |
| 5 | P | R | Polycarpus loses |
| 6 | S | S | Draw |
| 7 | R | P | Nikephoros loses |

### Output

```text
3 2
```

---

## Key Idea

Since both strings repeat forever, the sequence of rounds also repeats after

`LCM(length(A), length(B))`

rounds.

Instead of simulating all **`n`** rounds:

1. Simulate one complete repeating cycle.
2. Count the losses in that cycle.
3. Multiply the counts by the number of complete cycles.
4. Simulate only the remaining rounds.

This avoids iterating up to `2 × 10^9` rounds.

---

## Pseudocode

```text
read n
read A, B

cycleLength = LCM(length(A), length(B))

nikeLosses = 0
polyLosses = 0

simulate one complete cycle:
    compare current moves
    count who loses each round

fullCycles = n / cycleLength
remainingRounds = n % cycleLength

answerNike = nikeLosses * fullCycles
answerPoly = polyLosses * fullCycles

simulate the remaining rounds
update the answers

print answerNike, answerPoly
```

---

## Complexity

- **Time Complexity:** `O(LCM(|A|, |B|))`
- **Space Complexity:** `O(1)`

---