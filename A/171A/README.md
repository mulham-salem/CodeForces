# Problem 171A – Mysterious numbers - 1

## Overview

You are given two non-negative integers `a1` and `a2`.

The task is to reverse the digits of `a2`, then add the resulting number to `a1`, and output the final sum.

Leading zeros in the reversed number are ignored automatically.

---

## Examples

### Example 1

**Input**
```text
3 14
```

**Process**
```text
reverse(14) = 41
3 + 41 = 44
```

**Output**
```text
44
```

---

### Example 2

**Input**
```text
27 12
```

**Process**
```text
reverse(12) = 21
27 + 21 = 48
```

**Output**
```text
48
```

---

### Example 3

**Input**
```text
100 200
```

**Process**
```text
reverse(200) = 2
100 + 2 = 102
```

**Output**
```text
102
```

---

## Idea

1. Read `a1` and `a2`.
2. Reverse the digits of `a2`.
3. Add the reversed value to `a1`.
4. Print the result.

---

## Pseudocode

```text
read a1, a2

reversed = 0

while a2 > 0
    reversed = reversed * 10 + (a2 % 10)
    a2 = a2 / 10

print a1 + reversed
```

---

## Complexity Analysis

- **Time Complexity:** `O(d)`
- **Space Complexity:** `O(1)`

Where `d` is the number of digits in `a2`.

---