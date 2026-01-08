# Problem 320A – Magic Numbers

## Problem Summary
A number is called a **magic number** if it can be formed by concatenating
the strings:

- `1`
- `14`
- `144`

Each of these strings can be used any number of times.

You are given a number `n`. Determine whether it is a magic number or not.

---

## Rules
A number is **magic** if:
- It is composed **only** of the substrings `1`, `14`, and `144`
- The entire number can be split into these substrings without leftovers

Otherwise, it is **not magic**.

---

## Key Idea
Scan the number from **left to right** and always try to match:
1. `"144"` first
2. then `"14"`
3. then `"1"`

If none of these match at any position, the number is **not magic**.

The longest match is checked first to avoid breaking valid patterns.

---

## Examples

### Example 1
**Input**
```

114114

```

**Explanation**
```

1 | 14 | 1 | 14

```

**Output**
```

YES

```

---

### Example 2
**Input**
```

1111

```

**Explanation**
```

1 | 1 | 1 | 1

```

**Output**
```

YES

```

---

### Example 3
**Input**
```

441231

```

**Explanation**
- Starts with `4`
- Contains invalid digits

**Output**
```

NO

```

---

## Notes
- A single `4` is not allowed
- Sequences like `444` or `4444` are invalid
- The order of checking (`144` → `14` → `1`) is important
