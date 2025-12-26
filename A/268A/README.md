# Problem 268A – Games

## Requirement

You are given `n` football teams.  

Each team has:
- a **home uniform color**
- an **away uniform color**

When team `i` plays **at home** against team `j`:
- team `i` wears its **home** uniform
- team `j` wears its **away** uniform

A **color conflict** occurs if the **home color of one team matches the away color of another team**.

Your task is to count the **total number of color conflicts**.

---

## Input

- Integer `n` — number of teams
- `n` lines each containing two integers:
  - first integer — home color
  - second integer — away color

---

## Output

- One integer — total number of color conflicts

---

## Examples

### Example 1

**Input**
```

3
1 2
2 4
3 1

```

**Output**
```

2

```

**Explanation**
```

Teams:
1 → home:1, away:2
2 → home:2, away:4
3 → home:3, away:1

Conflicts:

* Team 1 (home=1) vs Team 3 (away=1)
* Team 2 (home=2) vs Team 1 (away=2)

Total conflicts = 2

```

---

### Example 2

**Input**
```

2
1 1
2 1

```

**Output**
```

1

```

**Explanation**
```

Teams:
1 → home:1, away:1
2 → home:2, away:1

Conflicts:

* Team 1 (home=1) vs Team 2 (away=1)

Total conflicts = 1

```

---

## Solution Idea

1. For every pair of **different teams** `(i, j)`:
   - Compare `home[i]` with `away[j]`.
   - If equal → conflict occurs.

2. Count all such conflicts across all pairs.

---

## Important Notes

- Do not compare a team with itself.
- Each pair `(i, j)` is considered **once**.
- This problem tests **nested loop comparisons** and careful counting.

---

## Complexity

- **Time Complexity:** `O(n²)`  
- **Space Complexity:** `O(n)`  

---

## Key Insight

A color conflict occurs **only** when the home uniform of a team matches the away uniform of another team.
Counting all such occurrences gives the answer.