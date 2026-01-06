# Problem 199A – Hexadecimal's Theorem

## Requirement
You are given:

- An integer **n** (0 ≤ n < 10⁹)
- It is guaranteed that **n** is a Fibonacci number

Fibonacci numbers are defined as:

- F₀ = 0  
- F₁ = 1  
- Fᵢ = Fᵢ₋₁ + Fᵢ₋₂  

Fibonacci sequence example:

0, 1, 1, 2, 3, 5, 8, 13, ...

Your task is to find **three Fibonacci numbers** `a`, `b`, and `c`
(not necessarily different) such that:

a + b + c = n

If there are multiple answers, print any of them.  
If there is no solution, print:

"I'm too stupid to solve this problem"

---

## Input
One integer **n** — a Fibonacci number.

---

## Output
Three integers **a**, **b**, **c** — Fibonacci numbers whose sum equals **n**.

---

## Examples

### Example 1
**Input**
```

3

```

**Output**
```

1 1 1

```

**Explanation**

1 + 1 + 1 = 3  
All numbers belong to the Fibonacci sequence.

---

### Example 2
**Input**
```

13

```

**Output**
```

8 5 0

```

**Explanation**

13 is a Fibonacci number.  
The two previous Fibonacci numbers are 8 and 5.  
8 + 5 + 0 = 13  
0 is also a Fibonacci number.

---

## Solution Idea
For every Fibonacci number `n` (except 0 and 1):

n = F(k−1) + F(k−2)

So it can always be written as:

n = F(k−1) + F(k−2) + 0

All three numbers are Fibonacci numbers, and they are not required to be different.

Special cases:
- n = 0 → 0 0 0
- n = 1 → 0 0 1

---

## Algorithm
1. Handle special cases (0 and 1).
2. Generate Fibonacci numbers until reaching `n`.
3. Take the two Fibonacci numbers before `n`.
4. Output those two numbers and `0`.

---

## Complexity
- **Time Complexity:** O(k), where k is the index of `n` in the Fibonacci sequence.
- **Space Complexity:** O(1)

---

## Key Insight
Every Fibonacci number is the sum of the two previous Fibonacci numbers.
Adding `0` (which is also Fibonacci) guarantees a valid representation using three Fibonacci numbers.
