# Problem 76A – Gift

## 📌 Problem Overview

You are given a graph with:
- **N cities**
- **M bidirectional roads**

Each road has two requirements:
- `g` → minimum gold coins required
- `s` → minimum silver coins required

You are also given:
- `G` → cost of 1 gold coin
- `S` → cost of 1 silver coin

---

## 🎯 Goal

Choose a gift containing:
- `a` gold coins
- `b` silver coins

such that:
- A road becomes usable if `g ≤ a` AND `s ≤ b`
- All cities become connected using usable roads
- The total cost is minimized:

cost = a * G + b * S

---

## 🧠 Key Idea

We want to:
1. Increase gold threshold (`a`)
2. Use only roads that satisfy `g ≤ a`
3. Among those roads, build a **minimum set that connects all cities**
4. Determine the required silver level (`b`) as the maximum `s` among used roads
5. Minimize total cost

---

## 🔑 Observations

- A valid solution must connect all cities → exactly `N - 1` roads are needed
- For a fixed gold level `a`, we only consider edges with `g ≤ a`
- Among those, we choose the best subset that connects all nodes while minimizing silver usage

---

## 🧩 Algorithm Idea

We iterate over edges sorted by gold requirement and progressively build candidate solutions.

For each gold level:
- Collect all edges with `g ≤ current_g`
- Sort them by silver requirement
- Use DSU (Disjoint Set Union) to pick edges that connect components without cycles
- Track the maximum silver used in the chosen edges
- Compute cost and update answer

---

## 🧪 Example

### Input

3 3 2 1 1 2 10 15 1 2 4 20 1 3 5 1

### Explanation

If we choose:
- `a = 5` (gold)
- usable roads:
  - (1–2), (1–3)

We can connect all cities using:
- (1–2), (1–3)

Maximum silver used:
- `b = 20`

Cost:

5 * 2 + 20 * 1 = 30

---

## ⚙️ Pseudocode

```
sort edges by g ascending

answer = INF

for each edge i: 
	activate edge i (g threshold increases)

keep only edges with g <= current threshold

sort active edges by s ascending

DSU init

chosen_edges = []

for edge in active:
    if unite(edge.u, edge.v):
        add edge to chosen_edges

if chosen_edges size == N - 1:
    b = max(s in chosen_edges)
    cost = current_g * G + b * S
    answer = min(answer, cost)

print answer
```

---

## 🚀 Complexity

- Sorting edges: `O(M log M)`
- DSU operations: nearly `O(M α(N))`

Efficient enough for:
- `N ≤ 200`
- `M ≤ 50000`

---

## 🧾 Summary

We try different gold thresholds, and for each:
- build the best possible connected graph using available roads
- compute required silver level
- minimize total cost

---