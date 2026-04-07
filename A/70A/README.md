# Problem 70A – Cookies

## Problem Description
Fangy wants to place cookies in a square box of size 2^n × 2^n.  
Each cookie of size k occupies the main diagonal and all cells above it in a k × k square.  
Cookies cannot overlap, rotate, or flip.  
The goal is to calculate the **number of empty cells** left in the box after placing cookies using the strategy: always place the largest cookie that fits.

**Input:**  
- A single integer `n` (0 ≤ n ≤ 1000)

**Output:**  
- Number of empty cells modulo 10^6 + 3

---

## Example

| Input | Output |
|-------|--------|
| 3     | 9      |

**Explanation:**  
- Box size = 2^3 × 2^3 = 8 × 8  
- Using the placement strategy, the empty cells left = 9

---

## Approach
Empty cells follow a pattern:  

- For n = 0 → empty cells = 1  
- For n ≥ 1 → empty cells = 3^(n-1)  

Use modulo 10^6 + 3 to avoid large numbers.

---

## Pseudocode

```
MOD = 1000003

function countEmptyCells(n): if n == 0: return 1

ans = 1
repeat (n-1) times:
    ans = (ans * 3) % MOD

return ans
```

---