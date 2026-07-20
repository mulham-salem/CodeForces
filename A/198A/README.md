# Problem 198A – About Bacteria

## 📝 Problem Summary

There are two experiments with bacteria growth.

In the first experiment, the tube starts with **1 bacterium**.

Every second, the number of bacteria changes using the rule:

$$
x \rightarrow k \times x + b
$$

After exactly `n` seconds, the number of bacteria becomes `z`.

In the second experiment, the tube starts with `t` bacteria and follows the same rule.

The goal is to find the **minimum number of seconds** needed for the second experiment to reach at least `z` bacteria.

---

## 📥 Input

The input contains four integers:

```
k b n t
```

Where:

- `k` → multiplication factor.
- `b` → extra bacteria added every second.
- `n` → time used in the first experiment.
- `t` → initial bacteria count in the second experiment.

---

## 📤 Output

Print one integer:

- The minimum number of seconds needed for the second experiment to have at least `z` bacteria.

---

## 💡 Examples

### Example 1

**Input**
```text
3 1 3 5
```

First experiment:

```
1 → 4 → 13 → 40
```

So:

```
z = 40
```

Second experiment:

```
5 → 16 → 49
```

After 2 seconds:

```
49 ≥ 40
```

**Output**
```text
2
```

---

### Example 2

**Input**
```text
1 4 4 7
```

First experiment:

```
1 → 5 → 9 → 13 → 17
```

So:

```
z = 17
```

Second experiment:

```
7 → 11 → 15 → 19
```

After 3 seconds:

```
19 ≥ 17
```

**Output**
```text
3
```

---

### Example 3

**Input**
```text
2 2 4 100
```

First experiment:

```
1 → 4 → 10 → 22 → 46
```

So:

```
z = 46
```

The second experiment starts with:

```
100 ≥ 46
```

Therefore, no time is needed.

**Output**
```text
0
```

---

## 🚀 Solution Idea

The value `z` can become extremely large, so we should not calculate it directly.

Instead, we simulate the first experiment until its value becomes greater than `t`.

Because the growth function:

$$
f(x)=kx+b
$$

is always increasing, once the first experiment exceeds `t`, the second experiment is already ahead.

Using this observation, we can calculate the required remaining time without storing the huge value of `z`.

---

## 📌 Pseudocode

```
Read k, b, n, t

current = 1
seconds = 0

while current <= t and seconds < n:
    current = k * current + b
    seconds++

if current > t:
    answer = n - seconds + 1
else:
    answer = 0

print answer
```

---