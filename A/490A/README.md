# Problem 490A – Team Olympiad

## Requirement
You are given:

- An integer **n** — the number of students.  
- Each student has a skill in **exactly one of three subjects**, represented by integers:  
  - `1` → programming  
  - `2` → maths  
  - `3` → PE  

Your task is to form as many **teams of 3 students** as possible, where each team has **one student from each subject**.  
Print the maximum number of teams and the indices of students in each team.

---

## Input
- Integer **n**  
- Next line: **n integers** `a₁ a₂ … aₙ` (1, 2, or 3)

---

## Output
- First line: integer — maximum number of teams  
- Next lines: indices of students in each team (3 integers per line)

---

## Examples

### Example 1
**Input**
```

7
1 3 1 3 2 1 2

```

**Output**
```

2
1 5 2
3 7 4

```

**Explanation**

- Students by skill:  
  - Programming (1): 1, 3, 6  
  - Maths (2): 5, 7  
  - PE (3): 2, 4  

- Max teams = min(count of each skill) = min(3, 2, 2) = 2  
- Teams formed:  
  - Team 1 → 1 (prog), 5 (math), 2 (PE)  
  - Team 2 → 3 (prog), 7 (math), 4 (PE)  

---

### Example 2
**Input**
```

5
1 1 2 2 3

```

**Output**
```

1
1 3 5

```

**Explanation**

- Counts: 1 → 2, 2 → 2, 3 → 1  
- Max teams = min(2,2,1) = 1  
- One team can be formed.

---

## Solution Idea
1. Maintain three lists to store the **indices of students** in each skill.  
2. The number of teams = `min(size of each list)`  
3. For each team, take **one student from each list** and print their indices.

---

## Important Notes
- Each student can belong to **only one team**.  
- Teams must contain **all three skills**.  
- Order of students in the team or output is arbitrary.  

---

## Complexity
- **Time Complexity:** O(n)  
- **Space Complexity:** O(n) (to store indices)

---

## Key Insight
Forming the maximum number of balanced teams is equivalent to **finding the minimum count** among the three skill groups.
