# Problem 254A – Cards with Numbers

## Problem Statement

Petya has `2n` cards, each card contains a positive integer. The goal is to split the cards into `n` pairs such that in each pair, both cards have the same number. Each card has a unique index from `1` to `2n`.  

If it is impossible to form such pairs, output `-1`. Otherwise, output `n` pairs of indices of the cards forming each pair.  

### Input
- First line: integer `n` (1 ≤ n ≤ 3·10^5)  
- Second line: `2n` integers `a1, a2, ..., a2n` (1 ≤ ai ≤ 5000)  

### Output
- `-1` if pairing is impossible  
- Otherwise, `n` lines, each line contains two integers — the indices of the paired cards. Order of pairs or indices in a pair does not matter.

### Example
**Input**
```

3
20 30 10 30 20 10

```

**Output**
```

1 5
2 4
3 6

```

**Explanation:**  
- Card `1` and `5` both have number 20  
- Card `2` and `4` both have number 30  
- Card `3` and `6` both have number 10  

---

## Solution Idea

1. Use an array (or vector) to store **indices for each number** since all numbers are between 1 and 5000.  
2. For each number:
   - If it appears an **odd number of times**, pairing is impossible → output `-1`.  
   - Otherwise, take the indices **two by two** to form pairs.  
3. Print the pairs.

---

## Pseudocode

```

function pair_cards(n, cards):
create pos[5001] as array of lists

```
for i from 1 to 2*n:
    x = cards[i]
    append i to pos[x]

for i from 1 to 5000:
    if length(pos[i]) is odd:
        print -1
        return

for i from 1 to 5000:
    for j from 0 to length(pos[i])-1 step 2:
        print pos[i][j], pos[i][j+1]
```

```

**Key Notes:**
- Each `pos[x]` stores all indices of cards with number `x`.  
- Pair indices **in the order they were read**.  
- Time complexity: O(n), Memory complexity: O(n).  

---

## Summary

This solution efficiently uses an **array of vectors** to group indices by number and then generates valid pairs. It works for large `n` because the numbers on the cards are bounded (≤ 5000), so the memory usage is controlled.

---