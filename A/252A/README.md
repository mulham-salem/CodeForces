# Problem 252A – Little Xor

## Problem

Given an array of non-negative integers, find a **contiguous segment** whose XOR is as large as possible.

A segment must contain consecutive elements, and it can contain a single element.

### Example

For the array:

```text
1 2 1 1 2
```
Choosing the segment:
```
1 2
```
gives:
```
1 ^ 2 = 3
```
So the answer is `3`.

---

### Input

The first line contains an integer `n` — the number of elements.

The second line contains n non-negative `integers`.

---

### Constraints

`1 ≤ n ≤ 100`
`0 ≤ a[i] < 2^30`

---

### Output

Print the maximum XOR value among all contiguous segments of the array.

---

### Examples

#### Example 1

#### Input:
```
5
1 2 1 1 2
```

#### Output:
```
3
```

One optimal segment is:
```
[1, 2]
```

because:
```
1 ^ 2 = 3
```

---

#### Example 2

#### Input:
```
3
1 2 7
```

#### Output:
```
7
```

The best segment is:
```
[7]
```

so the answer is `7`.

---

#### Example 3

#### Input:
```
4
4 2 4 8
```

#### Output:
```
14
```

One optimal segment is:
```
[2, 4, 8]
```

because:
```
2 ^ 4 ^ 8 = 14
```

---

### Approach

Since `n` is at most `100`, we can simply check every possible contiguous segment.

For each starting position:

1. Start the current `XOR` with `0`.


2. Extend the segment one element at a time.


3. Update the current `XOR` using the new element.


4. Update the maximum `answer`.


The `XOR` does not need to be recalculated from the beginning for every segment.

---

### Pseudocode
```
read n
read array

answer = 0

for left from 0 to n - 1:
    currentXor = 0

    for right from left to n - 1:
        currentXor = currentXor XOR array[right]
        answer = max(answer, currentXor)

print answer
```

---

### Complexity

**Time:** `O(n²)`

**Space:** `O(n)`

---