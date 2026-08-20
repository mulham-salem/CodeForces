# Problem 251A – Points on Line

## Problem

You are given `n` points on a line, sorted in strictly increasing order.

You need to count the number of groups of **3 distinct points** such that the distance between the two farthest points in the group is at most `d`.

The order of the points inside a group does not matter.

### Key Idea

For each point `x[left]`, consider it as the **leftmost point** of the group.

Using two pointers, find how many consecutive points starting from `x[left]` are within distance `d` from it.

If there are `count` valid points:

- `x[left]` is already fixed.
- We need to choose **2 more points** from the remaining `count - 1` points.
- The number of ways is:

```text
(count - 1) * (count - 2) / 2
```
We add this value to the answer.

Why This Works

Since the points are sorted, for any group:
```
x[left] < x[mid] < x[right]
```
the farthest distance is always:
```
x[right] - x[left]
```
So we only need to make sure:
```
x[right] - x[left] <= d
```
Each group is counted exactly once because its smallest point is used as left.

---

### Examples

#### Example 1

#### Input:
```
4 3
1 2 3 4
```
#### Output:
```
4
```
All groups of three points satisfy the condition because the maximum possible distance is:
```
4 - 1 = 3
```
There are:
```
C(4, 3) = 4
```
valid groups.

---

#### Example 2

#### Input:
```
4 2
-3 -2 -1 0
```

#### Output:
```
2
```
The valid groups are:
```
{-3, -2, -1}
{-2, -1, 0}
```
Each has a maximum distance of 2.

---

#### Example 3

#### Input:
```
5 19
1 10 20 30 50
```

#### Output:
```
1
```
The only valid group is:
```
{1, 10, 20}
```
because:
```
20 - 1 = 19
```
while the other groups have a larger distance between their farthest points.

---

### Pseudocode
```
answer = 0
right = 0

for each left from 0 to n - 1:

    move right while x[right] - x[left] <= d

    count = right - left

    if count >= 3:
        answer += (count - 1) * (count - 2) / 2

print answer
```
---

### Complexity

**Time:** `O(n)`

**Space:** `O(n)`

---