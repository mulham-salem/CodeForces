# Problem 158A – Next Round

## Problem Summary
In a competition, there are `n` participants.  
Each participant has a **score**.

Rules to advance to the next round:

1. Only participants with a **positive score** can advance.
2. A participant advances if their score is **at least as high as the k-th place score**.

Your task:
- Count how many participants advance to the next round.

---

## Key Idea
- Sort is **not necessary** if input is in order.
- Let `scores` = array of participant scores.
- Let `k` = position for qualification (1-indexed).

### Algorithm
```text
threshold = scores[k-1]   # k-th score
count = 0
for score in scores:
    if score >= threshold and score > 0:
        count += 1
````

---

## Example 1

**Input**

```
8 5
10 9 8 7 7 7 5 5
```

**Explanation**

* k-th score = 7 (5th place)
* Participants with score ≥ 7 and > 0:

```
10, 9, 8, 7, 7
```

* Count = 5

**Output**

```
5
```

---

## Example 2

**Input**

```
4 2
0 0 0 0
```

**Explanation**

* k-th score = 0
* No positive scores → Count = 0

**Output**

```
0
```

---

## Pseudocode

```text
read n, k
read scores[1..n]

threshold = scores[k-1]
count = 0

for i in 1..n:
    if scores[i] >= threshold and scores[i] > 0:
        count += 1

print count
```

---

## Final Notes

* Only participants with **score > 0** are eligible
* Anyone scoring **less than k-th place** is eliminated
* Works for all `1 ≤ k ≤ n` and `0 ≤ scores[i] ≤ 100`