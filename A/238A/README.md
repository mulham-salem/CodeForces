# Problem 238A – Not Wool Sequences

## Problem Description

A sequence is called a **wool sequence** if it contains at least one contiguous subarray whose `XOR` is equal to `0`.

We need to count the number of sequences of length `n`, where every element is in the range:

```text
0 ... 2^m - 1
```
that are not wool sequences.

The answer should be printed modulo:

`1,000,000,009`


---

## Key Idea

Use prefix `XOR`:
```
p[0] = 0

p[i] = a[1] ^ a[2] ^ ... ^ a[i]
```

If two prefix `XOR` values are equal:
```
p[i] = p[j]
```
then the `XOR` of the elements between them is `0`.

Therefore:

Repeated prefix **XOR → the sequence is a wool sequence**.

All prefix `XOR` values are different → the sequence is not wool.

Since there are `n + 1` prefix `XOR` values:
```
p[0], p[1], ..., p[n]
```
and each prefix `XOR` can have one of `2^m` possible values, we need to choose `n + 1` distinct values.

Note that `p[0] = 0` is already fixed.

Therefore, the number of choices is:
$$
(2^m - 1) × (2^m - 2) × ... × (2^m - n)
$$

**If:**
$$
2^m <= n
$$
then there are not enough different values for all `n + 1` prefix `XORs`, so the answer is 0.

---

## Example

### Input
```
3 2
```

Here:
```
n = 3
m = 2
```
There are:
```
2^2 = 4
```
possible prefix XOR values:
```
0, 1, 2, 3
```
We need `n + 1 = 4` distinct prefix `XOR` values.

Since `p[0] = 0` is fixed:

`p[1]` has `3` choices.

`p[2]` has `2` choices.

`p[3]` has `1` choice.


So:
```
3 × 2 × 1 = 6
```
Output
```
6
```
The six valid sequences are:

`(1, 3, 1)`
`(1, 2, 1)`
`(2, 1, 2)`
`(2, 3, 2)`
`(3, 1, 3)`
`(3, 2, 3)`


---

## Another Example

**Suppose:**
```
n = 4
m = 2
```
There are only:
```
2^2 = 4
```
possible prefix `XOR` values, but we need:
```
n + 1 = 5
```
distinct values.

This is impossible, so every sequence is a wool sequence.

**Therefore:**
```
answer = 0
```

---

## Pseudocode
```
MOD = 1,000,000,009

Read n, m

Calculate x = 2^m using fast exponentiation

If x <= n:
    print 0
    return

answer = 1

For i from 1 to n:
    answer = answer × (x - i)
    answer = answer mod MOD

Print answer
```

---

## Complexity

**Time:**  `O(n + log m)`
**Space:** `O(1)`

---