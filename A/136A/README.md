# Problem 136A – Presents

## Problem Summary
There are `n` friends standing in a line.  
Each friend gives **one present** to **exactly one other friend**.

You are given an array `p` where:
- `p[i]` = the friend who receives the present from friend `i`

Your task is to determine:
👉 **Who gave a present to each friend**

---

## Key Idea
- If friend `i` gives a present to friend `p[i]`,
- then friend `p[i]` received a present **from `i`**.

So we simply **reverse the mapping**.

---

## How to Solve

Create a new array `ans` such that:
```text
ans[p[i]] = i
````

This way:

* `ans[j]` tells you **who gave a present to friend `j`**.

---

## Example 1

**Input**

```
4
2 3 4 1
```

**Explanation**

| Friend (i) | Gives present to p[i] |
| ---------- | --------------------- |
| 1          | 2                     |
| 2          | 3                     |
| 3          | 4                     |
| 4          | 1                     |

Reverse it:

| Friend | Received present from |
| ------ | --------------------- |
| 1      | 4                     |
| 2      | 1                     |
| 3      | 2                     |
| 4      | 3                     |

**Output**

```
4 1 2 3
```

---

## Example 2

**Input**

```
3
1 3 2
```

**Explanation**

* Friend 1 → 1 (gave a present to himself)
* Friend 2 → 3
* Friend 3 → 2

Reverse mapping:

```
1 ← 1
2 ← 3
3 ← 2
```

**Output**

```
1 3 2
```

---

## Pseudocode

```text
read n
read array p[1..n]

create array ans[1..n]

for i from 1 to n:
    ans[p[i]] = i

print ans
```

---

## Final Notes

* Each friend gives **exactly one** present
* Each friend receives **exactly one** present
* Time complexity: **O(n)**
* Space complexity: **O(n)**

✔️ Simple
✔️ No tricks
✔️ Direct mapping reversal