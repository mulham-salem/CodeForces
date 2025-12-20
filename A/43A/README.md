# Problem 43A – Football

## Problem Description
You are given the results of a football match.  
The match consists of several goal records, and **each record contains the name of the team that scored a goal**.

Your task is to determine **which team won the match**.

---

## What is Required?
1. Read an integer `n` — the number of goals scored.
2. Read `n` strings — each string is the name of the team that scored a goal.
3. Count how many goals each team scored.
4. Print the name of the team with **more goals**.

> It is guaranteed that **only two different teams** appear and there is **no draw**.

---

## Examples

### Example 1
**Input**
```

5
A
ABA
A
ABA
A

```

**Explanation**
- Team `A` scored 3 goals
- Team `ABA` scored 2 goals

**Output**
```

A

```

---

### Example 2
**Input**
```

1
Barcelona

```

**Explanation**
- Only one goal → only one team

**Output**
```

Barcelona

```

---

## Key Idea
> Count how many times each team name appears and choose the one with the higher count.

---

## Summary
- Read goal count
- Count goals per team
- Print the team with more goals
