# Problem 166A – Rank List

## Problem Summary
You are given the final results of a programming contest.  
Each team is described by:
- `p`: number of solved problems
- `t`: total penalty time

The final ranking follows these rules:
1. A team ranks higher if it solved **more problems**.
2. If two teams solved the same number of problems, the one with **less penalty time** ranks higher.
3. Teams with exactly the same `(p, t)` are considered **equal** and share consecutive places.

Your task is to determine **how many teams share the `k`-th place**.

---

## Key Observation
After sorting all teams according to the contest rules:
- Teams with identical `(p, t)` values will appear **next to each other**.
- The team at index `k-1` (0-based indexing) represents the `k`-th place.
- All teams with the same `(p, t)` as that team share the `k`-th place.

So the problem reduces to:
> Count how many teams have the same `(p, t)` as the team at position `k-1` after sorting.

---

## Sorting Criteria
Teams must be sorted by:
1. Number of solved problems `p` — **descending**
2. Penalty time `t` — **ascending**

---

## Example 1
Input:
```

7 2
4 10
4 10
4 10
3 20
2 1
2 1
1 10

```

After sorting:
```

(4,10), (4,10), (4,10), (3,20), (2,1), (2,1), (1,10)

```

- The 2nd place corresponds to `(4,10)`
- There are **3 teams** with `(4,10)`

Output:
```

3

```

---

## Example 2
Input:
```

5 4
3 1
3 1
5 3
3 1
3 1

```

After sorting:
```

(5,3), (3,1), (3,1), (3,1), (3,1)

```

- The 4th place corresponds to `(3,1)`
- There are **4 teams** with `(3,1)`

Output:
```

4

```

---

## Pseudocode

```

read n, k
read list of teams (p, t)

sort teams by:
p descending
t ascending

target = teams[k - 1]

count = 0
for each team in teams:
if team.p == target.p and team.t == target.t:
count++

print count

```

---

## Complexity Analysis
- Sorting: `O(n log n)`
- Counting: `O(n)`
- Constraints are small (`n ≤ 50`), so this solution is efficient.

---

## Conclusion
By sorting the teams correctly and counting how many match the `k`-th ranked team, the problem can be solved cleanly without explicitly simulating ranks.

---