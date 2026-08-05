# Problem 226A – Flying Saucer Segments

## 📝 Problem Description

A spaceship consists of three connected segments:

1 <--> 2 <--> 3

There are `n` aliens, each with a unique rank from `1` to `n`.

Initially, all aliens are in the **3rd segment**, and they need to move to the **1st segment**.

An alien can move between two adjacent segments only if he is senior in rank than all aliens currently in both segments.

Each move takes exactly one minute, and only one alien can move at a time.

The goal is to find the minimum number of moves required to move all aliens from segment `3` to segment `1`, and output the answer modulo `m`.

---

## 💡 Idea

Let:

$$
dp[i]
$$

be the minimum number of moves needed to move `i` aliens from segment `3` to segment `1`.

By analyzing the movement process, we get:

$$
dp[1] = 2
$$

and:

$$
dp[i] = 3 \times dp[i-1] + 2
$$

Since:

$$
n \leq 10^9
$$

we cannot calculate this recurrence iteratively.

---

## 🔍 Mathematical Observation

Starting from:

$$
dp[i] = 3 \times dp[i-1] + 2
$$

Add `1` to both sides:

$$
dp[i] + 1 = 3 \times dp[i-1] + 3
$$

Take `3` as a common factor:

$$
dp[i] + 1 = 3 \times (dp[i-1] + 1)
$$

This means that the value:

$$
dp[i] + 1
$$

is multiplied by `3` every step.

For the first alien:

$$
dp[1] + 1 = 3
$$

Therefore:

$$
dp[n] + 1 = 3^n
$$

Finally:

$$
\boxed{dp[n] = 3^n - 1}
$$

So the problem becomes finding:

$$
(3^n - 1) \bmod m
$$

---

## ⚡ Binary Exponentiation

The value of `n` can be very large, so calculating:

$$
3^n
$$

directly is impossible.

We use **Binary Exponentiation** to calculate:

$$
3^n \bmod m
$$

in:

$$
O(\log n)
$$

instead of:

$$
O(n)
$$

---

## 🧠 Pseudocode
```
function modPow(base, exponent, mod):

result = 1

while exponent > 0:

    if exponent is odd:
        result = (result * base) % mod

    base = (base * base) % mod

    exponent = exponent / 2

return result

read n, m

power = modPow(3, n, m)

answer = (power - 1 + m) % m

print answer
```

---

## 📌 Examples

### Example 1

**Input**
```
1 10
```
For one alien, the movement is:

3 → 2 → 1

Number of moves:

$$
2
$$

Modulo:

$$
2 \bmod 10 = 2
$$

**Output**
```
2
```
---

### Example 2

**Input**
```
3 8
```
Number of moves:

$$
3^3 - 1 = 27 - 1 = 26
$$

After taking modulo:

$$
26 \bmod 8 = 2
$$

**Output**
```
2
```
---

## ⏱ Complexity Analysis

**Time Complexity:** `O(log n)`

**Space Complexity:** `O(1)`

---