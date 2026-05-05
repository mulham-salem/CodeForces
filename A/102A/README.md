# Problem 102A – Clothes

## 🧩 Problem Summary
You are given `n` clothing items and `m` pairs of items that are compatible (they match each other).

Each item has a price. The task is to choose **3 items** such that:
- Every pair among the 3 items is compatible (they form a triangle in a graph).
- The total cost (sum of prices) is minimized.

If no such triple exists, output `-1`.

---

## 📥 Input
- `n m` → number of items and number of matching pairs
- `a[i]` → price of each item
- `m` lines → each contains `u v` meaning item `u` matches item `v`

---

## 📤 Output
- Minimum cost of 3 mutually compatible items
- Or `-1` if no valid triple exists

---

## 🧠 Idea
The problem reduces to finding a **triangle in an undirected graph** with minimum sum of node weights.

A triangle means:
- u is connected to v
- u is connected to w
- v is connected to w

---

## 🚀 Approach (Pseudocode)
```
store graph in adjacency sets store all edges

answer = INF

for each edge (u, v): 
	for each neighbor w of u: 
		if w == v: continue

	if v is connected to w:
			answer = min(answer, price[u] + price[v] + price[w])

if answer not updated: 
	print -1 
else: 
	print answer
```
---

## 💡 Key Insight
Instead of checking all triples (O(n³)), we:
- Fix an edge (u, v)
- Try to find a common neighbor w
- Verify if (v, w) also exists

This ensures we find valid triangles efficiently.

---

## 🔍 Example

### Input

3 3 1 2 3 1 2 2 3 3 1

### Graph
- 1 connected to 2, 3
- 2 connected to 1, 3
- 3 connected to 1, 2

### Valid triangle
(1, 2, 3)

### Output

6

---

## ❌ Example (No triangle)

### Input

3 2 2 3 4 2 3 2 1

No 3 fully connected nodes exist.

### Output

-1

---

## ⏱ Complexity
- Approximately `O(m * sqrt(m))`
- Efficient due to adjacency set lookups and smart iteration

---

## 🧾 Summary
We detect triangles in an undirected graph
and compute the minimum weighted triangle.

---