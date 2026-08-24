# Problem 257A – Sockets

## Problem Summary

Vasya has `k` electrical sockets available directly from the wall and `m` devices that need to be plugged in.

He also has `n` power strips. Each power strip has `ai` sockets.

When a power strip is plugged into an available socket, it **uses one socket** but provides `ai` new sockets.

Therefore, using a power strip with `ai` sockets increases the number of available sockets by:

`ai - 1`

The goal is to find the **minimum number of power strips** needed to have at least `m` available sockets.

If it is impossible even after using all power strips, print `-1`.

---

## Input

The first line contains three integers:

- `n` — the number of power strips.
- `m` — the number of devices.
- `k` — the number of sockets available directly from the wall.

The second line contains `n` integers:

- `ai` — the number of sockets on the `i`-th power strip.

---

### Constraints

- `1 ≤ n, m, k ≤ 50`
- `1 ≤ ai ≤ 50`

---

## Output

Print the minimum number of power strips required to plug all `m` devices.

If it is impossible, print `-1`.

---

## Examples

### Example 1

**Input:**
```text
3 5 3
3 1 2
```

**Output:**
```
1
```
Initially, there are `3` sockets.

Using the power strip with `3` sockets:

It consumes `1` existing socket.

It provides `3` new sockets.


So the number of available sockets becomes:
```
3 - 1 + 3 = 5
```
Therefore, only `1` power strip is needed.


---

### Example 2

**Input:**
```
4 7 2
3 3 2 4
```

**Output:**
```
2
```
Initially, there are `2` sockets.

Use the power strip with `4` sockets:
```
2 - 1 + 4 = 5
```
We still need more sockets, so use a power strip with `3` sockets:
```
5 - 1 + 3 = 7
```
Thus, `2` power strips are enough.

---

### Example 3

**Input:**
```
5 5 1
1 3 1 2 1
```

**Output:**
```
-1
```

Even after using all power strips, the maximum number of available sockets is only `4`, while `5` are required.

Therefore, it is impossible.

---

## Approach

To minimize the number of power strips:

1. Sort the power strips in descending order of their number of sockets.


2. Start with `k` available sockets.


3. Use the largest power strips first.


4. For each used power strip with `ai` sockets, increase the available sockets by `ai - 1`.


5. Stop as soon as the number of available sockets reaches at least `m`.


6. If all power strips are used and there are still fewer than m sockets, print `-1`.

---

## Pseudocode
```
Read n, m, k
Read array a

Sort a in descending order

answer = 0

For each power strip x in a:
    If k >= m:
        break

    k = k + x - 1
    answer++

If k >= m:
    print answer
Else:
    print -1
```

---

## Complexity

Sorting takes `O(n log n)` time.

The remaining loop takes `O(n)` time.

Overall:

**Time:** `O(n log n)`

**Space:** `O(n)`

---