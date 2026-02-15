# Problem 11A – Increasing Sequence

## Problem Statement

You are given a sequence of integers `b0, b1, ..., bn-1` and a positive integer `d`.  
You want to make the sequence **strictly increasing**, i.e., each element is greater than the previous one:

```

ai-1 < ai  for all 1 ≤ i < n

```

The only allowed operation is:

- Choose an element of the sequence and **add `d` to it**.  
- Each addition counts as **one move**.

Your task is to find the **minimum number of moves** required to make the sequence strictly increasing.

---

## Input

- First line: two integers `n` and `d` (2 ≤ n ≤ 2000, 1 ≤ d ≤ 10^6)  
- Second line: `n` integers: `b0, b1, ..., bn-1` (1 ≤ bi ≤ 10^6)

---

## Output

- Print a single integer — the minimum number of moves needed.

---

## Example 1

**Input**
```

4 2
1 3 3 2

```

**Output**
```

3

```

**Explanation**

Step by step:

1. Sequence: `1 3 3 2`  
   - 3 ≤ 3 → add `d=2` to second 3 → `1 3 5 2` (1 move)  
2. Sequence: `1 3 5 2`  
   - 2 ≤ 5 → add `d=2` twice → `1 3 5 6` (2 moves)  

Total moves: 3

---

## Example 2

**Input**
```

5 3
2 5 5 4 10

```

**Output**
```

4

````

---

## Approach

1. Start from the first element and move to the right.  
2. For each element `curr`, compare it with the previous element `prev`.  
3. If `curr` > `prev`, do nothing.  
4. If `curr` ≤ `prev`:
   - Calculate the **difference**: `diff = prev - curr`  
   - Compute the **minimum number of moves**:  
     ```
     needed = diff / d + 1
     ```
   - Update `curr` by `curr += needed * d`  
   - Add `needed` to total move count  

This ensures **each element becomes strictly greater than the previous one** with the minimum moves.

---

## Pseudocode

````

read n, d
read array b of size n
move_count = 0

for i from 0 to n-2:
if b[i] >= b[i+1]:
diff = b[i] - b[i+1]
needed = diff / d + 1
b[i+1] += needed * d
move_count += needed

print move_count

```

---

## Complexity

- Time: O(n) — each element is processed once  
- Space: O(n) — storing the sequence

---