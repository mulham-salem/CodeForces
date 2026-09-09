# Problem 284A – Cows and Primitive Roots

## Problem Summary
Given a prime number `p` (2 ≤ p < 2000), find the number of primitive roots modulo `p`.

A primitive root `x` (1 ≤ x < p) satisfies:
- None of `x¹ - 1, x² - 1, ..., x^(p-2) - 1` are divisible by `p`
- But `x^(p-1) - 1` is divisible by `p`

---

## Key Insight
For a prime `p`, the number of primitive roots modulo `p` is **φ(p-1)**, where φ is Euler's totient function.

This is because:
- The multiplicative group modulo `p` is cyclic of order `p-1`
- Primitive roots are exactly the generators of this cyclic group
- Number of generators in a cyclic group of order `n` is φ(n)

---

## Algorithm (Pseudo-code)
```

1. Read prime p
2. Let n = p - 1
3. Initialize answer = n
4. For each prime factor i of n:
   a. Divide all occurrences of i from n
   b. answer = answer - (answer / i)   // Euler's totient formula
5. If n > 1 (remaining prime factor):
   answer = answer - (answer / n)
6. Print answer

```

---

## Examples

### Example 1:
- **Input:** `3`
- `p = 3 → n = 2`
- `Prime factors: {2}`
- `φ(2) = 2 × (1 - 1/2) = 1`
- **Output:** `1` (primitive root: `2`)

---

### Example 2:
- **Input:** `5`
- `p = 5 → n = 4`
- `Prime factors: {2}`
- `φ(4) = 4 × (1 - 1/2) = 2`
- **Output:** `2` (primitive roots: `2` and `3`)

---

### Example 3:
- **Input:** `7`
- `p = 7 → n = 6`
- `Prime factors: {2, 3}`
- `φ(6) = 6 × (1 - 1/2) × (1 - 1/3) = 2`
- **Output:** `2` (primitive roots: `3` and `5`)

---

## Complexity
- **Time:** `O(√p)` for prime factorization
- **Space:** `O(1)`

---