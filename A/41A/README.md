# Problem 41A – Translation

## Problem Description
You are given two strings:

- The first string `s`
- The second string `t`

Your task is to check whether the string `t` is the **reverse** of the string `s`.

---

## What is Required?
1. Read string `s`.
2. Read string `t`.
3. Reverse string `s`.
4. Compare the reversed `s` with `t`.
5. Print:
   - `YES` if they are equal
   - `NO` otherwise

---

## Examples

### Example 1
**Input**
```

code
edoc

```

**Explanation**
- Reverse of `"code"` is `"edoc"`
- It matches `t`

**Output**
```

YES

```

---

### Example 2
**Input**
```

a
a

```

**Explanation**
- Reverse of `"a"` is `"a"`
- It matches `t`

**Output**
```

YES

```

---

### Example 3
**Input**
```

abc
abc

```

**Explanation**
- Reverse of `"abc"` is `"cba"`
- It does **not** match `t`

**Output**
```

NO

```

---

## Key Idea
> Just reverse the first string and compare it with the second one.

---

## Summary
- Reverse the first string
- Compare with the second string
- If equal → `YES`
- Otherwise → `NO`
