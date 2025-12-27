# Problem 289A – Polo the Penguin and Segments

## 🧩 Problem Summary
You are given `n` segments on a number line.  
Each segment is represented by two integers `l` and `r` (inclusive).

You are also given an integer `k`.  
Your task is to determine the **minimum number of integers** that need to be added so that the **total count of integers covered by all segments** becomes divisible by `k`.

---

## 📌 Rules
- Each segment `[l, r]` includes all integers from `l` to `r`
- Segments may overlap
- Count **all integers** covered by the segments
- You may add extra integers outside the segments if needed
- The final total count must be divisible by `k`

---

## ✅ Output
- Print a single integer: the minimum number of integers that must be added

---

## ✨ Examples

### Example 1
**Input**
```

n = 1, k = 3
Segment:
1 2

```

**Explanation**  
The segment covers 2 integers: `{1, 2}`  
To make the count divisible by 3, one more integer is needed.

**Output**
```

1

```

---

### Example 2
**Input**
```

n = 2, k = 4
Segments:
1 3
5 6

```

**Explanation**  
First segment covers 3 integers, second covers 2 integers.  
Total = 5 integers.  
To reach the next multiple of 4 (8), 3 integers must be added.

**Output**
```

3

```

---

### Example 3
**Input**
```

n = 1, k = 5
Segment:
10 14

```

**Explanation**  
The segment already covers 5 integers, which is divisible by 5.

**Output**
```

0

```

---

## 🎯 Key Idea
The problem focuses on counting how many integers are covered by all given segments and determining how many more are needed to make this total **a multiple of `k`**.

---