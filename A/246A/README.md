# Problem 246A – Buggy Sorting

## Problem

Valera wrote a sorting algorithm that is supposed to sort an array in non-decreasing order.

The algorithm is:

```text
for i = 1 to n - 1
    for j = i to n - 1
        if a[j] > a[j + 1]
            swap(a[j], a[j + 1])
```

However, the algorithm may be incorrect.

We need to find a counter-example: an array of size n such that after running Valera's algorithm, the array is still not sorted.

If no such array exists, print -1.


---

## Input

A single integer:
```
n  //the size of the array.
```
`1 ≤ n ≤ 50`

---

## Output

If a counter-example exists, print `n` integers satisfying:

`1 ≤ ai ≤ 100`

After running Valera's algorithm on this array, the result must not be sorted in non-decreasing order.

If no counter-example exists, print:
```
-1
```

---

## Key Observation

For `n ≤ 2`, the algorithm always sorts the array correctly, so a counter-example is impossible.

For `n ≥ 3`, we can use the array:
```
2 2 1 1 ... 1
```
For example, when `n = 5`:
```
2 2 1 1 1
```
After Valera's algorithm, it becomes:
```
2 1 1 1 2
```
which is still not sorted.

Therefore:

If `n ≤ 2` → print `-1`.

Otherwise → print two `2s` followed by `n - 2` ones.

---

## Examples

### Example 1

### Input:
```
1
```
There is only one element, so the array is always sorted.

### Output:
```
-1
```

---

### Example 2

### Input:
```
5
```
One valid counter-example is:
```
2 2 1 1 1
```
After the buggy algorithm:
```
2 1 1 1 2
```

The array is not sorted, so this is a valid answer.

---

## Pseudocode
```
read n

if n <= 2:
    print -1
else:
    print 2 2

    for i from 3 to n:
        print 1
```

---

## Complexity

**Time:** `O(n)`

**Space:** `O(1)`

---