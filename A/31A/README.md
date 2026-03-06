# Problem 31A – Worms Evolution

## Problem Summary
Professor Vasechkin studies worm evolution and suggests that worms evolve by **division**.  
There are **n worm forms**, each having a certain length.

You are given an array:

a1, a2, a3, ..., an

The goal is to determine whether there exist **three distinct worm forms** such that:

ai = aj + ak

If such indices exist, print **any valid triple (i, j, k)**.  
Otherwise, print **-1**.

### Constraints
- 3 ≤ n ≤ 100
- 1 ≤ ai ≤ 1000
- Indices must be **distinct**
- It is allowed that **aj = ak in value**, but they must come from different positions.

---

## Key Idea
We need to check whether any worm length equals the **sum of two other worm lengths**.

Since **n is small (≤100)**, we can simply try all possible combinations of three different indices.

For each triple `(i, j, k)`:
- ensure the indices are different
- check if:

ai = aj + ak

If the condition holds, we immediately output the indices.

If no valid triple is found after checking all possibilities, the answer is **-1**.

---

## Example 1

Input
```

5
1 2 3 5 7

```

Possible check:

```

3 = 2 + 1

```

So:

```

a3 = a2 + a1

```

Output
```

3 2 1

```

---

## Example 2

Input
```

5
1 8 1 5 1

```

Trying all combinations shows that **no element equals the sum of two others**.

Output
```

-1

```

---

## Pseudocode

```
read n
read array a

for i from 1 to n
for j from 1 to n
for k from 1 to n
if i, j, k are all different
if a[i] == a[j] + a[k]
print i, j, k
stop program

print -1

```

---

## Time Complexity

```

O(n³)

```

Since `n ≤ 100`, this approach is fast enough.
