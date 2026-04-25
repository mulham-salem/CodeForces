# Problem 91A – Newspaper Headline

## 📰 Problem Summary

You are given two strings:

- `s1`: a newspaper headline (source string)
- `s2`: a target word

You can:
- Take **multiple copies** of `s1`
- Concatenate them into one long string
- Delete characters (without changing order)

### 🎯 Goal:
Find the **minimum number of copies of `s1`** needed to form `s2` as a subsequence.

If it is impossible, print `-1`.

---

## 💡 Key Idea

We simulate building `s2` by scanning through repeated copies of `s1`.

- We try to match characters of `s2` one by one
- Each time we reach the end of `s1`, we start a new copy
- If a character in `s2` does not exist in `s1` → impossible

---

## 🔁 Algorithm (Pseudo Code)
```
read s1, s2

if any character in s2 is not in s1: print -1 exit

build a list posList[26] for each character in s1: store all indices of each character

count = 1 pos = -1

for each character c in s2: vec = posList[c]

find first index in vec > pos using upper_bound

if found:
    pos = that index
else:
    count += 1
    pos = first occurrence of c in s1

print count
```
---

## 🧠 Explanation

### Why this works?

We always try to take the **next valid occurrence** of each character in order.

If no valid position exists in the current copy of `s1`, we:
- Start a new copy
- Reset position tracking

---

## 📌 Example 1

### Input:

s1 = "abcd" s2 = "dabc"

### Steps:
- Take `'d'` → end of first pass
- Need new copy for `'a'`, `'b'`, `'c'`

### Output:

2

---

## 📌 Example 2

### Input:

s1 = "abc" s2 = "xyz"

### Reason:
- Characters `x`, `y`, `z` do not exist in `s1`

### Output:

-1

---

## ⚡ Complexity

- Preprocessing: `O(|s1|)`
- Processing `s2`: `O(|s2| log |s1|)`

Efficient for large inputs.

---

## 🧾 Summary

- Greedy matching of characters
- Use binary search to jump through positions
- Count how many full passes of `s1` are needed

---