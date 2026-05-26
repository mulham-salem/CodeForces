# Problem 127A – Wasted Time

## Overview

Mr. Scrooge’s signature is represented as a polyline consisting of `n` points.

He draws straight segments between every two consecutive points:

- `A1 -> A2`
- `A2 -> A3`
- ...
- `A(n-1) -> An`

His writing speed is constant:

```text
50 millimeters per second
```

He signed exactly `k` papers using the same signature.

The task is to calculate the total time spent signing all papers.

---

## Input

The first line contains:

```text
n k
```

- `n` → number of points
- `k` → number of signatures

The next `n` lines contain the coordinates of each point:

```text
xi yi
```

---

## Output

Print one real number:

```text
Total signing time in seconds
```

---

## Idea

1. Calculate the distance between every two consecutive points.
2. Sum all segment lengths to get the total signature length.
3. Multiply by `k`.
4. Divide by `50` because the speed is `50 mm/s`.

Distance formula:

```text
d = sqrt((x2 - x1)^2 + (y2 - y1)^2)
```

---

## Example 1

### Input

```text
2 1
0 0
10 0
```

### Explanation

The signature contains one segment:

```text
(0,0) -> (10,0)
```

Length:

```text
10
```

Time:

```text
10 / 50 = 0.2
```

### Output

```text
0.200000000
```

---

## Example 2

### Input

```text
5 10
3 1
-5 6
-2 -1
3 2
10 0
```

### Explanation

Compute the length of every segment, sum them, multiply by `10`, then divide by `50`.

### Output

```text
6.032163204
```

---

## Pseudocode

```text
read n, k

read all points

totalLength = 0

for i from 1 to n-1
    dx = x[i] - x[i-1]
    dy = y[i] - y[i-1]

    totalLength += sqrt(dx*dx + dy*dy)

answer = (totalLength * k) / 50

print answer
```

---

## Complexity

```text
Time Complexity:  O(n)
Space Complexity: O(n)
```

---