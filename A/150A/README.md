# Problem 150A – Win or Freeze

## Overview

Two players play a game starting with an integer `q`.

In each move, a player must choose a **non-trivial divisor** of the current number:

- A divisor different from `1`
- And different from the number itself

The chosen divisor becomes the new number.

The player who **cannot make a move wins**.

Your task is to determine:

- Which player wins if both play optimally.
- A winning first move if Player 1 wins.

---

## Key Observation

The game depends on the number of prime factors of `q`.

### Losing Positions

A number is losing if it has exactly **two prime factors** (counting multiplicity).

Examples:

```text
4  = 2 × 2
6  = 2 × 3
9  = 3 × 3
10 = 2 × 5
```

Any move from such numbers leads to a prime number, allowing the next player to win immediately.

### Winning Positions

If a number has **three or more prime factors**, Player 1 can always move to a losing position.

Example:

```text
30 = 2 × 3 × 5
```

Move to:

```text
6 = 2 × 3
```

Since `6` is a losing position, this guarantees a win.

---

## Special Cases

### `q = 1`

No valid move exists.

Player 1 wins immediately.

### Prime Numbers

Prime numbers have no non-trivial divisors.

Player 1 also wins immediately.

---

## Example 1

### Input

```text
6
```

### Output

```text
2
```

### Explanation

Possible moves:

```text
6 → 2
6 → 3
```

Both moves allow Player 2 to win.

---

## Example 2

### Input

```text
30
```

### Output

```text
1
6
```

### Explanation

Player 1 moves:

```text
30 → 6
```

Since `6` is a losing position, Player 1 wins.

---

## Example 3

### Input

```text
1
```

### Output

```text
1
0
```

### Explanation

No valid move exists, so Player 1 wins immediately.

---

## Pseudocode

```text
factorize(q)

if count_prime_factors < 2
    print 1
    print 0

else if count_prime_factors == 2
    print 2

else
    print 1
    print first_prime_factor * second_prime_factor
```

---

## Complexity

### Time Complexity

```text
O(√q)
```

### Space Complexity

```text
O(number of prime factors)
```

---