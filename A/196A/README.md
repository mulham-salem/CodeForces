# Problem 196A – Lexicographically Maximum Subsequence

## Problem Summary

Given a lowercase string `s`, find the **lexicographically maximum subsequence**.

A subsequence is formed by deleting zero or more characters while keeping the remaining characters in their original order.

The goal is to construct the largest possible string in lexicographical (dictionary) order.

---

## Examples

### Example 1

**Input**

```text
ababba
```

**Output**

```text
bbba
```

**Explanation**

The largest character is `'b'`, so the answer starts with every valid `'b'`. After no more `'b'` characters remain, the last `'a'` is added.

---

### Example 2

**Input**

```text
abbcbccacbbcbaaba
```

**Output**

```text
cccccbba
```

**Explanation**

All possible `'c'` characters are selected first because they are the largest. Then the remaining largest characters are `'b'`, followed by the final `'a'`.

---

## Algorithm

1. Traverse the string from right to left.
2. For every position, store the largest character that appears from that position to the end.
3. Traverse the string from left to right.
4. If the current character is equal to the stored maximum for its suffix, include it in the answer.
5. Print the constructed subsequence.

---

## Pseudocode

```text
read s
n = length(s)

mx[n - 1] = s[n - 1]

for i = n - 2 down to 0
    mx[i] = max(s[i], mx[i + 1])

answer = ""

for i = 0 to n - 1
    if s[i] == mx[i]
        append s[i] to answer

print answer
```

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

---