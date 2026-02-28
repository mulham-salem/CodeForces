# Problem 25A – IQ Test

**Platform:** Codeforces  
**Difficulty:** Easy  

## 🧠 Problem Summary

Bob is preparing for an IQ test.  
He is given `n` numbers, and **exactly one number differs from the others in evenness**.

- Most numbers are either **even**
- Or most numbers are **odd**
- Only **one number** has different parity

Your task is to determine the **1-based index** of that number.

### Constraints

- `3 ≤ n ≤ 100`
- Each number is a natural number ≤ 100
- Exactly one number differs in evenness

---

## 🔎 Key Idea

Since exactly one number is different:

- Either most numbers are **even** and one is **odd**
- Or most numbers are **odd** and one is **even**

We can:
1. Inspect the first 3 numbers to determine the majority parity.
2. Scan the array to find the number that differs.

---

## 📌 Example 1

### Input
```

5
2 4 7 8 10

```

### Explanation

Even numbers: 2, 4, 8, 10  
Odd number: 7  

Only **7** is different.  
Its position (1-based) is **3**.

### Output
```

3

```

---

## 📌 Example 2

### Input
```

4
1 2 1 1

```

### Explanation

Odd numbers: 1, 1, 1  
Even number: 2  

Only **2** is different.  
Its position is **2**.

### Output
```

2

```

---

## 💡 Pseudocode

```

read n
read array a

even_count = 0
odd_count = 0

// Determine majority using first three elements
for i from 1 to 3:
if a[i] % 2 == 0:
even_count++
else:
odd_count++

if even_count > odd_count:
majority = "even"
else:
majority = "odd"

// Find the index of the different element
for i from 1 to n:
if majority == "even" and a[i] % 2 != 0:
print i
stop
if majority == "odd" and a[i] % 2 == 0:
print i
stop

```

---

## ⏱ Time Complexity

- **O(n)**  
We scan the array at most twice.

---

## 🎯 Takeaway

The problem is a simple parity check task.  
The trick is realizing that checking only the first three numbers is enough to determine the majority.
