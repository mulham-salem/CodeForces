# Problem 255A – Greg's Workout

## Problem

Greg has `n` exercises, and each exercise `i` must be repeated `a[i]` times.

The exercises are performed cyclically in this order:

1. `chest`
2. `biceps`
3. `back`
4. `chest`
5. `biceps`
6. `back`
7. ...

The goal is to determine which muscle gets the most total repetitions.

The answer is guaranteed to be unique.

---

## Input

- The first line contains an integer `n` — the number of exercises.
- The second line contains `n` integers `a[i]` — the number of repetitions for each exercise.

---

### Constraints

- `1 ≤ n ≤ 20`
- `1 ≤ a[i] ≤ 25`

---

## Output

Print the muscle that receives the most repetitions:

- `chest`
- `biceps`
- `back`

---

## Examples

### Example 1

**Input:**
```text
2
2 8
```

**Output:**
```
biceps
```

`chest = 2`

`biceps = 8`

`back = 0`


So, `biceps` gets the most repetitions.

---

### Example 2

**Input:**
```
3
5 1 10
```

### Output:
```
back
```

`chest = 5`

`biceps = 1`

`back = 10`


So, `back` gets the most repetitions.

---

### Example 3

**Input:**
```
7
3 3 2 7 9 6 8
```

**Output:**
```
chest
```

The repetitions are distributed as follows:

`chest = 3 + 7 + 8 = 18`

`biceps = 3 + 9 = 12`

`back = 2 + 6 = 8`


Therefore, `chest` gets the most repetitions.

---

## Approach

1. Initialize three counters for `chest`, `biceps`, and `back`.


2. Iterate through all exercises.


3. Determine the muscle using the exercise position modulo `3`.


4. Add the repetitions to the corresponding counter.


5. Compare the three counters and print the muscle with the largest value.

---

## Pseudocode
```
Read n

Initialize chest, biceps, and back to 0

For each exercise:
    Read the number of repetitions

    If its position corresponds to chest:
        Add repetitions to chest
    Else if its position corresponds to biceps:
        Add repetitions to biceps
    Else:
        Add repetitions to back

Find the largest total

Print the corresponding muscle name
```

---

## Complexity

**Time:** `O(n)`

**Space:** `O(1)`

---