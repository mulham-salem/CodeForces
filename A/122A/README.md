# Problem 122A - Lucky Division

| Category | Details |
|---|---|
| **Difficulty** | Easy |
| **Topic** | Brute Force |
| **Platform** | Codeforces |

---

## 📌 Problem Summary

A number is called **lucky** if it contains only the digits `4` and `7`.

Examples of lucky numbers:

- `4`
- `7`
- `44`
- `47`

A number is called **almost lucky** if it is divisible by at least one lucky number.

Your task is to determine whether the given number `n` is almost lucky.

---

## 📥 Input

| Input | Description |
|---|---|
| `n` | A single integer `(1 ≤ n ≤ 1000)` |

---

## 📤 Output

| Output |
|---|
| Print `"YES"` if `n` is divisible by any lucky number, otherwise print `"NO"` |

---

## 💡 Examples

| Input | Output | Explanation |
|---|---|---|
| `47` | `YES` | `47` itself is a lucky number |
| `16` | `YES` | `16` is divisible by `4` |
| `78` | `NO` | `78` is not divisible by any lucky number |

---

## 🧠 Idea

Generate or store all lucky numbers less than or equal to `1000`, then check if any of them divides `n` without remainder.

If at least one lucky number satisfies:

```math
n \bmod x = 0
```

then the answer is `"YES"`.

Otherwise, print `"NO"`.

---

## 📝 Pseudocode

```text
read n

lucky_numbers = [4, 7, 44, 47, 74, 77, ...]

for each number x in lucky_numbers:
    if n % x == 0:
        print "YES"
        stop

print "NO"
```

---

## ⏱️ Complexity

| Complexity | Value |
|---|---|
| **Time Complexity** | `O(k)` |
| **Memory Complexity** | `O(1)` |

Where `k` is the number of lucky numbers checked.

---