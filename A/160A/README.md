# Problem 160A – Twins

## Problem Summary
- There are two twins, and each has a collection of coins.  
- One twin wants to have **strictly more coins** than the other.

You are given:
- `n` = number of coins
- A list of coin values

Your task:
- Find the **minimum number of coins** the twin needs to take from the collection to have strictly more than the other twin.

---

## Key Idea
- Sort the coins in **descending order**
- Take the **largest coins first**
- Keep adding coins until the sum is **strictly greater than the sum of the remaining coins**

---

## Algorithm

1. Compute `total_sum` = sum of all coins
2. Sort coins descending
3. Initialize:
   - `taken_sum = 0`
   - `count = 0`
4. Loop through coins:
   - Add coin to `taken_sum`
   - Increment `count`
   - Stop if `taken_sum > total_sum - taken_sum`
5. Output `count`

---

## Example 1

**Input**
```

5
3 2 1 2 2

```

**Explanation**
- Total sum = 10
- Sort descending: `3 2 2 2 1`
- Take coins:
  1. Take 3 → `taken_sum = 3`, remaining = 7 → 3 ≤ 7 → continue
  2. Take 2 → `taken_sum = 5`, remaining = 5 → 5 ≤ 5 → continue
  3. Take 2 → `taken_sum = 7`, remaining = 3 → 7 > 3 → stop

- Coins taken = 3

**Output**
```

3

```

---

## Example 2

**Input**
```

4
1 1 1 1

```

**Explanation**
- Total sum = 4
- Take coins largest first:
  - Take 1 → 1 ≤ 3 → continue
  - Take 1 → 2 ≤ 2 → continue
  - Take 1 → 3 > 1 → stop

- Coins taken = 3

**Output**
```

3

````

---

## Pseudocode

```text
read n
read coins[1..n]

total_sum = sum(coins)
sort coins descending

taken_sum = 0
count = 0

for coin in coins:
    taken_sum += coin
    count += 1
    if taken_sum > total_sum - taken_sum:
        break

print count
````

---

## Final Notes

* Always take **largest coins first**
* Goal: sum of taken coins > sum of remaining coins
* Time complexity: O(n log n) due to sorting
* Works for any positive integer coin values