# Problem 118A – Epic Game

## Requirement

You are given three integers `a`, `b`, and `n`.

Two players play a game in turns:
- The first player uses number `a`.
- The second player uses number `b`.

Starting from `n`, players alternate turns.
On each turn, a player subtracts the **greatest common divisor (GCD)** of their number and the current value of `n`.

**Goal:**  
Determine which player wins the game.

- Print `0` if the **first player** wins.
- Print `1` if the **second player** wins.

---

## Input

- Three integers: `a`, `b`, `n`
  - `1 ≤ a, b, n ≤ 100`

---

## Output

- One integer:
  - `0` → first player wins
  - `1` → second player wins

---

## Examples

### Example 1

**Input**
```

3 5 9

```

**Output**
```

0

```

**Explanation**
```

Player 1:
gcd(3, 9) = 3 → n = 9 - 3 = 6

Player 2:
gcd(5, 6) = 1 → n = 6 - 1 = 5

Player 1:
gcd(3, 5) = 1 → n = 5 - 1 = 4

Player 2:
gcd(5, 4) = 1 → n = 4 - 1 = 3

Player 1:
gcd(3, 3) = 3 → n = 3 - 3 = 0

Player 2 cannot move → Player 1 wins

```

---

## Solution Idea

1. Start with value `n`.
2. Players take turns:
   - Player 1 subtracts `gcd(a, n)`
   - Player 2 subtracts `gcd(b, n)`
3. If a player cannot make a move (gcd = 0), they lose.
4. Output the winner.

---

## Complexity

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---