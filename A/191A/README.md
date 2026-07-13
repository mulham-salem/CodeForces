# Problem 191A – Dynasty Puzzles

## Idea

Each king's abbreviated name can be represented by:

- **First letter** (starting character)
- **Last letter** (ending character)
- **Length** of the name

A valid dynasty must satisfy:

1. The last letter of each king matches the first letter of the next king.
2. The first letter of the first king is the same as the last letter of the last king.

The dynasty's name is simply the concatenation of all selected names, so the goal is to maximize the **total length**.

Since there are only **26 lowercase letters**, we use Dynamic Programming.

---

## DP State

Let:

```text
dp[start][end]
```

be the **maximum total length** of a valid chain that:

- starts with letter `start`
- ends with letter `end`

Initially, every state is unreachable.

---

## DP Transition

For every name:

- `first` = first letter
- `last` = last letter
- `len` = length of the name

There are two possibilities:

### 1. Start a new chain

```text
dp[first][last] = max(dp[first][last], len)
```

### 2. Extend an existing chain

If a chain already ends with `first`, append the current name.

```text
start ----> first
             +
        first ----> last
             =
start -----------------> last
```

Update:

```text
dp[start][last] =
max(dp[start][last], dp[start][first] + len)
```

---

## Example

Input:

```text
abc
bc
ca
```

After reading `"abc"`:

```text
a -> c = 3
```

After reading `"bc"`:

```text
b -> c = 2
```

After reading `"ca"`:

```text
a -> a = 5
b -> a = 4
```

The best completed dynasty is:

```text
a -> a
```

Answer:

```text
5
```

---

## Pseudocode

```text
Initialize dp[26][26] as unreachable

For each name:

    first = first letter
    last = last letter
    len = length of the name

    Copy dp into old

    // Start a new chain
    dp[first][last] =
        max(dp[first][last], len)

    // Extend existing chains
    For every starting letter start:

        If old[start][first] is reachable:

            dp[start][last] =
                max(dp[start][last],
                    old[start][first] + len)

Answer = 0

For every letter:

    Answer = max(Answer, dp[letter][letter])

Print Answer
```

---

## Complexity

- **Time Complexity:** `O(26 × n)`
- **Space Complexity:** `O(26²)`

---