# Problem 176A – Trading Business

## Idea

Choose **one planet to buy items** and **another planet to sell them**.

For each item type:

- Compute the profit per item:
  ```
  profit = sellPrice - buyPrice
  ```
- Ignore item types with non-positive profit.
- You can buy at most the available quantity on the buying planet.
- The spaceship can carry at most `k` items.

For every pair of planets, calculate the profit of each item type, sort them by **profit per item** in descending order, then greedily fill the spaceship with the most profitable items. The maximum profit over all planet pairs is the answer.

---

## Example

Suppose we have the following profitable items:

| Profit per Item | Available Quantity |
|----------------:|-------------------:|
| 5 | 2 |
| 3 | 4 |
| 1 | 10 |

If `k = 5`:

- Take **2** items with profit **5**.
- Take **3** items with profit **3**.

Total profit:

```
2 × 5 + 3 × 3 = 19
```

---

## Algorithm

1. Read all planets and item information.
2. Try every pair of different planets `(buy, sell)`.
3. Compute the profit per item for every item type.
4. Keep only profitable item types.
5. Sort them by profit in descending order.
6. Greedily fill the spaceship until capacity `k` is reached.
7. Update the maximum profit.
8. Print the answer.

---

## Pseudocode

```text
answer = 0

for each buying planet
    for each selling planet
        if same planet
            continue

        profitableItems = []

        for each item type
            profit = sellPrice - buyPrice

            if profit > 0
                add (profit, quantity) to profitableItems

        sort profitableItems by profit descending

        remaining = k
        currentProfit = 0

        for each item in profitableItems
            take = min(remaining, quantity)
            currentProfit += take × profit
            remaining -= take

            if remaining == 0
                break

        answer = max(answer, currentProfit)

print answer
```

---

## Complexity

- **Time Complexity:** `O(n² × m log m)`
- **Space Complexity:** `O(m)`

---