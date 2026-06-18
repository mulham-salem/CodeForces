# Problem 162A – Pentagonal Numbers

## Description

A pentagonal number is defined by the formula:

```text
P(n) = (3 * n^2 - n) / 2
```

Given an integer `n`, calculate the `n`-th pentagonal number.

---

## Input

| Variable | Description |
|----------|-------------|
| `n` | The index of the pentagonal number (`1 ≤ n ≤ 100`) |

---

## Output

Print the `n`-th pentagonal number.

---

## Examples

| Input | Output |
|-------|--------|
| `2` | `5` |
| `5` | `35` |

### Explanation

For `n = 2`:

```text
P(2) = (3 * 2^2 - 2) / 2
     = (12 - 2) / 2
     = 5
```

For `n = 5`:

```text
P(5) = (3 * 5^2 - 5) / 2
     = (75 - 5) / 2
     = 35
```

---

## Approach

The formula directly gives the answer.

1. Read `n`.
2. Compute `(3 * n * n - n) / 2`.
3. Print the result.

---

## Pseudocode

```text
read n

answer = (3 * n * n - n) / 2

print answer
```

---

## Complexity Analysis

| Complexity | Value |
|------------|-------|
| Time | O(1) |
| Space | O(1) |

---