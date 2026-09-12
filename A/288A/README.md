# Problem 288A – Polo the Penguin and Strings

## Problem Summary

Given two integers `n` and `k`, construct a string that satisfies:

1. The string has length `n` and consists of lowercase English letters.
2. Exactly `k` **distinct** letters are used.
3. No two neighboring characters are equal.
4. Among all valid strings, the result must be the **lexicographically smallest**.

If no such string exists, output `-1`.

---

## Approach

### Impossible Cases

| Condition | Reason |
|-----------|--------|
| `k > n` | Can't have more distinct letters than string length. |
| `k == 1 && n > 1` | With only one letter, adjacent characters must repeat. |
| `k == 1 && n == 1` | Valid — the answer is `"a"`. |

### Construction Strategy

To get the **lexicographically smallest** string:

1. Use `'a'` and `'b'` **alternating** for as long as possible — because they are the smallest letters.
2. Introduce the remaining `k - 2` letters (`'c'`, `'d'`, ...) **at the end**, each exactly once — because placing larger letters later keeps the string smaller lexicographically.
3. The alternating part has length `n - k + 2`.
4. The tail part has length `k - 2`.

### Why This Works

- The `'abab...'` pattern guarantees no two adjacent equal characters.
- The last alternating character is either `'a'` or `'b'`, which is **never equal** to the first tail character `'c'`.
- Tail letters are all distinct, so no adjacent duplicates there.
- Pushing larger letters to the end ensures minimal lexicographic order.

---

## Pseudocode

```

read n, k

if k > n:
print -1
return

if k == 1:
if n == 1:
print "a"
else:
print -1
return

altLength = n - k + 2
result = ""

for i from 0 to altLength - 1:
if i is even:
result += 'a'
else:
result += 'b'

for i from 0 to k - 3:
result += char('c' + i)

print result

```

---

## Examples

### Example 1
```

Input:  n = 7, k = 4
Output: ababacd

```
**Walkthrough:**
- `altLength = 7 - 4 + 2 = 5` → `"ababa"`
- Tail: `k - 2 = 2` letters → `"cd"`
- Result: `"ababa" + "cd" = "ababacd"`

### Example 2
```

Input:  n = 4, k = 7
Output: -1

```
**Reason:** `k > n` → impossible.

### Example 3
```

Input:  n = 5, k = 2
Output: ababa

```
**Walkthrough:**
- `altLength = 5 - 2 + 2 = 5` → `"ababa"`
- Tail: `k - 2 = 0` letters → nothing added.

### Example 4
```

Input:  n = 1, k = 1
Output: a

```

### Example 5
```

Input:  n = 3, k = 3
Output: abc

```
**Walkthrough:**
- `altLength = 3 - 3 + 2 = 2` → `"ab"`
- Tail: `k - 2 = 1` letter → `"c"`
- Result: `"abc"`

---

## Complexity

| Metric | Value |
|--------|-------|
| Time   | `O(n)` |
| Space  | `O(n)` |

---

## Key Insight

> Keep the smallest letters (`a`, `b`) at the beginning and delay all larger letters (`c`, `d`, ...) to the end — this guarantees the lexicographically smallest valid string.

---