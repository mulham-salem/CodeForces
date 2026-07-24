# Problem 203A – Two Problems

## Overview

There are **two problems** in the contest.

- The first problem starts with **`a`** points and loses **`da`** points every minute.
- The second problem starts with **`b`** points and loses **`db`** points every minute.

A submission can be made at any minute from **0** to **`t - 1`**.

Determine whether it is possible to obtain **exactly `x` points** by solving:

- None of the problems
- Only the first problem
- Only the second problem
- Both problems

---

## Example

### Input

```text
30 5 20 20 3 5
```

### Possible Scores

| Minute | Problem 1 | Problem 2 |
|:------:|:---------:|:---------:|
| 0 | 20 | 20 |
| 1 | 17 | 15 |
| 2 | 14 | 10 |
| 3 | 11 | 5 |
| 4 | 8 | 0 |

One possible choice:

- Problem 1 at minute **0** → **20**
- Problem 2 at minute **2** → **10**

Total:

```text
20 + 10 = 30
```

Answer:

```text
YES
```

---

## Idea

Since there are only **two problems**, simply try every possible submission time.

Check all possible cases:

1. Solve nothing.
2. Solve only the first problem.
3. Solve only the second problem.
4. Solve both problems using every pair of submission times.

If any combination gives exactly **`x`**, print **`YES`**; otherwise print **`NO`**.

---

## Pseudocode

```text
Read x, t, a, b, da, db

If x == 0
    Print "YES"
    Stop

Try every submission time for the first problem
    If its score equals x
        Print "YES"
        Stop

Try every submission time for the second problem
    If its score equals x
        Print "YES"
        Stop

Try every pair of submission times
    Calculate:
        score1 + score2
    If the total equals x
        Print "YES"
        Stop

Print "NO"
```

---

## Complexity

- **Time Complexity:** `O(t²)`
- **Space Complexity:** `O(1)`

---