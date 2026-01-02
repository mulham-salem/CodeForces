# Problem 520A – Pangram

## Requirement
You are given:

- An integer **n** — the length of a string.
- A string **s** of length **n**, consisting of uppercase and lowercase English letters.

A string is called a **pangram** if it contains **every letter of the English alphabet**
at least once.

Your task is to determine whether the given string is a pangram.

---

## Input
- Integer **n**
- String **s**

---

## Output
- Print `YES` if the string is a pangram  
- Print `NO` otherwise

---

## Examples

### Example 1
**Input**
```

26
abcdefghijklmnopqrstuvwxyz

```

**Output**
```

YES

```

---

### Example 2
**Input**
```

12
toosmallword

```

**Output**
```

NO

```

---

## Solution Idea
1. Create a boolean array or a set of size 26.
2. Traverse the string:
   - Convert each character to lowercase.
   - Mark the corresponding letter as seen.
3. After traversal:
   - If all 26 letters are present → print `YES`
   - Otherwise → print `NO`

---

## Important Notes
- Letter case does **not** matter.
- Only English letters are considered.
- The value of `n` is not strictly required for the solution.

---

## Complexity
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

---

## Key Insight
A string is a pangram if it contains **all 26 English letters** at least once,
regardless of order or case.

