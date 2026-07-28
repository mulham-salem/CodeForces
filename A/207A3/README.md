# Problem 207A3 – Beaver's Calculator 1.0

## Idea

The problems of each scientist **must remain in their original order**.

Whenever the required resources decrease between two consecutive problems, a new **group** begins.

Example:

```text
Sequence:
1 4 7 2 5 8 3

Groups:
Group 0: 1 4 7
Group 1: 2 5 8
Group 2: 3
```

Each decrease creates one additional group.

---

## Key Observation

Each transition between two consecutive groups is an **unavoidable bad pair**, because the first value of the new group is always smaller than the last value of the previous one.

For a scientist:

- `group = 0` → no decreases.
- `group = 1` → one decrease.
- `group = 2` → two decreases.
- ...

Thus:

```text
group = number of decreases = number of unavoidable bad pairs
```

When combining all scientists optimally, these unavoidable bad pairs can overlap.

Therefore, the minimum possible number of bad pairs is simply:

```text
maximum group value among all scientists
```

---

## Algorithm

1. Read all scientists.
2. Generate each sequence using the given recurrence.
3. Count how many times the sequence decreases.
   - Start with `group = 0`.
   - If `next < current`, increment `group`.
4. Keep the maximum `group` over all scientists.
5. Output this maximum.
6. If the total number of problems is at most `200000`, generate all problems, sort them by `(group_id, value, scientist_id)`, and print the optimal order.

---

## Pseudocode

```text
read n

max_group = 0

for each scientist:
    generate sequence

    group = 0

    for each next value:
        if next < current:
            group++

        current = next

    max_group = max(max_group, group)

print max_group
```

---

## Complexity

### If total problems ≤ 200000

- **Time:** `O(T log T)`
- **Memory:** `O(T)`

### If total problems > 200000

- **Time:** `O(T)`
- **Memory:** `O(n)`

Where `T` is the total number of problems.

---