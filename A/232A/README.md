# 232A - Cycles

## Problem

Given an integer `k`, construct an **undirected graph** that contains exactly `k` cycles of length `3` (triangles).

A cycle of length `3` consists of three distinct vertices where every pair of them is connected by an edge.

The graph must contain at most `100` vertices.

---

## Input

A single integer:

```text
k
```
where:

`1 ≤ k ≤ 10^5`

**k is the required number of triangles**


---

## Output

First, print an integer `n` — **the number of vertices in the constructed graph*

Then print an `n × n` **adjacency matrix**

*For every pair of vertices i and j:*

`1` **means there is an edge between them**

`0` **means there is no edge**


The matrix must be symmetric because the graph is undirected:
$$
graph[i][j] = graph[j][i]
$$
There must be no self-loops:
$$
graph[i][i] = 0
$$

---

## Key Idea

The solution uses the combinations formula:

$$
C(n,r)=\frac{n!}{r!(n-r)!}
$$

**We mainly use two cases.**

`1. Number of triangles in a complete graph`

If we have n vertices and every vertex is connected to every other vertex, every group of 3 vertices forms one triangle.

**Therefore:**
$$
C(n,3)=\frac{n(n-1)(n-2)}{6}
$$

In the code, this is represented by:
$$
C3(n)
$$

**For example:**
$$
C3(5) = C(5,3) = 10
$$
So a complete graph with `5` vertices contains exactly `10` triangles.


---

`2. Triangles created by a new vertex`

Suppose we add a new vertex and connect it to m existing vertices of the complete graph.

Every pair among those `m` vertices forms a triangle with the new vertex.

**Therefore:**
$$
C(m,2)=\frac{m(m-1)}{2}
$$

In the code, this is represented by:
$$
C2(m)
$$

**For example:**
$$
C2(4) = C(4,2) = 6
$$

So if a new vertex is connected to `4` existing vertices, it creates exactly `6` new triangles.


---

## Construction

First, we try different sizes of a complete graph.

For a chosen clique size:
$$
remaining = k - C3(clique)
$$

If `remaining < 0`, the complete graph already contains more triangles than required, so we skip this size.

Otherwise, we build the complete graph.

If triangles are still missing, we add new vertices.

For each new vertex, we choose the largest possible m such that:

`C2(m) ≤ remaining`

Then we connect the new vertex to m vertices of the original complete graph.

This creates exactly:

`C2(m)`

new triangles.

We subtract them from remaining and repeat until:

`remaining = 0`

At that point, the graph contains exactly `k` triangles.


---

## Why Does a New Vertex Create C2(m) Triangles?

Suppose a new vertex is connected to:
```
0, 1, 2
```
Since `0`, `1`, and `2` are part of the complete graph, they are already connected to each other.

Therefore, the new vertex creates these triangles:

`New - 0 - 1`
`New - 0 - 2`
`New - 1 - 2`

There are `3` triangles.

And:

`C(3,2)=3`

**In general:**

$$
\text{New triangles} = C(m,2)
$$

---

## Example

For:

```
k = 10
```
we can use a complete graph with `5` vertices.

**The number of triangles is:**
```
C(5,3)=10
```
Therefore, the graph already contains exactly the required number of triangles.

**Its adjacency matrix can be:**
```
01111
10111
11011
11101
11110
```
This means every vertex is connected to every other vertex.

---

## Pseudocode
```
read k

create an empty 100 × 100 adjacency matrix

for clique from 3 to 100:

    remaining = k - C3(clique)

    if remaining < 0:
        continue

    build a complete graph with `clique` vertices

    n = clique

    while remaining > 0:

        if n >= 100:
            this construction is impossible
            break

        m = 2

        while m + 1 <= clique
              and C2(m + 1) <= remaining:

            m++

        add a new vertex

        connect the new vertex
        to the first m vertices of the clique

        remaining -= C2(m)

        n++

    if remaining == 0:

        print n
        print the adjacency matrix

        finish
```

---

## Complexity

The graph contains at most `100` vertices.

**The adjacency matrix requires:** `O(n^2)` memory.

Since `n ≤ 100`, the solution easily fits within the limits.


---

## Summary

The solution works in two steps:

1. Build a complete graph that produces a large part of the required triangles.


2. Add new vertices to produce the remaining triangles exactly.

**The key formulas are:**
$$
C3(n)=\frac{n(n-1)(n-2)}{6}
$$
and:
$$
C2(m)=\frac{m(m-1)}{2}
$$
The final graph contains exactly `k` triangles and at most `100` vertices.

---