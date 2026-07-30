# Problem 212A – Privatization

## Problem Description

You are given a bipartite graph representing a network of flights between two countries:

- `n` cities in Berland.
- `m` cities in Beerland.
- `k` flights connecting cities from the two countries.
- Each flight must be sold to one of `t` private companies.

Each company wants to get as many flights as possible, but the government wants the distribution to be as fair as possible.

For every city `i`, let:

$$
a_{ij} = \text{number of flights connected to city } i \text{ that belong to company } j
$$

The unevenness of city `i` is:

$$
w_i = \sum_{j=1}^{t} a_{ij}^{2}
$$

The total unevenness is:

$$
\sum w_i
$$

The goal is to minimize the total unevenness.

---

# Observation

For a city with degree `d`, we need to distribute its flights among `t` companies.

The contribution of this city is:

$$
x_1^2 + x_2^2 + \dots + x_t^2
$$

where:

$$
x_1+x_2+\dots+x_t=d
$$

To minimize this value, the flights must be distributed as equally as possible.

So every company should receive either:

$$
\left\lfloor \frac{d}{t} \right\rfloor
$$

or:

$$
\left\lceil \frac{d}{t} \right\rceil
$$

flights.

Therefore, the minimum unevenness depends only on whether the degree is divisible by `t`.

If:

$$
degree \bmod t \neq 0
$$

the city contributes `1` to the answer.

So:

$$
\text{Minimum Unevenness}
=
\text{Number of cities where } degree \bmod t \neq 0
$$

---

# Transforming the Problem

The problem can be converted into an **Edge Coloring** problem.

Each company represents a color:

```
Company 1 → Color 1
Company 2 → Color 2
...
Company t → Color t
```

Each flight is an edge.

The required condition becomes:

> No two flights connected to the same city can have the same color.

This is exactly the definition of edge coloring.

---

# Problem With High Degree Cities

Using only `t` colors is possible when:

$$
degree(v) \leq t
$$

But some cities may have a larger degree.

Example:

```
degree = 10
t = 3
```

A single city with degree `10` cannot be colored using only `3` colors.

So we split cities into virtual nodes.

---

# Splitting Cities

For every city, create:

$$
\left\lceil \frac{degree}{t} \right\rceil
$$

virtual nodes.

Each virtual node can contain at most `t` flights.

### Example

Suppose:

```
degree = 8
t = 3
```

Number of virtual nodes:

$$
\left\lceil \frac{8}{3} \right\rceil = 3
$$

The city becomes:

```
City_0
City_1
City_2
```

The flights are distributed:

```
City_0 → 3 flights
City_1 → 3 flights
City_2 → 2 flights
```

Now:

$$
degree(\text{any virtual node}) \leq t
$$

So we can color the graph using `t` colors.

---

# Assigning Flights To Virtual Nodes

While processing flights, we keep the number of already assigned flights for every original city.

For each flight:

Choose the virtual node using:

$$
\frac{current\_degree}{t}
$$

because integer division groups every `t` flights into one virtual node.

Example:

For:

```
t = 3
```

The indices become:

```
0 / 3 = 0
1 / 3 = 0
2 / 3 = 0

3 / 3 = 1
4 / 3 = 1
5 / 3 = 1

6 / 3 = 2
```

Meaning:

```
First 3 flights  → Virtual node 0
Next 3 flights   → Virtual node 1
Next flights     → Virtual node 2
```

---

# Edge Coloring Algorithm

For every new edge `(u, v)`:

1. Find the first unused color at `u`.

Call it:

```
c1
```

2. Find the first unused color at `v`.

Call it:

```
c2
```

---

## Case 1: Same Available Color

If:

$$
c1 = c2
$$

We assign this color directly.

---

## Case 2: Different Available Colors

If:

$$
c1 \neq c2
$$

We need to rearrange some previous colors.

We find an alternating path that uses only these two colors:

```
c1
c2
c1
c2
...
```

Then swap the colors on this path.

Before:

```
c1 - c2 - c1 - c2
```

After:

```
c2 - c1 - c2 - c1
```

This frees one color at the required endpoint, allowing the new edge to receive a valid color.

---

# Algorithm

```text
Read n, m, k, t

Read all flights

Calculate degree of every city


Calculate minimum unevenness:

    answer = 0

    For every city:

        if degree % t != 0:
            answer++



Create virtual nodes:

    For every city:

        parts = ceil(degree / t)

        create parts virtual nodes



For every flight:

    Get original endpoints

    Choose virtual node for each endpoint:

        virtual_index = current_degree / t


    Increase current degrees


    Add edge between virtual nodes


    Color the edge:

        Find free colors c1 and c2

        If c1 == c2:

            assign c1


        Else:

            Find alternating path

            Swap colors on the path

            Assign the freed color



Print:

    minimum unevenness

    colors of all original flights
```

---

# Example

### Input

```
3 5 8 2
1 4
1 3
3 3
1 2
1 1
2 1
1 5
2 2
```

There are:

```
8 flights
2 companies
```

The minimum possible unevenness is:

```
4
```

One valid assignment:

```
2 1 2 1 2 1 2 2
```

Meaning each number is the company that buys the corresponding flight.

---

# Complexity

The constraints are small:

```
n, m ≤ 200
k ≤ 5000
t ≤ 200
```

The algorithm is efficient enough for the given limits.

---

# Concepts Used

- Bipartite Graph
- Edge Coloring
- Virtual Nodes
- Graph Splitting
- Alternating Paths
- Recoloring

---