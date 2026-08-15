# Problem 244A – Dividing Orange

## Problem

There are `n × k` orange segments numbered from `1` to `n × k`, and `k` children.

Each child `i` chooses a specific segment `a[i]` that they must receive.

We need to divide all segments so that:

- Each child gets exactly `n` segments.
- Child `i` must receive segment `a[i]`.
- No segment is given to more than one child.
- Every segment must be used.

If there are multiple valid answers, any of them is accepted.

---

## Input

- The first line contains two integers `n` and `k`.
- The second line contains `k` distinct integers `a[1], a[2], ..., a[k]`.

Constraints:

- `1 ≤ n, k ≤ 30`
- `1 ≤ a[i] ≤ n × k`
- All `a[i]` are distinct.

--- 

## Output

Print exactly `n × k` distinct integers.

- The first `n` integers belong to the first child.
- The next `n` integers belong to the second child.
- And so on.

The order of segments within each child's group does not matter.

---

## Examples

### Example 1

**Input:**
```text
2 2
4 1
```
**Output:**
```
2 4
1 3
```
Each child gets `2` segments, and each receives their requested segment.

---

### Example 2

**Input:**
```
3 1
2
```

**Output:**
```
3 2 1
```

There is only one child, so they receive all `3` segments, including their requested segment `2`.

---

## Approach

First, give each child their requested segment `a[i]` and mark it as used.

Then, iterate through the segment numbers from `1` to `n × k`. Whenever an unused segment is found, give it to the current child until that child has exactly `n` segments.

A used array is used to make sure that no segment is assigned twice.

---

## Pseudocode
```
Read n and k
Read a[1...k]

Create used[1...n*k] initialized to false
Create k empty groups

For each child i:
    Add a[i] to group[i]
    Mark a[i] as used

current = 1

For each child i:
    While group[i] contains fewer than n segments:
        While current is already used:
            current++

        Add current to group[i]
        Mark current as used
        current++

Print all groups
```

---

## Complexity

**Time:** `O(n × k)`

**Space:** `O(n × k)`

---