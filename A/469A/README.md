# Problem 469A – I Wanna Be the Guy

## Requirement
There is a game with **n levels**.  

- Two players (or sets of levels) are given:
  - Player X can pass **p** levels: `x₁, x₂, …, xₚ`
  - Player Y can pass **q** levels: `y₁, y₂, …, y_q`  

Your task is to determine whether, **together**, they can pass **all n levels**.

---

## Input
- Integer **n** — total number of levels  
- Integer **p** and **p** integers — levels X can pass  
- Integer **q** and **q** integers — levels Y can pass  

---

## Output
- Print `I become the guy.` if all levels can be passed  
- Print `Oh, my keyboard!` otherwise

---

## Examples

### Example 1
**Input**
```

4
3 1 2 3
2 2 4

```

**Output**
```

I become the guy.

```

**Explanation**

Levels 1, 2, 3 → player X  
Levels 2, 4 → player Y  
Together they cover all levels 1, 2, 3, 4.

---

### Example 2
**Input**
```

3
1 1
1 3

```

**Output**
```

Oh, my keyboard!

```

**Explanation**

Level 2 is missing → cannot pass all levels.

---

## Solution Idea
1. Use a set to store all **unique levels** that can be passed.
2. Add all levels from both players.
3. If the size of the set = n → all levels covered → print `I become the guy.`
4. Otherwise → print `Oh, my keyboard!`

---

## Important Notes
- Levels are numbered from **1 to n**
- Duplicate levels do **not** matter
- Order of levels is irrelevant

---

## Complexity
- **Time Complexity:** O(p + q)
- **Space Complexity:** O(n)

---

## Key Insight
All levels must be covered at least once.
Using a set automatically removes duplicates and allows easy counting.
