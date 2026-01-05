# Problem 766A – Mahmoud and Longest Uncommon Subsequence

## Problem Summary
Mahmoud is given two strings.

Your task:

Find the length of the **Longest Uncommon Subsequence** between the two strings.

Definition:
An uncommon subsequence is a string that is a subsequence of one string
but is NOT a subsequence of the other string.

---

## Key Idea
There are only two possible cases:

Case 1:
If the two strings are exactly the same,
then every subsequence of one is also a subsequence of the other.
So the answer is -1.

Case 2:
If the two strings are different,
then the longer string itself is an uncommon subsequence.
So the answer is the length of the longer string.

---

## Example 1

Input
aba
cdc

Explanation
The strings are different.
The longer length is 3.

Output
3

---

## Example 2

Input
aaa
aaa

Explanation
The strings are identical.
No uncommon subsequence exists.

Output
-1

---

## Example 3

Input
abcd
abc

Explanation
The strings are different.
The longer string has length 4
and cannot be a subsequence of the shorter one.

Output
4

---

## Pseudocode
read string s
read string t

if s == t:
    print -1
else:
    print max(length(s), length(t))

---

## Final Notes
This problem has a simple logical observation.
No need for dynamic programming.
Time complexity is O(n).
Works for all valid strings.
