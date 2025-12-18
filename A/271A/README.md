# Problem 271A – Beautiful Year

## Requirement
Given a year **y** (4 digits), find the smallest year that is **strictly greater than y**
and has **all four digits different**.

In other words:
- The year must be **greater than y**
- **No digit is repeated**

---

## Examples

### Example 1

**Input**
1987

**Output**
2013

**Explanation**

1988 → digit '8' is repeated
1989 → digit '9' is repeated later
...
2013 → digits {2, 0, 1, 3} are all different → valid answer
---

### Example 2

**Input**
2013

**Output**
2014

**Explanation**

2014 has digits {2, 0, 1, 4}
All digits are distinct and it is the next valid year.

---

### Example 3

**Input**
1000

**Output**
1023

**Explanation**

1001, 1002, ... contain repeated digit '0' or '1'
1023 has digits {1, 0, 2, 3} → all unique

---
## Solution Idea

- Start checking from **year y + 1**
- Convert the year to a string
- Compare every digit with the others
- If all digits are different, print the year and stop
