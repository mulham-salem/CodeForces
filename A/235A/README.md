# 235A — LCM Challenge

## 📌 Problem

Given an integer `n`, choose **three positive integers** that are not greater than `n`.

The three integers **do not have to be distinct**.

The goal is to find the **maximum possible LCM (Least Common Multiple)** of the three chosen integers.

---

## 📥 Input

The input contains a single integer:

```text
n
```
Constraints

`1 ≤ n ≤ 10⁶`


---

## 📤 Output

Print a single integer — the maximum possible LCM of three positive integers, each of which is at most n.

Since the answer can exceed the range of a 32-bit integer, use a 64-bit integer such as long long.


---

## 🧪 Examples

### Example 1

### Input:
```
9
```
We can choose:

`9, 8, 7`

Their LCM is:

`LCM(9, 8, 7) = 504`

### Output:
```
504
```

---

### Example 2

### Input:
```
7
```
We can choose:

`7, 6, 5`

Their LCM is:

`LCM(7, 6, 5) = 210`

### Output:
```
210
```

---

## 💡 Key Idea

We need to maximize the LCM of three numbers not greater than n.

We do not need to try all possible triples.

The optimal choice depends on the value of n:

| Condition | Chosen Numbers |
|-----------|-----------------|
| `n ≤ 2` | `n, n, n` |
| `n` is odd | `n, n-1, n-2` |
| `n` is even and divisible by `3` | `n-1, n-2, n-3` |
| `n` is even and not divisible by `3` | `n, n-1, n-3` |

---

## 🧠 Algorithm

1. Read n.

2. If n ≤ 2, the answer is simply n.

3. Otherwise, check whether n is odd.

If it is odd, choose n, n-1, and n-2.

4. Otherwise, n is even.

If n is divisible by 3, choose n-1, n-2, and n-3.

Otherwise, choose n, n-1, and n-3.

5. Print the product of the selected three numbers.

---

## 📝 Pseudocode
```
Read n

If n <= 2:
    answer = n

Else if n is odd:
    answer = n × (n - 1) × (n - 2)

Else if n is divisible by 3:
    answer = (n - 1) × (n - 2) × (n - 3)

Else:
    answer = n × (n - 1) × (n - 3)

Print answer
```

---

## ⏱️ Complexity

**Time Complexity:** `O(1)`

Only a constant number of conditions and arithmetic operations are performed.

**Space Complexity:** `O(1)`

Only a few variables are used.

---

## 🔑 Important Notes

LCM stands for Least Common Multiple — the smallest positive number divisible by all the chosen numbers.

The three selected numbers do not have to be distinct.

Use long long because the result can be larger than a 32-bit integer.

The solution does not require loops or checking all possible triples.

---