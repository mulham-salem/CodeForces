# Problem 239A – Valera and Potatoes

## 🧩 Problem Overview

Valera had two bags of potatoes:
- The first bag contained **x** potatoes (**x ≥ 1**) — this bag was lost.
- The second bag contained **y** potatoes — this value is known.

Valera remembers two facts about the total number of potatoes **(x + y)**:
1. The total was **not greater than n**.
2. The total was **divisible by k**.

Your task is to determine **all possible values of x** that satisfy these conditions.

---

## 📥 Input

Three integers:
- `y` — number of potatoes in the second bag
- `k` — divisor
- `n` — maximum allowed total number of potatoes

**Constraints:**
- `1 ≤ y, k, n ≤ 10⁹`

---

## 📤 Output

- Print all possible values of `x` in **ascending order**, separated by spaces.
- If no valid value of `x` exists, print `-1`.

---

## 💡 Key Insight

The constraints apply to the **sum (x + y)**, not to `x` directly.

From the condition `x ≥ 1`, the smallest possible total is:
```

x + y ≥ y + 1

```

So we only need to consider values of `(x + y)` that:
- Are divisible by `k`
- Lie in the range `[y + 1, n]`

For each valid total, we can recover:
```

x = (x + y) − y

```

---

## ✏️ Example

**Input:**
```

y = 10, k = 6, n = 40

```

Valid totals divisible by `k` in range `[11, 40]`:
```

12, 18, 24, 30, 36

```

Corresponding values of `x`:
```

2, 8, 14, 20, 26

```

**Output:**
```

2 8 14 20 26

```

---

## 🧠 Pseudo-code

```

read y, k, n

minSum = y + 1

if minSum > n:
print -1
exit

found = false

for sum from k to n, step k:
if sum < minSum:
continue

```
print (sum - y)
found = true
```

if not found:
print -1

```

---

## ⏱ Complexity

- **Time Complexity:** `O(n / k)`
- **Space Complexity:** `O(1)`

---

## ✅ Notes

- The solution iterates over **multiples of k**, not over all possible values of `x`.
- This approach is efficient even for very large inputs.

---

Happy coding 🚀