# Problem 236A – Boy or Girl

## Problem Summary

A user enters a **username** consisting of lowercase English letters.

The system determines whether the user is a **boy** or a **girl** based on the number of **distinct characters** in the username.

---

## Rule

- If the number of **distinct characters** is **even** → the user is a **Girl**
- If the number of **distinct characters** is **odd** → the user is a **Boy**

---

## Goal

Given a username, determine whether to print:

- `"CHAT WITH HER!"` → Girl
- `"IGNORE HIM!"` → Boy

---

## Key Idea

1. Count how many **unique characters** appear in the username
2. Check whether this count is **even or odd**

---

## Example 1

### Input
```

wjmzbmr

```

### Analysis
Distinct characters:
```

w, j, m, z, b, r

```

- Count = 6
- 6 is even

### Output
```

CHAT WITH HER!

```

---

## Example 2

### Input
```

xiaodao

```

### Analysis
Distinct characters:
```

x, i, a, o, d

```

- Count = 5
- 5 is odd

### Output
```

IGNORE HIM!

```

---

## Complexity

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`  
  (maximum 26 lowercase English letters)

---

## Conclusion

The problem is solved by:
- Counting distinct letters in the username
- Checking the parity (even or odd) of that count

This simple logic directly determines the correct output.

---