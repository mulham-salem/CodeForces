# Problem 44A – Indian Summer

## Problem Description

Alyona is walking in the forest and collecting fallen leaves. She is very picky: she will **not take a leaf** if she already has a leaf with the **same tree species and color**.  
Your task is to determine how many leaves Alyona ends up taking.

---

## Input

- The first line contains an integer `n` (1 ≤ n ≤ 100) — the number of leaves Alyona found.  
- The next `n` lines each describe a leaf:  
  - A **tree species** (string of ≤10 lowercase letters)  
  - A **color** (string of ≤10 lowercase letters)  
  The species and color are separated by a space.

### Example Input

```
5 
birch yellow 
maple red 
birch yellow 
maple yellow 
maple green
```

---

## Output

- Output a single integer — the number of **distinct leaves** Alyona takes.

### Example Output

```
4
```

---

## Explanation
1. `birch yellow` → new, take it.  
2. `maple red` → new, take it.  
3. `birch yellow` → duplicate, skip it.  
4. `maple yellow` → new, take it.  
5. `maple green` → new, take it.  

Total distinct leaves taken: **4**

Another example:

**Input**

```
3 
oak yellow 
oak yellow 
oak yellow
```

**Output**

```
1
```

Explanation: All leaves are the same, so only one is taken.

---

## Pseudocode

```
read n initialize empty set leaves

for i = 1 to n: read tree, color if (tree, color) not in leaves: add (tree, color) to leaves

print size of leaves
```

---