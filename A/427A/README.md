# Problem 427A – Police Recruits

## Requirement
You are given:

- An integer **n** — the number of events.
- A sequence of **n** integers describing events.

Each event is:
- A **positive integer** → hiring that many police officers.
- `-1` → a crime occurs.

Police officers can handle crimes **only if at least one officer is available**.
If a crime occurs when no officers are available, it goes **untreated**.

Your task is to count how many crimes go untreated.

---

## Input
- Integer **n**
- **n** integers — the events

---

## Output
- One integer — the number of untreated crimes

---

## Examples

### Example 1
**Input**
```

5
-1 -1 1 -1 -1

```

**Output**
```

3

```

**Explanation**

Events timeline:
- Crime → no police → untreated (1)
- Crime → no police → untreated (2)
- Hire 1 officer → police = 1
- Crime → police used → police = 0
- Crime → no police → untreated (3)

---

### Example 2
**Input**
```

6
3 -1 -1 -1 -1 -1

```

**Output**
```

2

```

**Explanation**

- Hire 3 officers → police = 3
- 3 crimes handled → police = 0
- 2 crimes occur with no police → untreated

---

## Solution Idea
1. Maintain a counter for available police officers.
2. Maintain a counter for untreated crimes.
3. Process events in order:
   - If event > 0 → add officers.
   - If event == -1:
     - If police > 0 → use one officer.
     - Else → increment untreated crimes.

---

## Important Notes
- Events must be processed **in order**.
- Officers cannot be reused after handling a crime.
- Only crimes without available police are counted.

---

## Complexity
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

---

## Key Insight
Only crimes that occur when **no police officers are available**
increase the answer.
