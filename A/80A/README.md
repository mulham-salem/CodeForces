# Problem 80A – Panoramix’s Prediction

## Requirement

You are given two integers `n` and `m`.

Your task is to determine whether `m` is the **next prime number** after `n`.

**Goal:**  
- Print `"YES"` if `m` is the next prime number after `n`.
- Otherwise, print `"NO"`.

---

## Input

- Two integers `n` and `m`
  - `2 ≤ n < m ≤ 50`

---

## Output

- Print `"YES"` or `"NO"` (case-sensitive)

---

## Examples

### Example 1

**Input**
```

3 5

```

**Output**
```

YES

```

**Explanation**
```

Prime numbers after 3 are: 5, 7, 11, ...
The next prime after 3 is 5, so the answer is YES.

```

---

### Example 2

**Input**
```

7 11

```

**Output**
```

YES

```

**Explanation**
```

The next prime after 7 is 11.

```

---

### Example 3

**Input**
```

7 13

```

**Output**
```

NO

```

**Explanation**
```

The next prime after 7 is 11, not 13.

```

---

## Solution Idea

1. Find the **smallest prime number greater than `n`**.
2. Compare it with `m`.
3. If they are equal, print `"YES"`, otherwise print `"NO"`.

---

## Prime Check Method

To check if a number `x` is prime:
- Try dividing `x` by all integers from `2` to `√x`.
- If any division is exact, `x` is not prime.
- Otherwise, `x` is prime.

---

## Complexity

- **Time Complexity:** `O(√m)`
- **Space Complexity:** `O(1)`

---