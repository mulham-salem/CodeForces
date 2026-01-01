# Problem 443A – Anton and Letters

## Requirement
You are given:

- A string **s** representing a set of lowercase English letters,
  written in the form `{a, b, c, ...}`.

Your task is to determine how many **distinct letters** are present in the set.

---

## Input
- One line containing the string **s**

---

## Output
- One integer — the number of distinct lowercase letters

---

## Examples

### Example 1
**Input**
```

{a, b, c}

```

**Output**
```

3

```

**Explanation**

Distinct letters: `a`, `b`, `c`

---

### Example 2
**Input**
```

{a, a, b, c, c}

```

**Output**
```

3

```

**Explanation**

Duplicates are ignored.
Distinct letters: `a`, `b`, `c`

---

### Example 3
**Input**
```

{}

```

**Output**
```

0

```

**Explanation**

No letters inside the set.

---

## Solution Idea
1. Traverse the string.
2. For each character:
   - If it is a lowercase letter (`'a'` to `'z'`), add it to a set.
3. The size of the set is the answer.

---

## Important Notes
- Braces `{}`, commas, and spaces should be ignored.
- Only lowercase English letters count.
- Order and repetition do not matter.

---

## Complexity
- **Time Complexity:** O(|s|)
- **Space Complexity:** O(1)  
  (At most 26 different letters)

---

## Key Insight
Using a set automatically removes duplicates,
so counting unique letters becomes straightforward.

