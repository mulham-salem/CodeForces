# Problem 190A – Vasya and the Bus

## Problem Description

There are `n` adults and `m` children riding a bus.

The bus fare is **1 ruble per person**, but there is a special rule:

- One child can ride for free with each adult.
- If an adult rides with `k` children (`k > 0`), they pay for `k` tickets in total:
  - 1 ticket for the adult.
  - `k - 1` tickets for the children.
- An adult without children pays 1 ruble.

Children cannot ride the bus without adults.

The task is to find:

- The **minimum** possible total fare.
- The **maximum** possible total fare.

If the situation is impossible, print `"Impossible"`.

---

## Input

The input contains two integers:
```
n m
```
Where:

- `n` → number of adults.
- `m` → number of children.

Constraints:

0 ≤ n, m ≤ 10^5

---

## Output

Print two integers:
```
minimum maximum
```
representing:

- The minimum possible total fare.
- The maximum possible total fare.

If the passengers cannot ride the bus, print:

`Impossible`

---

## Key Observations

### Impossible Case

Children cannot ride without adults.

Therefore, the only impossible situation is:

`n = 0 and m > 0`

---

### Minimum Fare

To minimize the cost:

- Make as many children as possible ride for free.
- Each adult can make one child free.

So the number of free children is:

`min(n, m)`

The remaining children must pay.

---

### Maximum Fare

To maximize the cost:

- We need to minimize the number of free children.
- If there are children, only one adult needs to accompany them.
- That adult makes only one child free.

So:

- If `m = 0`, all adults just pay for themselves.
- Otherwise, exactly one child can be free.

---

## Examples

### Example 1

#### Input:
```
1 2
```
Possible arrangement:

`Adult + 2 Children`

The adult pays for himself and one child.

#### Output:
```
2 2
```
---

### Example 2

#### Input:
```
0 5
```
There are children but no adults.

Children cannot ride alone.

#### Output:
```
Impossible
```
---

### Example 3

#### Input:
```
2 2
```
Minimum fare:

`Adult + Child Adult + Child`

Total:

`2`

Maximum fare:

`Adult + 2 Children Adult`

Total:

`3`

#### Output:
```
2 3
```
---

## Pseudocode
```
Read n, m

If n == 0 and m > 0: Print "Impossible" Stop

minimum = n + max(0, m - n)

If m == 0: maximum = n Else: maximum = n + m - 1

Print minimum, maximum
```
---

## Complexity Analysis

Time Complexity: `O(1)`

Memory Complexity: `O(1)`

---