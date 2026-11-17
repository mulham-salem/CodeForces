# Problem 368A – Sereja and Coat Rack

## 📌 Problem Summary

Sereja owns a restaurant with **n coat hooks**. Each hook `i` costs `a[i]` rubles to use. Tonight **m guests** arrive, and each guest picks the **cheapest available hook**. If no hooks are available, Sereja must pay a **fine of d rubles** to that guest.

Find the total profit (possibly negative).

---

## 💡 Approach

1. Read `n` and `d`.
2. Read the array `a` of hook prices.
3. Sort the prices in **ascending order** so guests always take the cheapest hook.
4. Read `m` (number of guests).
5. Loop over `m` guests:
   - If `i < n` → a hook is available → add `a[i]` to profit.
   - Else → no hooks left → subtract `d` from profit.
6. Print the profit.

---

## 🧪 Example 1

**Input:**
```

2 1
2 1
2

```

**Explanation:**
- Sorted hooks: `[1, 2]`
- Guest 1 → pays `1`
- Guest 2 → pays `2`
- Total profit = `1 + 2 = 3`

**Output:** `3`

---

## 🧪 Example 2

**Input:**
```

2 1
2 1
10

```

**Explanation:**
- Sorted hooks: `[1, 2]`
- Guests 1–2 pay `1 + 2 = 3`
- Guests 3–10 (8 guests) → no hooks → fine `8 × 1 = 8`
- Total profit = `3 − 8 = −5`

**Output:** `-5`

---

## 🧾 Pseudocode

```

READ n, d
READ array a of size n
SORT a ascending

READ m

profit = 0
FOR i = 0 TO m-1:
	IF i < n:
		profit += a[i]
	ELSE:
		profit -= d

PRINT profit

```

---

## ⏱️ Complexity

- **Time:** `O(n log n + m)` — sorting dominates.
- **Space:** `O(n)` — storing hook prices.
