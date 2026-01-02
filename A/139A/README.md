# Problem 139A – Petr and Book

## Requirement
You are given:

- An integer **n** — the total number of pages in a book.
- An array of **7 integers** — the number of pages Petr reads on each day of the week  
  (from day 1 to day 7).

Petr reads the book following this weekly pattern.
After day 7, the pattern **repeats from day 1**.

Your task is to determine **on which day of the week** Petr finishes reading the book.

---

## Input
- Integer **n**
- 7 integers — pages read on days 1 through 7

---

## Output
- One integer (from 1 to 7) — the day of the week when the book is finished

---

## Examples

### Example 1
**Input**
```

100
15 20 20 15 10 30 45

```

**Output**
```

6

```

**Explanation**

Day-by-day reading:
- Day 1 → 15
- Day 2 → 35
- Day 3 → 55
- Day 4 → 70
- Day 5 → 80
- Day 6 → 110 ✅

The book is finished on **day 6**.

---

### Example 2
**Input**
```

200
10 10 10 10 10 10 10

```

**Output**
```

6

```

**Explanation**

Each day reads 10 pages.
Each week = 70 pages.

After 2 weeks → 140 pages  
In the 3rd week:
- Day 6 → 200 pages ✅

So the book is finished on **day 6**.

---

## Solution Idea
- Repeatedly traverse the 7 days in order.
- Subtract the pages read each day from **n**.
- As soon as `n ≤ 0`, stop.
- Output the **current day number**.

---

## Important Notes
- You do **not** count the total number of days.
- The week only represents a **repeating pattern**.
- The answer is always a number from **1 to 7**.

---

## Complexity
- **Time Complexity:** O(number of days needed)  
  (at most a few weeks, very small)
- **Space Complexity:** O(1)

---

## Key Insight
The reading pattern repeats every week.
Simulate the days until the remaining pages reach zero —
the day where this happens is the answer.
