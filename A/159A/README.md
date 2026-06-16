# Problem 159A – Friends or Not

## Overview

You are given a chronological log of messages exchanged between users and an integer `d`.

A message from user **B** is considered a reply to a previous message from user **A** if:

- `A` sent a message to `B` at time `t₁`
- `B` sent a message to `A` at time `t₂`
- `0 < t₂ - t₁ ≤ d`

Two users become friends if at least one valid reply exists between them.

Your task is to find all friendship pairs.

---

## Key Idea

For every message:

```text
A → B at time t
```

search for a later message:

```text
B → A
```

such that:

```text
0 < time_difference ≤ d
```

If such a pair of messages exists, the two users are friends.

Since friendship is mutual, the pair `{A, B}` should be stored only once regardless of message direction.

---

## Example 1

### Input

```text
4 1
vasya petya 1
petya vasya 2
anya ivan 2
ivan anya 4
```

### Explanation

Messages:

```text
vasya → petya (1)
petya → vasya (2)
```

The difference is:

```text
2 - 1 = 1
```

Since:

```text
0 < 1 ≤ 1
```

they are friends.

For:

```text
anya → ivan (2)
ivan → anya (4)
```

the difference is:

```text
4 - 2 = 2
```

which is greater than `d`, so they are not friends.

### Output

```text
1
petya vasya
```

---

## Example 2

### Input

```text
1 1000
a b 0
```

### Explanation

There is only one message and no reply in the opposite direction.

Therefore no friendship can be formed.

### Output

```text
0
```

---

## Pseudocode

```text
read n, d

store all messages

friends = empty set

for each message i
    for each later message j

        diff = time[j] - time[i]

        if diff > d
            break

        if sender[i] == receiver[j]
           and receiver[i] == sender[j]
           and diff > 0

            store the pair in sorted order
            inside the set

print number of pairs

print all pairs
```

---

## Complexity Analysis

- **Time Complexity:** O(n²)
- **Space Complexity:** O(k)

Where:

- `n` = number of messages
- `k` = number of friendship pairs

---