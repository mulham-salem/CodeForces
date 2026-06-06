# Problem 142A – Help Farmer

## Overview

Farmer Sam stored hay blocks in a 3D box with dimensions:

- A layers  
- B rows  
- C columns  

So the total number of blocks is:

A × B × C

After thieves attacked, the remaining blocks became:

(A − 1) × (B − 2) × (C − 2) = n

You are given `n` and must find:
- Minimum possible stolen blocks
- Maximum possible stolen blocks

---

## Key Idea

Let:

p = A − 1  
q = B − 2  
r = C − 2  

So we get:

p × q × r = n

Now the problem becomes:
Find all triples (p, q, r) whose product is `n`.

---

## Important Insight

From one triple (p, q, r), any value can represent (A − 1), so we must try all cases:

Case 1: A − 1 = p  
Original = (p + 1)(q + 2)(r + 2)

Case 2: A − 1 = q  
Original = (q + 1)(p + 2)(r + 2)

Case 3: A − 1 = r  
Original = (r + 1)(p + 2)(q + 2)

Stolen blocks = Original − n

---

## Example

Input:
4

One factorization:
1 × 2 × 2

Original:
2 × 4 × 4 = 32

Stolen:
32 − 4 = 28

Another arrangement gives:
41

Output:
28 41

---

## Approach

- Iterate over all divisors p of n  
- For each p compute rem = n / p  
- Find divisors q of rem  
- Compute r = rem / q  
- Try all permutations of (p, q, r)  
- Compute stolen = (A × B × C) − n  
- Track min and max

---

## Complexity

Time: O(n^(2/3))  
Memory: O(1)


---