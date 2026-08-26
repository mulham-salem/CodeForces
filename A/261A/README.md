# Problem 261A – Maxim and Discounts

## Problem Description

You have `n` items with different prices.

There are `m` possible discount options. For a discount `x`:

- You buy `x` items.
- You get the next **2 items for free**.
- You can choose at most one discount option.
- You may also buy all items normally.

The goal is to find the **minimum total amount of money** needed to buy all items.

---

## Key Idea

Sort the item prices in ascending order.

For a discount `x`, it is optimal to use the discount starting from the **most expensive items**, because the free items should be the cheapest possible items.

A group of `x + 2` items works as follows:

```text
[x paid items] [2 free items]
```
We calculate the sum of the `x` paid items efficiently using a prefix sum array.

For an interval `[l, r)`:
```
sum = pref[r] - pref[l]
```
So:
```
pref[i] - pref[i - x]
```
gives the total price of the last `x` items before position `i`.

If fewer than `x + 2` items remain, but at least `x + 1` remain, we can still buy `x` items and get `1` item free.

Any items left after that are bought normally.

---

## Example

Suppose:
```
Prices = [10, 20, 30, 40, 50, 60]
Discount = 2
```
We can group the most expensive items:
```
[50, 60] → paid
[30, 40] → free
```
Then:
```
[10, 20] → bought normally
```
Total:
```
50 + 60 + 10 + 20 = 140
```
Another possible discount may give a smaller total, so we try every available discount and take the minimum.

Prefix Sum Example

For:
```
a = [10, 20, 30, 40, 50]
```
the prefix sums are:
```
pref = [0, 10, 30, 60, 100, 150]
```
To calculate:
```
30 + 40 + 50
```
we use:
```
pref[5] - pref[2]
= 150 - 30
= 120
```
This lets us calculate the sum of any consecutive range in `O(1)`.

---

## Algorithm

1. Read the available discounts and the item prices.


2. Sort the item prices.


3. Build a prefix sum array.


4. Remove duplicate discount values.


5. Initially assume that all items are bought normally.


6. For every discount `x`:

	Start from the most expensive item.

	While at least `x + 2` items remain:

	Add the price of the `x` paid items.

	Skip the next `2` items because they are free.


	If at least `x + 1` items remain:

	Buy `x` items and get `1` item for free.


	Buy any remaining items normally.

	Update the minimum answer.



7. Output the minimum cost.

---

## Pseudocode
```
read m
read discounts

read n
read prices

sort prices

build prefix sum

remove duplicate discounts

answer = sum of all prices

for each discount x:

    if x > n:
        continue

    cost = 0
    i = n

    while i >= x + 2:
        add sum of last x items to cost
        move i back by x + 2

    if i >= x + 1:
        add sum of x paid items to cost
        set i = 0

    add prices of remaining items normally

    answer = minimum(answer, cost)

print answer
```
---

## Complexity

Sorting the prices takes:

`O(n log n)`

For each distinct discount, we process the items in groups, taking `O(n)` time.

Therefore:

**Time:**  `O(n log n + m × n)`
**Space:** `O(n)`

---