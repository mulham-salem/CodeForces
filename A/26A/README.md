# Problem 26A – Almost Prime

## 📌 Problem Summary

A number is called **almost prime** if it has **exactly two distinct prime divisors**.

Given an integer `n (1 ≤ n ≤ 3000)`, determine how many almost prime numbers exist between `1` and `n` (inclusive).

---

## 🔎 Definition

A number is **almost prime** if:

- It has **exactly two different prime factors**
- The multiplicity of factors does not matter
- Only distinct prime divisors are counted

---

## 🧠 Examples

### Example 1

Input:
```

10

```

Numbers between 1 and 10:

- 6 = 2 × 3 → ✅ (two distinct primes)
- 10 = 2 × 5 → ✅

Output:
```

2

```

---

### Example 2

Input:
```

21

```

Almost prime numbers:

- 6  = 2 × 3  
- 10 = 2 × 5  
- 12 = 2² × 3  
- 14 = 2 × 7  
- 15 = 3 × 5  
- 18 = 2 × 3²  
- 20 = 2² × 5  
- 21 = 3 × 7  

Output:
```

8

```

---

## 🚀 Efficient Approach (Sieve Idea)

Instead of factoring every number independently, we can:

1. Create an array `primeCount[i]` that stores  
   the number of distinct prime divisors of `i`.
2. Use a sieve-like technique:
   - For each prime number `i`
   - Increase the count of all its multiples.
3. Count how many numbers have exactly `2` distinct prime divisors.

Time Complexity: **O(n log n)**  
Efficient for `n ≤ 3000`.

---

## 🧩 Pseudocode

```
read n

create array primeCount[0..n] and initialize with 0

for i from 2 to n:
if primeCount[i] == 0:
# i is prime
for j from i to n step i:
primeCount[j] = primeCount[j] + 1

answer = 0

for i from 1 to n:
if primeCount[i] == 2:
answer = answer + 1

print answer

```

---

## 🎯 Key Idea

Each prime number contributes +1  
to all of its multiples.

In the end:

- If `primeCount[i] == 2`
- Then `i` is an **almost prime number**.
