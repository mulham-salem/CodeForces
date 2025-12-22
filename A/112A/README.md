# Problem 112A – Petya and Strings

## Requirement

You are given two strings of equal length.

Your task is to compare the two strings **lexicographically**,  
**ignoring the case of the letters** (uppercase and lowercase are considered the same).

**Goal:**  
- Print `-1` if the first string is lexicographically smaller.
- Print `1` if the first string is lexicographically larger.
- Print `0` if both strings are equal.

---

## Input

- The first line contains string `a`.
- The second line contains string `b`.

Both strings:
- Have the same length.
- Contain only English letters.

---

## Output

- Print a single integer: `-1`, `0`, or `1`.

---

## Examples

### Example 1

**Input**
```

aaaa
aaaA

```

**Output**
```

0

```

**Explanation**
```

After ignoring case:
"aaaa" == "aaaa"
So the strings are equal.

```

---

### Example 2

**Input**
```

abs
Abz

```

**Output**
```

-1

```

**Explanation**
```

After ignoring case:
"abs" < "abz"
So the first string is lexicographically smaller.

```

---

### Example 3

**Input**
```

abc
Xyz

```

**Output**
```

-1

```

**Explanation**
```

After ignoring case:
"abc" < "xyz"

```

---

## Solution Idea

1. Convert both strings to the **same case** (lowercase or uppercase).
2. Compare them character by character.
3. Determine the result based on lexicographical order.

---

## Lexicographical Comparison Rules

- Compare characters from left to right.
- At the first differing position:
  - Smaller character → smaller string.
- If all characters are equal → strings are equal.

---

## Complexity

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---