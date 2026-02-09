# Problem 4A – Watermelon

## 📝 Problem Summary
Pete and Billy bought a watermelon weighing **w** kilograms.  
They want to divide it into **two parts**, such that:

- Each part has an **even** weight
- Each part has a **positive** weight
- The two parts do **not** have to be equal

Your task is to determine whether such a division is possible.

---

## 💡 Key Observation
- An even number can be split into two even numbers **only if it is greater than 2**.
- The smallest even positive number is **2**, so the smallest valid split is:
```

2 + 2 = 4

````

---

## ✅ Decision Rule
The watermelon **can** be divided if and only if:
- `w` is **even**
- `w` is **greater than 2**

Otherwise, it is **not possible**.

---

## 📌 Examples

| Input | Explanation | Output |
|------|------------|--------|
| 8 | 2 + 6 (both even) | YES |
| 4 | 2 + 2 | YES |
| 2 | 0 + 2 (invalid) | NO |
| 3 | Cannot split into even parts | NO |

---

## 🧠 Pseudocode

```text
read w

if w > 2 AND w is even then
  print "YES"
else
  print "NO"
````

---

## ⏱️ Complexity

* **Time Complexity:** O(1)
* **Space Complexity:** O(1)