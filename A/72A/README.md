# Problem 72A – Goshtasp, Vishtasp and Eidi

## Problem Description
You are given a positive integer `n`. You need to determine whether `n` is *rich*.  

A number `x` is considered rich if there exists a set of **distinct numbers** `a1, a2, ..., am` such that:

- Each `ai` is either a **prime number** or **1**
- Sum of all `ai` equals `x`  

If such a set exists, you should print it in **lexicographically latest order**.

---

## Input
- Single positive integer `n` `(1 ≤ n ≤ 10000)`

---

## Output
- If `n` is **not rich**, print `0`.  
- Otherwise, print the numbers `a1, ..., am` separated by `+` followed by `=n`.  
- If multiple sequences exist, print the **lexicographically largest** one.

---

## Examples

### Input

11

### Output

11=11

### Input

545

### Output

541+3+1=545

---

## Notes
- Lexicographical order is compared by sequences of numbers, not strings.  
- Zeros are added to the shorter sequence temporarily for comparison if lengths differ.  
- You do **not** need to minimize the number of elements in the sequence.

---

## Pseudocode
```
function isPrime(num): if num < 2: return false if num == 2: return true if num is even: return false for d = 3 to sqrt(num) step 2: if num % d == 0: return false return true

function findRichNumber(n): if isPrime(n): print n = n return

primes = list of primes <= n in descending order
append 1 to primes list

remaining = n
best = empty list

for p in primes:
    while remaining >= p:
        append p to best
        remaining -= p

if remaining == 0:
    print elements of best joined by '+' then '=' then n
else:
    print 0
```

---