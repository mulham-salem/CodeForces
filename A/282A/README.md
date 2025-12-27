# Problem 282A – Bit++

## 🧩 Problem Summary
You are given an integer variable `X` with an initial value of `0`.

Then, you are given `n` statements. Each statement either increments or decrements the value of `X` by `1`.

Your task is to determine the **final value of `X`** after all statements are executed.

---

## 📌 Rules
- `X` starts with the value `0`
- Each statement is one of the following:
  - `++X`
  - `X++`
  - `--X`
  - `X--`
- Increment statements increase `X` by `1`
- Decrement statements decrease `X` by `1`

---

## ✅ Output
- Print the final value of `X`

---

## ✨ Examples

### Example 1
**Input**
```

n = 3
Statements:
++X
X++
--X

```

**Explanation**
- Start with `X = 0`
- `++X` → `X = 1`
- `X++` → `X = 2`
- `--X` → `X = 1`

**Output**
```

1

```

---

### Example 2
**Input**
```

n = 2
Statements:
X--
--X

```

**Explanation**
- Start with `X = 0`
- `X--` → `X = -1`
- `--X` → `X = -2`

**Output**
```

-2

```

---

## 🎯 Key Idea
The problem is about simulating simple operations and tracking how increment and decrement statements affect a variable.

---
