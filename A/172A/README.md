# Problem 172A – Phone Code

## Overview

Given `n` phone numbers of equal length, determine the length of their **longest common prefix**.

A common prefix is a sequence of digits that appears at the beginning of **every** phone number.

---

## Example

### Input

```text
4
00209
00219
00999
00909
```

### Common Prefix

```text
00
```

### Output

```text
2
```

---

## Idea

Compare all phone numbers digit by digit from left to right.

- If every phone number has the same digit at the current position, the common prefix grows.
- Once a mismatch is found, stop immediately.
- The number of matching positions is the answer.

---

## Pseudocode

```text
read n
read all phone numbers

answer = 0

for each position pos:
    digit = first_number[pos]

    for every other phone number:
        if phone_number[pos] != digit:
            output answer
            stop

    answer++

output answer
```

---

## Complexity Analysis

| Complexity | Value |
|------------|--------|
| Time | O(n × m) |
| Space | O(n) |

Where:

- `n` = number of phone numbers
- `m` = length of each phone number (`m ≤ 20`)

---