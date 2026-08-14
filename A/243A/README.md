# Problem 243A – The Brand New Function

## Problem

Given an array of `n` non-negative integers, define:

`f(l, r) = a[l] | a[l+1] | ... | a[r]`

where `|` is the **bitwise OR** operation.

For every possible subarray `[l, r]`, calculate its OR value.

The goal is to find the number of **distinct OR values** obtained from all possible subarrays.

---

## Example

For:

```text
[1, 2, 0]
```
The possible subarrays and their OR values are:
```
[1]       -> 1
[1, 2]    -> 1 | 2 = 3
[1, 2, 0] -> 1 | 2 | 0 = 3
[2]       -> 2
[2, 0]    -> 2 | 0 = 2
[0]       -> 0
```
The results are:
```
1, 3, 3, 2, 2, 0
```
The distinct values are:
```
{0, 1, 2, 3}
```
Therefore, the answer is:
```
4
```

---

## Input

The first line contains an integer `n`:

`1 <= n <= 100000`

The second line contains `n` integers:

`a1, a2, ..., an`

with:

`0 <= ai <= 1000000`

## Output

Print the number of distinct values of `f(l, r)` obtained from all possible subarrays.

---

## Approach

A direct solution would consider all `O(n²)` subarrays, which is too slow for `n = 100000`.

Instead, process the array from left to right.

For every position, maintain a list previous containing the distinct OR values of all subarrays that end at the previous position.

When processing a new value `x`:

1. Start a new subarray `[x]`, whose `OR` value is `x`.


2. Extend every previous subarray by `x`.


3. If a previous OR value is `v`, the new value becomes:

```
v | x
```

4. Store the resulting distinct values in `current`.


5. Add every value in `current` to a global set containing all distinct `OR` values.


6. Set:
```
previous = current
```

**Why is the list small?**

When we repeatedly apply bitwise OR, bits can only change from `0` to `1`.

They can never change back from `1` to `0`.

Therefore, while extending subarrays, the `OR` value can only change a limited number of times. Since `ai <= 10^6`, there are only a small number of relevant bits.

Thus, instead of maintaining `O(n)` values for each position, we maintain only a small number of distinct `OR` values.

---

## Pseudocode
```
distinctValues = empty set
previous = empty list

for each element x:

    current = empty list

    add x to current

    for each value v in previous:

        newValue = v | x

        if newValue != current.back():

            add newValue to current

    add all values in current to distinctValues

    previous = current

print size of distinctValues
```

---

## Complexity

Let `B` be the number of bits in the numbers.

For every position, there are at most `O(B)` distinct `OR` values for subarrays ending at that position.

Therefore:

**Time:**  `O(n * B * log M)`
**Space:** `O(M)`

where `M` is the number of distinct `OR` values produced overall.

For the given constraints, this is easily fast enough.

---

## Example 1

### Input
```
3
1 2 0
```

### Output
```
4
```

---

## Example 2

### Input
```
10
1 2 3 4 5 6 1 2 9 10
```

### Output
```
11
```

---