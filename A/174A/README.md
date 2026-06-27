# Problem 174A – Problem About Equation

## 🧩 Problem Statement
You are given:
- `n` mugs
- `b` milliliters of drink in a bottle
- Initial amounts `a[i]` in each mug

You must pour **all `b` milliliters** into the mugs so that:
- The bottle becomes empty
- All mugs end with the **same amount of drink**

---

## 📥 Input
- First line: `n b`
  - `n` → number of mugs
  - `b` → amount of drink in the bottle

- Second line: `a1 a2 ... an`
  - current amounts in each mug

---

## 📤 Output
- Print `-1` if it is impossible
- Otherwise print `n` numbers:
  - `c[i]` = amount to add to mug `i`
- Each value must have **at least 6 digits after decimal point**

---

## 💡 Core Idea

Let the final equal amount in every mug be:
```
x = (sum(a) + b) / n
```
Then for each mug:
```
c[i] = x - a[i]
```
---

## ⚠️ Validity Condition

A solution is valid only if:

for all i: a[i] ≤ x

If any mug already exceeds `x`, we cannot remove drink → answer is `-1`.

---

## 🧪 Example 1

### Input
```
5 
50 
1 2 3 4 5
```
### Computation
- sum = 15  
- total = 65  
- x = 65 / 5 = 13  

### Output
```
12.000000 11.000000 10.000000 9.000000 8.000000
```
---

## 🧪 Example 2

### Input
```
2 
2 
1 100
```
### Output
```
-1
```
---

## 🧠 Pseudocode
```
read n, b 
read array a

sum = total of a 
x = (sum + b) / n

if any a[i] > x: print -1 exit

for each i: print x - a[i] with 6 decimals
```

---

## ⚙️ Complexity
- Time: O(n)
- Memory: O(1) extra (besides input array)

---