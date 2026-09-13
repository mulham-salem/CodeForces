# Problem 290A – Mysterious strings

## Problem Statement

Given an integer `a` (1 ≤ a ≤ 40), output the name of the **a-th President of the United States**.

---

## Input

A single integer `a` (1 ≤ a ≤ 40).

---

## Output

A single string — the full name of the a-th U.S. President.

---

## Examples

### Example 1:

**Input:**
```

2

```
**Output:**
```

Adams

```


---

### Example 2:

**Input:**
```

8

```
**Output:**
```

Van Buren

```

---

### Example 3:

**Input:**
```

29

```
**Output:**
```

Harding

```

---

## Solution Idea

Since the number of presidents is fixed and small (only 40), the simplest and most efficient approach is to **predefine an array** containing all 40 president names in order. Then, for each input `a`, simply print the element at index `a`.

- Index `0` is left empty (or unused) so that index `a` directly corresponds to the a-th president.
- This gives **O(1)** time complexity per query.

---

## Pseudocode

```

START
READ integer a
DECLARE array presidents[41] with names of all 40 US presidents
(index 0 empty, index 1 = "Washington", ..., index 40 = "Reagan")
PRINT presidents[a]
END

```

---

## Notes

- This is a classic **lookup table** problem — no computation needed, just mapping input to a fixed answer.
- Be careful to match the **exact spelling** of each president's name as expected by the judge.
- Two presidents share the name "Adams" (2nd and 6th), "Harrison" (9th and 23rd), "Cleveland" (22nd and 24th), "Roosevelt" (26th and 32nd), and "Johnson" (17th and 36th) — make sure the correct one appears at the right index.

---