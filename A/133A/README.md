# Problem 133A – HQ9+

## Requirement

You are given a string `s` that represents a program written in the **HQ9+ programming language**.

This language produces output **if and only if** the program contains **at least one** of the following characters:

- `H`
- `Q`
- `9`

All other characters (including `+`) are irrelevant for this problem.

---

## Goal

Determine whether the given program will produce any output.

- Print `YES` if the string contains `H`, `Q`, or `9`
- Print `NO` otherwise

---

## Input

- A single string `s`  
  (`1 ≤ |s| ≤ 100`)

---

## Output

- `YES` if the program produces output
- `NO` if it does not

---

## Examples

### Example 1

**Input**
```

Hi!

```

**Output**
```

YES

```

**Explanation**
```

The string contains 'H', so the program produces output.

```

---

### Example 2

**Input**
```

Codeforces

```

**Output**
```

NO

```

**Explanation**
```

The string does not contain 'H', 'Q', or '9'.

```

---

### Example 3

**Input**
```

abc1239

```

**Output**
```

YES

```

**Explanation**
```

The string contains '9', so the program produces output.

```

---

## Solution Idea

1. Read the input string.
2. Iterate through each character.
3. If any character is `H`, `Q`, or `9`, print `YES`.
4. If the loop finishes without finding any of them, print `NO`.

---

## Complexity

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---
