# Problem 22A – Second Order Statistics

**Source:** Codeforces  
**Problem Link:** 22A – Second Order Statistics  

---

## 🧠 Problem Summary

Given a sequence of integers, you must find the **second order statistic**.

The second order statistic is defined as:

> The smallest element that is **strictly greater** than the minimum element in the sequence.

If such a value does not exist, print:

```

NO

```

---

## 📥 Input

- An integer `n` (1 ≤ n ≤ 100) — number of elements.
- A sequence of `n` integers (each value between -100 and 100).

---

## 📤 Output

- Print the second order statistic.
- If it does not exist, print `NO`.

---

## 📌 Explanation

1. Sort the sequence.
2. Identify the minimum element.
3. Find the first element strictly greater than the minimum.
4. If found → print it.
5. Otherwise → print `NO`.

---

## 🔎 Examples

### Example 1

**Input**
```

4
1 2 2 -4

```

**Sorted**
```

-4 1 2 2

```

Minimum = `-4`  
Smallest number greater than -4 = `1`

**Output**
```

1

```

---

### Example 2

**Input**
```

5
1 2 3 1 1

```

**Sorted**
```

1 1 1 2 3

```

Minimum = `1`  
Smallest number greater than 1 = `2`

**Output**
```

2

```

---

### Example 3

**Input**
```

3
5 5 5

```

All elements are equal.  
No value is strictly greater than the minimum.

**Output**
```

NO

```

---

## 💡 Pseudocode

```

read n
read array

sort array

min_value = array[0]

for i from 1 to n-1:
if array[i] > min_value:
print array[i]
stop program

print "NO"

```

---

## ⏱ Complexity

- Sorting: O(n log n)
- Traversal: O(n)
- Overall: O(n log n)
