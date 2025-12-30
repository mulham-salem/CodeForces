# Problem 272A – Dima and Friends

## Problem Description

Dima and his friends are choosing who will clean the apartment using a counting-out game.

- Dima has **n friends**, so there are **n + 1 people** in total (including Dima).
- Each friend shows a number of fingers (from 1 to 5).
- Dima will also show a number of fingers (from 1 to 5).
- All people stand in a circle.
- The counting **starts from Dima** and continues clockwise.
- The total number of fingers shown determines how many people are counted.
- The person where the counting **stops** will clean the apartment.

⚠️ Dima does **not** want to be the one who cleans.

Your task is to count how many choices Dima has (from 1 to 5 fingers) such that **the counting does NOT stop on Dima**.

---

## Rules

1. Read the number of friends `n`.
2. Read the number of fingers shown by each friend.
3. Compute the sum of friends’ fingers.
4. Try all possible values for Dima’s fingers (1 to 5).
5. For each choice:
   - Add Dima’s fingers to the total.
   - Simulate the counting using modulo:
     - If  
       ```
       (total fingers) % (n + 1) == 1
       ```
       then the counting stops on Dima ❌ (bad choice).
     - Otherwise, Dima is safe ✅.
6. Count how many safe choices exist.

---

## Examples

### Example 1

**Input**
````

1
1

```

**Analysis**

- Number of friends: 1  
- Total people: 2 (Dima + 1 friend)
- Friend shows: 1 finger

Try Dima’s choices:

| Dima's Fingers | Total Fingers | Counting Result | Safe? |
|---------------|---------------|-----------------|-------|
| 1 | 2 | Stops on friend | ✅ |
| 2 | 3 | Stops on Dima | ❌ |
| 3 | 4 | Stops on friend | ✅ |
| 4 | 5 | Stops on Dima | ❌ |
| 5 | 6 | Stops on friend | ✅ |

Safe choices: **1, 3, 5**

**Output**
```

3

```

---

### Example 2

**Input**
```

1
2

```

**Analysis**

- Friend shows: 2 fingers
- Total people: 2

Try Dima’s choices:

Safe choices: **2, 4**

**Output**
```

2

```

---

### Example 3

**Input**
```

2
3 5

```

**Analysis**

- Friends show: 3 and 5 → sum = 8
- Total people: 3
- Safe choices count = **3**

**Output**
```

3

```

---

## Key Notes

- The counting always **starts from Dima**.
- If the counting ends on Dima, that choice must be excluded.
- Only values from **1 to 5** are valid for Dima.
- This problem focuses on:
  - Modulo arithmetic
  - Simulation of circular counting
  - Careful interpretation of the problem statement

This is a classic Codeforces problem that trains logical thinking and modular counting.

