# Problem 381A – Sereja and Dima

## Problem Description

Sereja and Dima are playing a game using a row of cards.

- There are `n` cards placed in a row.
- Each card has a number written on it.
- Two players play alternately:
  - **Sereja always starts first**.
- On each turn, a player takes **one card**:
  - Either the **leftmost** card
  - Or the **rightmost** card
- Each player adds the value of the taken card to their score.
- Both players play **optimally** (they always choose the better option for themselves).

Your task is to calculate the **final scores** of Sereja and Dima.

---

## Rules

1. Read the number of cards `n`.
2. Read the values written on the cards.
3. Initialize two scores:
   - `Sereja = 0`
   - `Dima = 0`
4. Players take turns:
   - On each turn, the player picks the **larger** value between the leftmost and rightmost cards.
   - Remove the chosen card from the row.
5. Continue until all cards are taken.
6. Output Sereja’s score and Dima’s score.

---

## Key Observation

Since players only choose between **two ends**, and both want to maximize their score:
- The optimal strategy is always to take the **maximum** of the two available ends.

No complex game theory is needed.

---

## Examples

### Example 1

**Input**
```

4
4 1 2 10

```

**Analysis**

Initial cards: `[4, 1, 2, 10]`

| Turn | Player | Choices | Chosen | Scores |
|----|--------|---------|--------|--------|
| 1 | Sereja | 4 vs 10 | 10 | S=10, D=0 |
| 2 | Dima | 4 vs 2 | 4 | S=10, D=4 |
| 3 | Sereja | 1 vs 2 | 2 | S=12, D=4 |
| 4 | Dima | 1 | 1 | S=12, D=5 |

**Output**
```

12 5

```

---

### Example 2

**Input**
```

5
1 2 3 4 5

```

**Analysis**

Initial cards: `[1, 2, 3, 4, 5]`

| Turn | Player | Choices | Chosen | Scores |
|----|--------|---------|--------|--------|
| 1 | Sereja | 1 vs 5 | 5 | S=5, D=0 |
| 2 | Dima | 1 vs 4 | 4 | S=5, D=4 |
| 3 | Sereja | 1 vs 3 | 3 | S=8, D=4 |
| 4 | Dima | 1 vs 2 | 2 | S=8, D=6 |
| 5 | Sereja | 1 | 1 | S=9, D=6 |

**Output**
```

9 6

```

---

## Step-by-Step Logic

1. Use two pointers:
   - `l` → start of the array
   - `r` → end of the array
2. Use a boolean flag to track turns:
   - `true` → Sereja’s turn
   - `false` → Dima’s turn
3. At each step:
   - Compare `cards[l]` and `cards[r]`
   - Take the larger value
   - Update the corresponding score
   - Move the pointer inward
4. Continue until `l > r`.

---

## Key Notes

- Sereja always starts.
- Only the two ends of the array can be chosen.
- Greedy choice works because players are restricted to ends only.
- This problem focuses on:
  - Greedy strategy
  - Two-pointer technique
  - Turn-based simulation

This is a simple and classic problem for practicing greedy algorithms and simulation.
