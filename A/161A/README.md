# Problem 161A – Dress'em in Vests!

## Overview

You are given:

- `n` soldiers, where the `i-th` soldier wants a vest of size `a[i]`.
- `m` available vests, where the `j-th` vest has size `b[j]`.

A soldier is willing to wear any vest whose size lies within:

`[a[i] - x, a[i] + y]`

Each vest can be assigned to **at most one soldier**, and each soldier can receive **at most one vest**.

Your goal is to maximize the number of equipped soldiers and output the matching pairs.

---

## Example

### Input

```text
5 3 0 0
1 2 3 3 4
1 3 5
```

### Output

```text
2
1 1
3 2
```

### Explanation

- Soldier 1 can wear Vest 1.
- Soldier 3 can wear Vest 2.
- Vest 3 cannot be assigned.

So the maximum number of equipped soldiers is `2`.

---

## Key Idea

Since both soldiers' desired sizes and vest sizes are already sorted:

- Keep one pointer on soldiers.
- Keep one pointer on vests.
- Try to match the current soldier with the current vest.

For a soldier with desired size `a[i]`:

- If the vest is too small, move to the next vest.
- If the vest is too large, move to the next soldier.
- Otherwise, assign the vest and move both pointers.

This greedy strategy always produces the maximum number of valid assignments.

---

## Pseudocode

```text
i = 0
j = 0

while i < n and j < m

    if b[j] < a[i] - x
        j++

    else if b[j] > a[i] + y
        i++

    else
        add pair (i + 1, j + 1)
        i++
        j++

output all collected pairs
```

---

## Complexity Analysis

| Complexity | Value |
|------------|--------|
| Time | O(n + m) |
| Space | O(k) |

Where `k` is the number of successful assignments.

---