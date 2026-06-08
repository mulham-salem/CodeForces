# Problem 146A - Lucky Ticket

## Overview

You are given a ticket number of even length `n`.

A ticket is considered **lucky** if:

1. Every digit is either `4` or `7`.
2. The sum of digits in the first half of the ticket is equal to the sum of digits in the second half.

Your task is to determine whether the given ticket is lucky.

---

## Examples

### Example 1

**Input**
```text
2
47
```

**Output**
```text
NO
```

**Explanation**

The ticket contains only lucky digits, but:

- First half sum = 4
- Second half sum = 7

Since `4 ≠ 7`, the ticket is not lucky.

---

### Example 2

**Input**
```text
4
4738
```

**Output**
```text
NO
```

**Explanation**

The digit `3` and `8` are not lucky digits, so the ticket is not a lucky number.

---

### Example 3

**Input**
```text
4
4774
```

**Output**
```text
YES
```

**Explanation**

- All digits are either `4` or `7`.
- First half sum = `4 + 7 = 11`
- Second half sum = `7 + 4 = 11`

The sums are equal, so the ticket is lucky.

---

## Key Idea

While scanning the ticket number:

- Verify that every digit is either `4` or `7`.
- Calculate the sum of the first half digits.
- Calculate the sum of the second half digits.

The answer is `"YES"` only if both conditions are satisfied.

---

## Pseudocode

```text
read n
read ticket

firstSum = 0
secondSum = 0

for each position i:
    if digit is not 4 and not 7:
        print NO
        stop

    if i is in the first half:
        add digit to firstSum
    else:
        add digit to secondSum

if firstSum equals secondSum:
    print YES
else:
    print NO
```

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---