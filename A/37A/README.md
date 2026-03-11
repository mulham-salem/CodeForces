# Problem 37A – Towers

## Problem Summary

From the problem **“Towers”** on <https://codeforces.com>, we are given **N wooden bars**, each with a known length.

Bars can be stacked on top of each other **only if their lengths are equal**.

The goal is to use **all bars** to build towers such that:

- Each tower contains bars of **the same length**.
- We determine:
  1. **The height of the tallest tower**.
  2. **The total number of towers built**.

---

## Key Idea

If bars can only stack with bars of the **same length**, then:

- Every **unique length** forms its own tower.
- The **number of times a length appears** equals the **height of that tower**.

Therefore:

- **Tallest tower** = maximum frequency of any length.
- **Total towers** = number of **distinct lengths**.

---

## Example 1

### Input
```

3
1 2 3

```

### Explanation

Each bar has a different length.

Possible towers:

```

1
2
3

```

- Each tower has height **1**
- Number of towers = **3**

### Output
```

1 3

```

---

## Example 2

### Input
```

4
6 5 6 7

```

### Explanation

Frequency of lengths:

```

5 → 1
6 → 2
7 → 1

```

Constructed towers:

```
6
6
```

```
5
```

```
7
```

- Tallest tower height = **2**
- Total towers = **3**

### Output
```

2 3

```

---

## Approach

1. Read the number of bars **N**.
2. Read all bar lengths.
3. Count how many times each length appears.
4. Track:
   - The **maximum frequency**.
   - The **number of distinct lengths**.

---

## Pseudocode

```
read N
read array bars

create frequency structure

for each bar in bars
increase frequency of bar

maxHeight = 0
towerCount = 0

for each length in frequency
if frequency[length] > 0
towerCount++
maxHeight = max(maxHeight, frequency[length])

print maxHeight and towerCount

```

---

## Complexity

- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

Since we only count occurrences of bar lengths, the algorithm is efficient even for the maximum constraint (**N ≤ 1000**).
