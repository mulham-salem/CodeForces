# Problem 36A – Extra-terrestrial Intelligence

## Problem Summary
Vasya recorded signals for **n days**.  
Each day is represented by:

- `1` → a signal was received
- `0` → no signal was received

Vasya believes he discovered **extra-terrestrial intelligence** if the signals follow a **consistent pattern**.  
Specifically, the **distance between every two consecutive signals must be equal**.

It is guaranteed that the record contains **at least three `1`s**.

Your task is to determine whether the signals follow this pattern.

---

## Key Idea
1. Find the **indices of all `1`s** in the sequence.
2. Compute the **distance between the first two signals**.
3. Check the distance between every other pair of consecutive signals.
4. If all distances are equal → `YES`, otherwise → `NO`.

---

## Example 1

Input
```

8
00111000

```

Signal positions:
```

3 4 5

```

Distances:
```

1, 1

```

All distances are equal → Output:
```

YES

```

---

## Example 2

Input
```

7
1001011

```

Signal positions:
```

1 4 6 7

```

Distances:
```

3, 2, 1

```

Distances are different → Output:
```

NO

```

---

## Example 3

Input
```

7
1010100

```

Signal positions:
```

1 3 5

```

Distances:
```

2, 2

```

All distances are equal → Output:
```

YES

```

---

## Pseudocode

```
read n
read string s

create empty list positions

for i from 0 to n-1
if s[i] == '1'
add i to positions

diff = positions[1] - positions[0]

for i from 0 to size(positions)-2
current = positions[i+1] - positions[i]

if current != diff
    print NO
    stop

print YES

```

---

## Complexity

Time Complexity:
```

O(n)

```

Space Complexity:
```

O(k)

```

Where **k** is the number of received signals (`1`s).
