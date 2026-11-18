# Problem 369A – Valera and Plates

## Problem Explanation

Valera has `m` clean bowls and `k` clean plates. Over the next `n` days he will eat one dish per day. There are two dish types:

- **Type 1** → must be eaten from a **bowl**.
- **Type 2** → can be eaten from **either a bowl or a plate**.

After eating, the used bowl/plate becomes dirty and cannot be reused until washed. Valera acts optimally, so he only washes a dish when no clean suitable dish is available. We need to find the **minimum number of washes**.

---

## Approach (Greedy)

Process the days in order:

- If the day needs a **type 1** dish:
  - Use a clean bowl if available (`m > 0` → `m--`).
  - Otherwise, wash one → `ans++`.
- If the day needs a **type 2** dish:
  - Prefer using a clean **plate** first (`k > 0` → `k--`), because plates are only useful for type 2.
  - Otherwise use a clean bowl (`m > 0` → `m--`).
  - Otherwise wash one → `ans++`.

The key greedy idea: **save bowls for type 1 dishes**, since plates cannot be used for them.

---

## Examples

### Example 1
```

Input:
3 1 1
1 2 1

Output:
1

```
- Day 1 (type 1): use bowl → `m = 0`
- Day 2 (type 2): use plate → `k = 0`
- Day 3 (type 1): no bowl left → wash → `ans = 1`

---

### Example 2
```

Input:
4 3 1
1 1 1 1

Output:
1

```
- Days 1–3: use the 3 bowls → `m = 0`
- Day 4: no bowl left → wash → `ans = 1`

---

### Example 3
```

Input:
3 1 2
2 2 2

Output:
0

```
- Day 1: use plate → `k = 1`
- Day 2: use plate → `k = 0`
- Day 3: use bowl (type 2 allows it) → `m = 0`
- No washes needed → `ans = 0`

---

### Example 4
```

Input:
8 2 2
1 2 1 2 1 2 1 2

Output:
4

```
Bowls and plates run out quickly, and type 1 dishes force washes whenever no bowl is left, resulting in 4 washes.

---

## Pseudocode

```

read n, m, k
read array a[0..n-1]

ans = 0

for i from 0 to n-1:
	if a[i] == 1:
		if m > 0:
			m = m - 1
		else:
			ans = ans + 1
			
	else:  // a[i] == 2
		if k > 0:
			k = k - 1
		else if m > 0:
			m = m - 1
		else:
			ans = ans + 1

print ans

```

---

## Complexity

- **Time Complexity:** `O(n)` — we iterate over the `n` days exactly once, and each day is handled with constant-time operations.
- **Space Complexity:** `O(n)` for storing the array `a` (can be reduced to `O(1)` by processing days on the fly as they are read).
