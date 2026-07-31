# Problem 213A – Game

## Problem Description

Furik found a new game that consists of `n` parts.  
To complete some parts, Rubik may need to complete other parts first.

The dependencies between parts do not contain cycles, so the whole game can always be completed.

Rubik has **3 computers**. Each game part can only be completed on one specific computer.

Completing any part takes exactly **1 hour**.

Moving between computers also takes time:

| From | To | Time |
|------|----|------|
| 1 | 2 | 1 |
| 1 | 3 | 2 |
| 2 | 1 | 2 |
| 2 | 3 | 1 |
| 3 | 1 | 1 |
| 3 | 2 | 2 |

Rubik can start at any computer.

Your task is to find the minimum number of hours needed to complete all game parts.

---

## Input

The first line contains an integer:
```
n
```
- `1 ≤ n ≤ 200`
- Number of game parts.

The second line contains `n` integers:
```
c1 c2 ... cn
```
where `ci` is the computer where part `i` can be completed.

Then follow `n` lines describing dependencies.

The `i-th` line contains:
```
ki a1 a2 ... aki
```
where:

- `ki` is the number of parts that must be completed before part `i`.
- `a1, a2, ..., aki` are the required previous parts.

---

## Output

Print one integer:
```
the minimum number of hours required to complete all parts.
```
---

## Key Idea

The problem is based on **Topological Sort**.

Each game part is a node in a directed graph.

If part `x` must be completed before part `i`:

$$ x → i $$

We use `indegree`:

- `indegree[i]` = number of parts that must be completed before part `i`.

When:

$$ indegree[i] = 0 $$

the part becomes available.

---

## Observation

While Rubik is at a computer, it is always optimal to complete **all currently available parts on that computer** before moving.

The movement strategy is also important.

Moving in the cycle:

`1 → 2 → 3 → 1`

always costs `1` hour.

Moving backwards costs `2` hours, which is the same as moving forward through the remaining computer.

For example:

`2 → 1 = 2`

but:

`2 → 3 → 1 = 1 + 1 = 2`

Therefore, moving forward can never be worse.

We try the three possible starting computers:

`1 → 2 → 3 → 1 ...`

`2 → 3 → 1 → 2 ...`

`3 → 1 → 2 → 3 ...`

and take the minimum answer.

---

## Algorithm

For each starting computer:

1. Copy the original `indegree` array.

2. Create three queues:

`q[1]` : **available parts on computer 1** 
`q[2]` : **available parts on computer 2** 
`q[3]` : **available parts on computer 3**

3. Add all parts with:

`indegree = 0`

to their corresponding queue.

4. Start from the chosen computer.

5. While there are available parts:

   - Complete all available parts on the current computer.
   - For every completed part:
     - Decrease the indegree of dependent parts.
     - If a part becomes available, add it to its computer queue.
   - Move to the next computer in the cycle.

6. Remove the last unnecessary movement.

7. Return the total time.

The answer is the minimum result among the three starting positions.

---

## Complexity Analysis

Let:

- `n` = number of parts
- `m` = number of dependencies

Each part and dependency is processed once.

**Time complexity**: `O(n + m)`

**Memory complexity**: `O(n + m)`

---

## Example

### Input
```
5 
2 2 1 1 3
1 5 
2 5 1 
2 5 4 
1 5 
0
```
**Dependencies:**

`5 → 1`
`5 → 4` 
`5 → 2` 
`1 → 2` 
`4 → 3`
`5 → 3`

The best strategy:

1. Start at computer `3`.
2. Complete part `5`.

`+1 hour`

3. Move to computer `1`.

`+1 hour`

4. Complete parts `4` and `3`.

`+2 hours`

5. Move to computer `2`.

`+1 hour`

6. Complete parts `1` and `2`.

`+2 hours`

**Total:**

`1 + 1 + 2 + 1 + 2 = 7`

Output:
```
7
```

---