# Problem 207A2 – Beaver's Calculator 1.0

## Problem Summary

There are **n scientists**, and each scientist has a sequence of problems that **must remain in the given order**.

Each problem requires a certain number of resource units. The goal is to merge all scientists' sequences into one valid sequence while preserving the order inside each scientist's list.

A pair of consecutive problems is considered **bad** if:

```
previous_resource > next_resource
```

Your task is to arrange the sequences so that the total number of bad adjacent pairs is **minimum**.

---

## Example

### Input

```text
Scientist 1: 10 → 23 → 49
Scientist 2: 100 → 99 → 98
```

### One valid order

```text
10 → 23 → 49 → 100 → 99 → 98
```

Bad pairs:

```text
100 > 99
99 > 98
```

Answer:

```text
2
```

---

## Key Observation

Each scientist's sequence is **fixed**.

You **cannot** reorder problems inside a scientist's list.

The only freedom is deciding **which scientist contributes the next problem** while preserving each sequence.

Some bad pairs already exist **inside** a scientist's sequence and cannot be removed.

The remaining bad pairs are created **between different scientists**, so choosing the order of merging the sequences is the main challenge.

---

## Algorithm Idea

1. Generate every scientist's sequence.
2. Count unavoidable bad pairs inside each sequence.
3. Determine an optimal order for merging the scientists' sequences.
4. Merge them while preserving each scientist's internal order.
5. Add any bad pairs created at the boundaries between different sequences.
6. Output the minimum number of bad pairs and, when required, the merged order.

---

## Pseudocode

```text
read n

for each scientist:
    generate its sequence
    count bad pairs inside the sequence

find the optimal ordering of scientists

merge the sequences while keeping
each scientist's original order

count bad pairs created between sequences

output the minimum answer

if total number of problems ≤ 200000:
    output the merged sequence
```

---

## Complexity

- **Time Complexity:** `O(total number of problems + sorting)`
- **Space Complexity:** `O(total number of problems)`

---