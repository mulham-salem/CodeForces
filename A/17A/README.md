# Problem 17A – Noldbach Problem

## 📘 Overview

Nick invented the **Noldbach Problem** inspired by the Goldbach conjecture.

Given two integers:

- `n` (2 ≤ n ≤ 1000)
- `k` (0 ≤ k ≤ 1000)

We must determine whether **at least `k` prime numbers** in the range `[2, n]` can be expressed in the following form:

```
p = p_i + p_i+1 + 1
```

Where:

- `p_i` and `p_{i+1}` are **neighboring prime numbers**
- Neighboring means: there is **no other prime between them**

If at least `k` such primes exist → print `YES`  
Otherwise → print `NO`

---

## 🔎 Key Idea

1. Generate all prime numbers up to `n`.
2. For every pair of consecutive (neighboring) primes:
   - Compute:
     ```
     candidate = prime[i] + prime[i+1] + 1
     ```
   - Check if:
     - `candidate ≤ n`
     - `candidate` is prime
3. Count how many valid candidates exist.
4. Compare the count with `k`.

---

## 🧠 Example 1

**Input**
```
27 2
```

Primes up to 27:
```

2, 3, 5, 7, 11, 13, 17, 19, 23

```

Check neighboring pairs:

- 5 + 7 + 1 = 13 ✅ (prime)
- 7 + 11 + 1 = 19 ✅ (prime)

We found at least 2 valid primes.

**Output**
```

YES

```

---

## 🧠 Example 2

**Input**
```

45 7

```

Not enough primes satisfy the condition.

**Output**
```

NO

```

---

## ⚙️ Pseudocode

```

read n, k

create empty list primes

for number from 2 to n:
if number is prime:
add number to primes

count = 0

for i from 0 to size(primes) - 2:
candidate = primes[i] + primes[i+1] + 1

if candidate ≤ n AND candidate is prime:
    count++

if count ≥ k:
print "YES"
else:
print "NO"

```

---

## ⏱ Complexity

- Prime generation: O(n √n) (or O(n log log n) using sieve)
- Checking pairs: O(number_of_primes)

Since `n ≤ 1000`, a simple prime check is sufficient.
