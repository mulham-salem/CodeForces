# Problem 318A – Even Odds

## Requirement

You are given two integers `n` and `k`.

Consider a sequence of numbers from `1` to `n` arranged in the following order:

1. First, all **odd numbers** in increasing order  
2. Then, all **even numbers** in increasing order

---

## Goal

Find the **k-th number** in this reordered sequence.

---

## Input

- Two integers `n` and `k`

  - `n` – the maximum number in the sequence  
  - `k` – the position you are looking for  

---

## Output

- One integer: the value at position `k` in the sequence

---

## Explanation of the Sequence

For `n = 7`, the sequence will be:

```

Odd numbers:  1 3 5 7
Even numbers: 2 4 6

Final sequence:
1 3 5 7 2 4 6

```

---

## Examples

### Example 1

**Input**
```

7 3

```

**Output**
```

5

```

**Explanation**
```

Sequence: 1 3 5 7 2 4 6
The 3rd element is 5.

```

---

### Example 2

**Input**
```

7 5

```

**Output**
```

2

```

**Explanation**
```

The first 4 numbers are odd.
The 5th number is the first even number → 2.

```

---

### Example 3

**Input**
```

10 7

```

**Output**
```

4

```

**Explanation**
```

Odd count = ceil(10 / 2) = 5
k = 7 > 5 → move to even numbers
Even position = 7 - 5 = 2
2nd even number = 4

```

---

## Solution Idea

1. Count how many odd numbers exist from `1` to `n`:
```

odd_count = (n + 1) / 2

```

2. If `k` is within the odd numbers:
```

answer = 2 * k - 1

```

3. Otherwise, `k` is in the even part:
```

answer = 2 * (k - odd_count)

```

4. Print the result.

---

## Complexity

- **Time Complexity:** `O(1)`
- **Space Complexity:** `O(1)`

---
