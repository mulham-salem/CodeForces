# Problem 1204A – BowWow and the Timetable

## Requirement
You are given:

- An integer **n** — number of lessons  
- An array of integers **a** of length n — duration of each lesson in minutes  

BowWow wants to **maximize the number of lessons he can attend**.  
He can only attend **full lessons** and the **total time spent cannot exceed 240 minutes** (4 hours).

---

## Input
- Integer **n** — number of lessons  
- Array of integers:  
```

a1 a2 ... an

```
(1 ≤ n ≤ 100, 1 ≤ ai ≤ 100)

---

## Output
- One integer — maximum number of lessons BowWow can attend without exceeding 240 minutes.

---

## Example 1
**Input**
```

3
60 90 80

```

**Output**
```

2

```

**Explanation**

Lesson durations: 60, 90, 80  
- Attend lessons 1 and 2 → 60 + 90 = 150 ≤ 240  
- Attending all three → 60 + 90 + 80 = 230 > 240? Actually 230 ≤ 240, so all three fit  
Correction: let's recalc:

60 + 90 + 80 = 230 ✅ still ≤ 240  

So output should be 3

---

Better example:

**Input**
```

3
100 100 100

```

**Output**
```

2

```

**Explanation**

- Attend first two lessons → 100 + 100 = 200 ≤ 240  
- Adding the third → 200 + 100 = 300 > 240  
- Maximum lessons = 2

---

## Solution Idea

- Sort the lesson durations in **ascending order**  
- Attend lessons one by one starting from the **shortest**  
- Stop when adding the next lesson exceeds 240 minutes  

---

## Algorithm

1. Sort array `a` in ascending order  
2. Initialize `sum = 0` and `count = 0`  
3. For each lesson duration `x` in `a`:
   - If `sum + x ≤ 240`, add it to sum and increment count  
   - Else, break the loop  
4. Output `count`  

---

## Complexity
- **Time Complexity:** O(n log n) — for sorting  
- **Space Complexity:** O(1)  

---

## Key Insight
- Attending **shortest lessons first** maximizes the total number of lessons without exceeding 240 minutes.