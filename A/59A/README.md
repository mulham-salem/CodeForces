# Problem 59A – Word

## Problem Description
You are given a single word consisting of uppercase and lowercase English letters.

Your task is to convert the entire word to:
- **lowercase**, if the number of lowercase letters is **greater than or equal to** the number of uppercase letters.
- **uppercase**, otherwise.

---

## Rules
- Count how many characters are lowercase.
- Count how many characters are uppercase.
- Compare the two counts:
  - lowercase ≥ uppercase → convert the whole word to lowercase
  - lowercase < uppercase → convert the whole word to uppercase

---

## Examples

### Example 1
**Input**
```

HoUse

```

**Analysis**
- Uppercase letters: `H`, `U` → 2
- Lowercase letters: `o`, `s`, `e` → 3

Lowercase ≥ Uppercase → convert to lowercase.

**Output**
```

house

```

---

### Example 2
**Input**
```

ViP

```

**Analysis**
- Uppercase letters: `V`, `P` → 2
- Lowercase letters: `i` → 1

Uppercase > Lowercase → convert to uppercase.

**Output**
```

VIP

```

---

## Key Notes
- The input contains only letters (no digits or symbols).
- The output must be a single word.
- This problem focuses on string traversal and character case handling.

This is a simple string manipulation problem commonly used to practice conditionals and character functions.
