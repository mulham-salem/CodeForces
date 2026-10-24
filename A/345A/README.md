# Problem 345A – Expecting Trouble

## Problem Summary

You have a string `s` representing your memories of Fridays the 13th:

- `'0'` → a normal day
- `'1'` → a bad day
- `'?'` → unknown day

Each `'?'` is an independent random variable: it is `1` with probability `p` and `0` with probability `1 - p`.

You need to compute the **expected value of the average badness** across all days.

---

## Key Insight

By **linearity of expectation**, the expected value of the sum equals the sum of expected values — and since we divide by a constant length, the expectation of the average equals the average of expectations:

$$E\left[\frac{1}{n}\sum_{i=1}^{n} X_i\right] = \frac{1}{n}\sum_{i=1}^{n} E[X_i]$$

For each day:

- `'1'` → contributes `1`
- `'0'` → contributes `0`
- `'?'` → contributes `p`

So the answer is simply:

$$\text{answer} = \frac{\text{count of '1'} + \text{count of '?'} \times p}{n}$$

---

## Examples

**Example 1:**

```

?111?1??1
1.0

```

- `ones = 5`, `questions = 4`, `n = 9`
- Expected = (5 + 4 × 1.0) / 9 = 9 / 9 = **1.00000**

---

**Example 2:**

```

01?10??10000
0.5

```

- `s = 0 1 ? 1 0 ? ? 1 0 0 0 0` → length 12
- `'1'` at indices 1, 3, 7 → **3 ones**
- `'?'` at indices 2, 5, 6 → **3 questions**
- Expected = (3 + 3 × 0.5) / 12 = 4.5 / 12 = **0.37500** ✅

---

## Pseudocode

```

read string s
read double p
ones = 0
questions = 0

for each character c in s:
	if c == '1': ones = ones + 1
	else if c == '?': questions = questions + 1

expected = ones + questions * p
answer = expected / length(s)
print answer with 5 decimal places (fixed format)

```

---

## Complexity

- **Time:** O(n) — single pass over the string
- **Space:** O(1) — only counters used
- **Constraints:** n ≤ 50, so trivially fast
