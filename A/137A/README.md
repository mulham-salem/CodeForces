# Problem 137A – Postcards and Photos

## Overview

You are given a string consisting of two characters:

C → postcard

P → photo


Polycarpus removes all items from left to right.

### Rules:

He can carry only one type at a time (C or P)

He can carry at most 5 items per trip

He must remove items in order


Find the minimum number of trips needed.


---

## Key Idea

Split the string into consecutive groups of the same character.

Example:

CPCPPCC → C | P | C | P | P | CC

Each group is handled separately.

For a group of size x:

Each trip carries up to 5 items

Trips needed = (x + 4) / 5



---

## Input

A single string s
Only characters: C, P
Length ≤ 100


---

## Output

Print the minimum number of trips.


---

## Example 1

### Input
```
CPCPCPC
```

### Output
```
7
```

### Explanation
Every character is different → each group size = 1 → 7 trips


---

## Example 2

### Input
```
CCCCCCPPPPPP
```

### Output
```
4
```

### Explanation
Groups:

CCCCCC → 2 trips

PPPPPP → 2 trips


Total = 4


---

## Example 3

### Input
```
CCCCCCPPCPPPPPPPPPP
```

### Output
```
6
```

### Explanation
Groups:

CCCCCC → 2

PP → 1

C → 1

PPPPPPPPPP → 2


Total = 6


---

## Pseudocode

```
read s
ans = 0
cnt = 1

for i = 1 → n-1
 if s[i] == s[i-1]
  cnt++
 else
  ans += (cnt + 4) / 5
  cnt = 1

ans += (cnt + 4) / 5

print ans
```

---

## Complexity

Time: O(n)
Memory: O(1)


---

## Summary

Split into consecutive blocks

Each block → (size + 4) / 5

Sum all blocks

Don’t forget last block


---