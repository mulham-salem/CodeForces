# Problem 152A – Marks

## Overview

A group contains **n students** and **m subjects**.  
Each student has a mark from **1 to 9** in every subject.

A student is considered **the best** in a subject if no other student has a higher mark in that subject.

A student is called **successful** if they are the best in **at least one subject**.

Your task is to determine how many students are successful.

---

## Input

- Two integers `n` and `m`:
  - `n` — number of students.
  - `m` — number of subjects.
- The next `n` lines contain strings of length `m`.
- Each character represents a student's mark in a subject.

### Example

```text
3 3
223
232
112
```

---

## Output

Print a single integer — the number of successful students.

### Example

```text
2
```

---

## Idea

For every subject:

1. Find the highest mark achieved in that subject.
2. Mark every student who has this highest mark as successful.

After processing all subjects, count how many students were marked successful.

---

## Example Walkthrough

### Input

```text
3 3
223
232
112
```

### Marks Table

| Student | Subject 1 | Subject 2 | Subject 3 |
|----------|----------|----------|----------|
| 1 | 2 | 2 | 3 |
| 2 | 2 | 3 | 2 |
| 3 | 1 | 1 | 2 |

### Best Students

| Subject | Highest Mark | Best Student(s) |
|----------|----------|----------|
| 1 | 2 | 1, 2 |
| 2 | 3 | 2 |
| 3 | 3 | 1 |

Successful students are:

- Student 1
- Student 2

Answer:

```text
2
```

---

## Pseudocode

```text
read n, m

read all students' marks

successful = array of size n initialized with false

for each subject:
    find maximum mark in this subject

    for each student:
        if student's mark equals maximum:
            successful[student] = true

count successful students

print count
```

---

## Complexity Analysis

- Time Complexity: **O(n × m)**
- Space Complexity: **O(n)**

---