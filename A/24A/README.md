# Problem 24A – Ring Road

## 📌 Problem Overview

There are `n` cities connected in a **single ring (cycle)**.  
Initially, roads are directed and each road has a cost to reverse its direction.

Your goal is to make the graph **strongly connected** by reversing some roads with minimum total cost.

Because the structure is already a cycle (ignoring direction), the only possible valid solutions are:

- Keep the cycle direction as it is.
- Reverse the entire cycle.

So we compute both possibilities and take the minimum cost.

---

## 💡 Key Observations

- The cities already form a cycle if we ignore directions.
- Each city has exactly two neighbors.
- To make it strongly connected, all roads must follow the same circular direction.
- There are only **two possible directions** for the ring.

---

## 🔎 Approach

### Step 1 — Read Input

Store all roads:

```

ai → bi with cost ci

```

Keep them in a list of directed edges.

---

### Step 2 — Build Undirected Graph

Ignore directions.

Create adjacency lists:

```

For each road (a, b):
Add b to adjacency[a]
Add a to adjacency[b]

```

Now the graph represents the ring structure.

---

### Step 3 — Extract Ring Order

Since every node has exactly 2 neighbors:

- Start from any city.
- Move to a neighbor.
- At each step, go to the neighbor that is NOT the previous city.
- Stop when you return to the starting city.

Store cities in an array:

```

ring_order[]

```

This gives the cities in cycle order.

---

### Step 4 — Cost Calculation Function

Define a function:

```
computeCost(ring_order):

total_cost = 0

For each i from 0 to n-1:
    u = ring_order[i]
    v = ring_order[(i + 1) mod n]

    If road exists from u → v:
        continue

    Else if road exists from v → u:
        total_cost += cost of reversing that road

return total_cost
```

---

### Step 5 — Try Both Directions

```

cost1 = computeCost(ring_order)

Reverse ring_order

cost2 = computeCost(ring_order)

Answer = min(cost1, cost2)

```

---

## 🧠 Example

### Input

```

3
1 2 5
2 3 4
3 1 7

```

### Extracted Ring

```

1 → 2 → 3 → 1

```

---

### Compute Cost (Direction 1)

All roads already match → cost = 0

---

### Compute Cost (Reversed Direction)

All roads must be reversed:

```

Reverse 1→2 (cost 5)
Reverse 2→3 (cost 4)
Reverse 3→1 (cost 7)

```

Total = 16

---

### Final Answer

```

min(0, 16) = 0

```

---

## ⏱ Complexity

- Building graph → O(n)
- Extracting ring → O(n)
- Computing cost → O(n²) (can be optimized)

Since `n ≤ 100`, this is safe.

---

## 🚀 Pseudocode

```
read n

edges = []
for i = 1 to n:
read a, b, c
edges.add(a, b, c)

# Build undirected graph

adj = array of n+1 empty lists

for each edge (a, b, c) in edges:
adj[a].add(b)
adj[b].add(a)

# Extract ring order

start = 1
curr = start
prev = -1
ring_order = []

do:
ring_order.append(curr)
mark curr as visited

for neighbor in adj[curr]:
    if neighbor != prev:
        next_city = neighbor
        break

prev = curr
curr = next_city

while curr != start

# Function to compute cost

function computeCost(order):
total = 0

for i from 0 to n-1:
    u = order[i]
    v = order[(i+1) mod n]

    if edge exists from u to v:
        continue
    else if edge exists from v to u:
        total += cost_of_that_edge

return total


cost1 = computeCost(ring_order)

reverse(ring_order)

cost2 = computeCost(ring_order)

print min(cost1, cost2)

```

✅ Key Takeaway

The graph already forms a cycle.

Only two global directions are possible.

Compute both costs and take the minimum.

---

