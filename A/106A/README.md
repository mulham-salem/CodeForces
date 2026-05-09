# Problem 106A – Card Game

## Overview
In the game **Durak**, each card has:

- A **rank**
- A **suit**

One suit is chosen as the **trump suit**.

Your task is to determine whether the **first card beats the second card** according to the game rules.

---

## Card Rank Order

```text
6 < 7 < 8 < 9 < T < J < Q < K < A
```

---

## Rules

The first card beats the second card if:

1. Both cards have the same suit and the first card has a higher rank.
2. The first card is a trump card and the second card is not.

Otherwise, the answer is `"NO"`.

---

## Input

- First line: the trump suit (`S`, `H`, `D`, or `C`)
- Second line: two cards

Each card consists of:
- Rank + Suit

Example:
```text
QH
```

- `Q` → Rank
- `H` → Suit

---

## Output

Print:

```text
YES
```

if the first card beats the second one, otherwise print:

```text
NO
```

---

## Examples

### Example 1

Input:
```text
H
QH 9S
```

Output:
```text
YES
```

Explanation:

`QH` is a trump card, so it beats `9S`.

---

### Example 2

Input:
```text
S
8D 6D
```

Output:
```text
YES
```

Explanation:

Both cards have the same suit, and `8` is stronger than `6`.

---

### Example 3

Input:
```text
C
7H AS
```

Output:
```text
NO
```

Explanation:

The suits are different, and the first card is not a trump card.

---

## Pseudocode

```
Read trump suit
Read first card and second card

Extract:
- rank1, suit1
- rank2, suit2

If first suit is trump and second suit is not trump
    Print YES

Else if suits are equal AND first rank is stronger
    Print YES

Else
    Print NO
```

---