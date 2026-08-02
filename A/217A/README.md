# Problem 217A – Ice Skating

## Idea

Treat each snow drift as a **node** in a graph.

Two nodes are directly connected if they share the same **x-coordinate** (same column) or the same **y-coordinate** (same row).

Our goal is to connect all disconnected groups (connected components) by adding the minimum number of new snow drifts.

A **Disjoint Set Union (DSU)** data structure efficiently finds and merges these connected components.

---

## Observation

If two snow drifts have:

- the same `x`, or
- the same `y`

they belong to the same connected component.

After processing every pair of snow drifts, the DSU contains all connected components.

If there are `k` connected components, we need exactly:

```
k - 1
```

new snow drifts to connect them all.

Why?

Each new connection can merge **two connected components**, reducing the number of components by exactly **one**.

Therefore:

- 4 components → 3 connections
- 3 components → 2 connections
- 2 components → 1 connection

Hence the answer is always:

```
Connected Components - 1
```

---

## Algorithm

1. Read all snow drifts.
2. Initialize a DSU with `n` nodes.
3. For every pair of snow drifts:
   - If they have the same `x` or the same `y`, merge them using `Union`.
4. Count the number of connected components by counting nodes that are their own representative (`Find(i) == i`).
5. Print `components - 1`.

---

## Pseudocode

```text
Read n

Read all points

Initialize DSU with n nodes

For every pair of points (i, j):
    If x[i] == x[j] OR y[i] == y[j]:
        Union(i, j)

components = 0

For each node i:
    If Find(i) == i:
        components++

Print (components - 1)
```

---

## Correctness

The DSU groups together every snow drift that is reachable from one another.

After all unions are performed, each DSU set represents exactly one connected component.

Connecting `k` disconnected components always requires at least `k - 1` connections, and each added snow drift can merge one pair of components.

Therefore, `components - 1` is both necessary and sufficient.

---

## Complexity Analysis

- **Time Complexity:** `O(n² · α(n))`
- **Space Complexity:** `O(n)`

where `α(n)` is the inverse Ackermann function (practically constant).

---