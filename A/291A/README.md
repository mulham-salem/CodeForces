# Problem 291A – Spyke Talks

## Problem Summary

There are `n` secretaries. Each secretary has a number:

- `0` means the secretary is not talking.
- A positive number represents the **session ID** of their current call.

Each call connects exactly **two people**, so the same session ID can appear at most twice.

We need to find the number of calls between the company's secretaries.

If any session ID appears more than twice, the data is invalid and we print `-1`.

---

## Input

- The first line contains an integer `n` — the number of secretaries.
- The second line contains `n` integers representing the session ID of each secretary.

Constraints:

- `1 ≤ n ≤ 1000`
- `0 ≤ id ≤ 10^9`

---

## Output

- Print the number of pairs of secretaries who are talking to each other.
- Print `-1` if any session ID appears more than twice.

---

## Examples

### Example 1

**Input:**
```
6
0 1 7 1 7 10
```

`Session 1 appears twice → one call`

`Session 7 appears twice → one call`

`Session 10 appears once → that secretary is talking to someone outside the company`

**Output:**
```
2
```

---

### Example 2

**Input:**
```
3
1 1 1
```

`Session 1 appears three times.`

This is impossible because a call can connect only two people.

**Output:**
```
-1
```

---

### Example 3

**Input:**
```
1
0
```
The only secretary is not talking.

**Output:**
```
0
```

---

## Approach

1. Count how many times each non-zero session ID appears.


2. If any ID appears more than twice, the data is invalid → print `-1`.


3. If an ID appears exactly twice, it represents one call between two secretaries.


4. Count all such IDs.

---

## Pseudocode
```
Read n

Create a map to count each session ID
answer = 0

For each of the n secretaries:
    Read id

    If id is not 0:
        Increase the count of id

For each session ID in the map:
    If its count is greater than 2:
        Print -1
        Stop

    If its count equals 2:
        Increase answer by 1

Print answer
```

---

## Complexity

**Time:** `O(n log n)` using a map

**Space:** `O(n)`

---