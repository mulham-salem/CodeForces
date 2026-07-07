# Problem 182A – Battlefield

## Problem Description

Vasya is playing a game on a battlefield that contains `n` trenches.  
Each trench is a horizontal or vertical line segment, and no two trenches intersect.

There is a laser that works in cycles:

- It charges for `a` seconds.
- Then it shoots continuously for `b` seconds.
- This cycle repeats forever.

During the shooting period, Vasya must be inside a trench.  
During the charging period, he can move freely anywhere.

Vasya starts at point `A` and needs to reach point `B`.

He moves with speed `1 meter/second`, and entering or leaving a trench takes no time.

The goal is to find the minimum time needed to reach point `B`.

If it is impossible, print `-1`.

---

## Input

The first line contains two integers:
```
a b
```
- `a` → duration of the charging period.
- `b` → duration of the shooting period.

The second line contains four integers:
```
Ax Ay Bx By
```
Coordinates of the starting point `A` and ending point `B`.

The third line contains:
```
n
```
The number of trenches.

The next `n` lines describe each trench:
```
x1 y1 x2 y2
```
Each trench is either:

- Horizontal (`y1 = y2`)
- Vertical (`x1 = x2`)

The length of every trench does not exceed `b`.

---

## Output

Print the minimum time required for Vasya to reach point `B`.

If Vasya cannot reach `B`, print: -1

The answer is accepted with an absolute or relative error of `10^-4`.

---

## Approach

The problem can be modeled as a **Shortest Path problem**.

### Graph Representation

Each important location is treated as a node:

- Starting point `A`
- Every trench
- Destination point `B`

An edge between two nodes represents moving from one location to another.

The edge weight is the time needed to travel between them while respecting the laser timing rules.

---

## Algorithm

1. Build a graph:
   - Compute distances between:
     - `A` and every trench.
     - `B` and every trench.
     - Every pair of trenches.

2. Use **Dijkstra's Algorithm** to find the shortest travel time from `A` to `B`.

3. While relaxing edges:
   - If the laser is shooting, Vasya cannot move outside trenches.
   - Wait until the next charging period if necessary.
   - Move during the available charging time.
   - Add the travel distance as time.

4. The shortest distance obtained by Dijkstra is the answer.

---

## Important Observations

- The laser cycle length is:

`a + b`

- The beginning of the game is always the start of a charging period.
- Vasya can arrive exactly when shooting starts because being inside the trench at that moment is allowed.
- Since every trench length is at most `b`, staying inside a trench during the shooting period is always possible.

---

## Complexity Analysis

Let:

`V = n + 2`

where:

- `n` = number of trenches.
- Two extra nodes represent `A` and `B`.

Building the graph:

`O(n²)`

Dijkstra using a priority queue:

`O(V² log V)`

Overall complexity:

`O(n² log n)`

which is suitable for:

`n ≤ 1000`

---

## Pseudocode
```
Create nodes: A all trenches B

For every pair of nodes: calculate the distance between them

Run Dijkstra:

start distance of A = 0

while there are unprocessed nodes:
    take node with smallest time

    for every neighbour:
        calculate the earliest possible departure time
        considering laser phases

        update shortest time

If B was reached: print answer Else: print -1
```

---