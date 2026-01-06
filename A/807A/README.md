# Problem 807A – Is it rated?

## Requirement
You are given the results of **n contestants** in a contest:

- Each contestant has a **rating** and a **place** (rank)
- The results are given **from first to last place**

Your task is to determine **whether the contest is rated**.

A contest is considered **rated** if:

1. There exists at least one contestant whose **rating changes** incorrectly (current rating not consistent with ranking), OR
2. The results are **not in non-increasing order of ratings** for the given ranks.

---

## Input
- Integer **n** — number of contestants  
- Next **n lines**: each line contains two integers:  
```

rating place

```
Ratings and places are integers.

---

## Output
Print one of the following:

- `"rated"` — if the contest is rated  
- `"unrated"` — if the contest is not rated but ratings are **not strictly decreasing** with ranks  
- `"maybe"` — if the contest is not rated and ratings are **non-increasing with ranks**

---

## Examples

### Example 1
**Input**
```

3
1000 1
1500 2
2000 3

```

**Output**
```

rated

```

**Explanation**

Ratings decrease incorrectly with rank → contest is rated.

---

### Example 2
**Input**
```

3
2000 1
2000 2
2000 3

```

**Output**
```

maybe

```

**Explanation**

Ratings are non-increasing, no inconsistencies → maybe.

---

## Solution Idea

1. Traverse the list of contestants from first to last.  
2. If **any rating is not consistent with ranking**, mark as `"rated"`.  
3. If all ratings are consistent but **ratings decrease inconsistently** with ranks, mark `"unrated"`.  
4. Otherwise, mark `"maybe"`.

---

## Algorithm

- Initialize a variable `prev_rating` with the first contestant's rating.  
- For each contestant:
  - If `current_rating > prev_rating`, contest is `"rated"`.
  - Update `prev_rating` = `current_rating`.
- If no inconsistencies but ratings are not strictly decreasing, output `"maybe"`.  
- Else output `"unrated"`.

---

## Complexity
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

---

## Key Insight
- A contest is `"rated"` if ratings **violate rank order**.  
- If no violations, check if ratings are **non-increasing** to decide `"maybe"`.  
- Otherwise, it is `"unrated"`.