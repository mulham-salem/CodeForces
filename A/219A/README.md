# Problem 219A – k-String

## Problem Summary

You are given:
- An integer **k**
- A string **s**

Your task is to determine whether it is possible to rearrange the characters of `s`
so that the resulting string consists of **exactly k identical substrings**.

If it is possible, output the resulting string.  
Otherwise, output `-1`.

---

## Key Observation

For a string to be split into `k` identical parts:

> **The frequency of every character must be divisible by `k`.**

This is necessary because each of the `k` identical substrings must contain
the same number of each character.

---

## Explanation

1. Count how many times each character appears in the string.
2. For each character:
   - If its count is **not divisible by `k`**, the task is impossible.
3. If all characters satisfy the condition:
   - Build one base substring using `count / k` occurrences of each character.
   - Repeat this substring `k` times to form the final result.

The order of characters is not important, as long as all `k` parts are identical.

---

## Examples

### Example 1
```

Input:
k = 2
s = "aazz"

```

Character frequencies:
- a → 2
- z → 2

All frequencies are divisible by `k`.

Base substring:
```

"az"

```

Final output:
```

"azaz"

```

---

### Example 2
```

Input:
k = 3
s = "abcabcabz"

```

Character frequencies:
- a → 3
- b → 3
- c → 2
- z → 1

Some frequencies are not divisible by `k`.

Output:
```

-1

```

---

## Pseudo Code

```

read k
read string s

create empty map freq

for each character c in s:
freq[c]++

for each character c in freq:
if freq[c] % k != 0:
print -1
exit

create empty string base

for each character c in freq:
append (freq[c] / k) copies of c to base

print base repeated k times

```

---

## Notes

- Only one traversal of the string is needed.
- Any valid rearrangement is accepted.
- Time complexity is O(n), where n is the length of the string.

---