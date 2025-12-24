# Problem 218A – Little Elephant and Bits

## Requirement

You are given a string `s` consisting only of characters `'0'` and `'1'`.

**Goal:**  
Remove **exactly one character** from the string so that the resulting string is as **small as possible lexicographically**.

---

## Input

- One string `s`
  - Contains only `'0'` and `'1'`
  - Length of the string is at least 1

---

## Output

- Print the resulting string after removing exactly one character

---

## Examples

### Example 1

**Input**
```

101

```

**Output**
```

01

```

**Explanation**
```

Removing the first character '1' gives "01",
which is the smallest possible result.

```

---

### Example 2

**Input**
```

111

```

**Output**
```

11

```

**Explanation**
```

There is no '0' in the string.
So we remove the last character.

```

---

### Example 3

**Input**
```

10010

```

**Output**
```

0010

```

**Explanation**
```

Removing the first '1' before a '0' gives
the smallest lexicographical result.

```

---

## Solution Idea

1. To minimize the string lexicographically, we want `'0'` to appear as early as possible.
2. If the string contains at least one `'0'`:
   - Remove the **first occurrence of `'0'`**.
3. If the string does **not** contain `'0'`:
   - Remove the **last character**.
4. Print the resulting string.

---

## Key Notes

- Exactly **one character must be removed**.
- The order of remaining characters must be preserved.

---

## Complexity

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

---