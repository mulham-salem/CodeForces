# Problem 223A – Bracket Sequence

## Problem Statement

You are given a string containing only four types of brackets:

- `(`
- `)`
- `[`
- `]`

A **correct bracket sequence** is a sequence where:

- Every opening bracket has a matching closing bracket.
- Brackets are closed in the correct order.
- Each opening bracket matches the same type of closing bracket.

Examples of correct bracket sequences:

```
()
[]
([])
()[]
```

Examples of incorrect bracket sequences:

```
)(
[)
([]
```

The given string is not necessarily correct.

Your task is to find a **continuous substring** of the string that is a correct bracket sequence and contains the maximum possible number of opening square brackets `[`.

If there are multiple answers with the same number of `[` characters, output any one of them.

---

## Input

The only line contains a string `s`.

Constraints:

```
1 ≤ |s| ≤ 100000
```

The string contains only:

```
( ) [ ]
```

---

## Output

Print two lines:

- The first line contains the maximum number of `[` characters inside the chosen substring.
- The second line contains the chosen correct bracket sequence.

If no correct bracket sequence exists, print:

```
0
```

and an empty second line.

---

## Examples

### Example 1

#### Input
```
([])
```

#### Output
```
1
([])
```

#### Explanation

The whole string is a valid bracket sequence and contains one opening square bracket.

---

### Example 2

#### Input
```
(((
```

#### Output
```
0

```

#### Explanation

There is no valid bracket sequence, so the answer is an empty string.

---

# Approach

The solution combines:

- Stack
- Dynamic Programming
- Prefix Sum

to find valid bracket substrings efficiently.

---

# 1. Stack

The stack stores the **indices of opening brackets**.

When we encounter:

```
(
```

or

```
[
```

we push its index into the stack.

When we encounter a closing bracket:

- We check the latest opening bracket.
- If the types match, we remove it using `pop()`.
- Otherwise, the current sequence cannot form a valid bracket sequence.

The stack helps us find matching pairs and their positions.

---

# 2. Dynamic Programming

We define:

```
dp[i]
```

as:

> The length of the longest correct bracket substring that ends at index `i`.

When a matching pair is found:

```
s[j] ... s[i]
```

where:

- `j` is the position of the matching opening bracket.
- `i` is the current closing bracket.

The current valid length is:

```
i - j + 1
```

There may also be a valid substring directly before this pair.

Therefore:

```
dp[i] = i - j + 1
```

and if there is a previous valid part:

```
dp[i] += dp[j - 1]
```

The condition:

```cpp
j > 0
```

is needed because we cannot access:

```
dp[-1]
```

---

# 3. Prefix Sum

We need to count how many `[` characters exist inside each valid substring.

Instead of counting every time, we build a prefix array:

```
pre[i]
```

where:

> `pre[i]` is the number of `[` characters before index `i`.

Construction:

```cpp
pre[i + 1] = pre[i] + (s[i] == '[');
```

For any range:

```
L ... R
```

the number of `[` characters is:

```
pre[R + 1] - pre[L]
```

This allows counting in `O(1)`.

---

# Finding the Best Answer

After calculating:

```
dp[i]
```

we know that the valid substring ends at `i`.

Its starting index is:

```
L = i - dp[i] + 1
```

Then we calculate:

```
count = pre[i + 1] - pre[L]
```

If this count is greater than the current best:

```
bestCount
```

we store:

```
bestL = L
bestR = i
```

Finally, the answer is:

```cpp
s.substr(bestL, bestR - bestL + 1)
```

---

# Complexity Analysis

Let:

```
n = |s|
```

### Time Complexity

```
O(n)
```

Each character is processed once.

### Memory Complexity

```
O(n)
```

For:

- Stack
- DP array
- Prefix sum array

---

# Pseudocode

```
read s

build prefix sum of '['

initialize dp array
initialize stack

bestCount = 0
bestL = -1
bestR = -1

for i from 0 to n-1:

    if s[i] is an opening bracket:
        push i into stack

    else:

        if stack is not empty:

            j = stack top

            if s[j] matches s[i]:

                pop stack

                dp[i] = i - j + 1

                if j > 0:
                    dp[i] += dp[j-1]

                L = i - dp[i] + 1

                count '[' inside L...i

                if count is better:
                    update best answer

print bestCount

if an answer exists:
    print the substring
```

---