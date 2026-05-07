# Problem 104A – Blackjack

## Overview
In this problem, the first card is always the **Queen of Spades**, which is worth **10 points**.

You are given a target value `n`, and you need to determine how many possible second cards can make the total score exactly equal to `n`.

---

## Card Values

| Card Type | Points |
|---|---|
| 2 → 10 | Same as the number |
| J, Q, K | 10 |
| Ace | 1 or 11 |

---

## Main Idea

Since the first card already gives `10` points:

```text
needed = n - 10
```

Now we check how many cards can produce this value.

### Cases

- If `needed` is between `2` and `9`
  → there are `4` possible cards.

- If `needed` is `1` or `11`
  → only Aces work, so answer is `4`.

- If `needed` is `10`
  → possible cards are:
  - 10
  - Jack
  - Queen
  - King

  Total:
  ```text
  16 cards
  ```

  But the Queen of Spades is already used:

  ```text
  16 - 1 = 15
  ```

- Otherwise
  → answer is `0`.

---

## Example 1

### Input
```text
12
```

### Explanation
```text
12 - 10 = 2
```

There are four cards with value `2`.

### Output
```text
4
```

---

## Example 2

### Input
```text
20
```

### Explanation
```text
20 - 10 = 10
```

Cards worth `10`:
- 10
- J
- Q
- K

Total = `16`, but one Queen is already used.

### Output
```text
15
```

---

## Pseudo Code

```
read n

needed = n - 10

if needed == 10
    print 15

else if needed is between 2 and 9
    print 4

else if needed == 1 or needed == 11
    print 4

else
    print 0
```