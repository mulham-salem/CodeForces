# Problem 386A – Second-Price Auction

## 📌 Problem Summary

In a **second-price auction**, `n` bidders each submit a secret bid. The **highest bidder wins**, but pays the **second-highest price** (the highest bid among the other participants), not their own bid.

All bids are **distinct**.

**Goal:** Find the **1-based index** of the winner and the **price they pay** (the second-highest bid).

---

## 📥 Input

- First line: `n` (2 ≤ n ≤ 1000) — number of bidders.
- Second line: `n` distinct integers `p1, p2, ..., pn` (1 ≤ pi ≤ 10000).

## 📤 Output

- One line with two integers: **winner's index** and **price paid** (second-highest bid).

---

## 🧪 Examples

### Example 1
```

Input:
2
5 7

Output:
2 5

```
> Bidder 2 bids 7 (highest) → wins, pays 5 (second-highest).

---

### Example 2
```

Input:
3
10 2 8

Output:
1 8

```
> Bidder 1 bids 10 (highest) → wins, pays 8 (second-highest).

---

### Example 3
```

Input:
6
3 8 2 9 4 14

Output:
6 9

```
> Bidder 6 bids 14 (highest) → wins, pays 9 (second-highest).

---

## 💡 Approach

We only need the **largest** and **second-largest** bids while tracking the winner's index:

- Keep `max1` (highest bid), `max2` (second-highest bid), and `winner` (index of `max1`).
- For each bid `p` at index `i`:
  - If `p > max1`: shift `max1 → max2`, update `max1 = p`, `winner = i + 1`.
  - Else if `p > max2`: update `max2 = p`.
- Output `winner` and `max2`.

---

## 🧾 Pseudocode

```

READ n
max1 ← -1
max2 ← -1
winner ← 0

FOR i FROM 0 TO n-1:
	READ p
	IF p > max1:
		max2 ← max1
		max1 ← p
		winner ← i + 1
	ELSE IF p > max2:
		max2 ← p

PRINT winner, max2

```

---

## ⏱️ Complexity

- **Time Complexity:** O(n) — single pass over all bids.
- **Space Complexity:** O(1) — only a few variables are stored.
