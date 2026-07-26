# Problem 207A1 – Beaver's Calculator 1.0

## Problem Description

There are `n` scientists. Each scientist provides a sequence of problems that must be solved in a fixed order.

Each problem requires a certain number of resource units. The calculator solves all problems one by one.

A **bad pair** occurs when a problem requires more resources than the next one:

$$ a[i] > a[i+1] $$

because the calculator must free resources, which is an expensive operation.

The goal is to arrange all problems in an order that minimizes the number of bad pairs while keeping the order of problems for each scientist unchanged.

---

## Generating Problems

For each scientist, the first value `a1` is given.

The following values are generated using:

$$ a[i] = (a[i-1] × X + Y) mod M $$

for every next problem.

---

## Key Observation

The order of problems from the same scientist cannot be changed.

Therefore, every decrease inside a scientist's sequence is unavoidable.

**Example:**
```
100 80 90 70
```
The decreases:
```
100 -> 80 90 -> 70
```
cannot be removed.

We split the sequence into increasing groups:

`Group 0: 100`

`Group 1: 80 90`

`Group 2: 70`

Each group is already non-decreasing.

After splitting all scientists' sequences into groups, we can merge these groups by:

1. Processing smaller group numbers first.
2. Sorting values inside the same group.

This produces the optimal order without trying all possible arrangements.

---

## Example

### Input
```
2 
3 10 2 3 1000 
3 100 1 999 1000
```
### Generated sequences

**Scientist 1:**

`10 23 49`

**Scientist 2:**

`100 99 98`

Splitting into groups:

**Scientist 1:**

`Group 0: 10 23 49`

**Scientist 2:**

`Group 0: 100`

`Group 1: 99`

`Group 2: 98`

After sorting groups, the final order becomes:

`10 23 49 100 99 98`

Checking adjacent pairs:

`10 -> 23   OK`
`23 -> 49   OK`
`49 -> 100  OK` 
`100 -> 99  Bad`
`99 -> 98   Bad`

The minimum number of bad pairs is:
```
2
```
---

## Algorithm

1. Generate all problems for every scientist.
2. Split each scientist's sequence into groups whenever the next value is smaller than the current value.
3. Store every problem with:
   - its value
   - its group number
   - scientist number
4. Sort all problems by:
   - group number
   - value
   - scientist number
5. Count bad pairs in the final order.
6. Print the answer and the order if the total number of problems is at most `200000`.

---

## Pseudocode
```
Read n

problems = empty list

For each scientist:

Generate all values

group = 0

Add first value with current group

For every next value:

    Generate next value

    If next value < current value:
        group++

    Add value with this group

Sort problems by:

group
value
scientist id

badPairs = 0

For every adjacent pair:

If current.value < previous.value:
    badPairs++

Print badPairs

If number of problems <= 200000:

Print all problems in sorted order
```
---

## Complexity Analysis

Let `N` be the total number of problems.

**Generating values:** `O(N)`

**Sorting:** `O(N log N)`

**Counting bad pairs:** `O(N)`

**Total complexity:** `O(N log N)`

---