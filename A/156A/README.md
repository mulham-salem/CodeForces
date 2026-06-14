# Problem 156A – Message

## Overview

You are given two strings:

- `s` → original string
- `u` → target string

You may choose **any substring** from `s`, then transform it into `u`.

Allowed operations (each costs 1):

- Insert a character at either end
- Delete a character from either end
- Replace a character

The goal is to minimize the number of operations.

---

## Key Idea

Instead of transforming directly, we try to **match `u` with a substring of `s` as much as possible**.

- Matching characters cost **0**
- Non-matching characters cost **1**
- So we want to maximize matches

Let:

- `best` = maximum number of matching characters between `u` and any aligned substring of `s`
- `m = |u|`

Then:

answer = m - best

---

## Example 1

### Input
```
s = abcabc 
u = bcd
```
### Best alignment

b c a b c d

Matches:
- b = b
- c = c

So:

best = 2

### Output
```
3 - 2 = 1
```
---

## Example 2

### Input
```
s = aaaaa 
u = aaa
```
### Best alignment

a a a a a a

All match:

best = 3

### Output
```
3 - 3 = 0
```
---

## Example 3

### Input
```
s = abcdef 
u = klmnopq
```
No matches at all:

best = 0

### Output
```
7 - 0 = 7
```
---

## Pseudocode
```
read s, u

n = length(s) m = length(u)

best = 0

for i in range(n): for j in range(m): if s[i] == u[j]: dp[i][j] = dp[i-1][j-1] + 1 else: dp[i][j] = 0

best = max(best, dp[i][j])

print(m - best)
```
---

## Complexity
```
- Time: O(n × m)
- Memory: O(n × m)
```
---
