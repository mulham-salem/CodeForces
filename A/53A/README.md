# Problem 53A – Autocomplete

## 🧠 Problem Summary
You are given a string `s` (typed by the user) and a list of `n` previously visited page addresses.

Your task is to simulate an **autocomplete feature**:
- Find all pages that start with `s` (i.e., `s` is a prefix).
- If such pages exist, output the **lexicographically smallest** one.
- Otherwise, output `s` itself.

---

## 📥 Input
- A string `s`
- An integer `n` (1 ≤ n ≤ 100)
- `n` strings representing visited pages

All strings:
- Length between 1 and 100
- Contain only lowercase English letters

---

## 📤 Output
- If no page starts with `s`, print `s`
- Otherwise, print the **smallest lexicographical page** that starts with `s`

---

## 📌 Key Concepts

### 🔹 Prefix Check
A string `t` starts with `s` if:

t.substr(0, s.length()) == s

### 🔹 Lexicographical Order
- Same as dictionary order
- Example:

"apple" < "banana" "abc" < "abd"

---

## 🧪 Examples

### Example 1

Input: next 2 nextpermutation nextelement

Output: nextelement

### Example 2

Input: find 4 find findfirstof findit fand

Output: find

### Example 3

Input: find 4 fondfind fondfirstof fondit fand

Output: find

---

## ⚙️ Approach

1. Read input `s` and list of pages
2. Filter pages that start with `s`
3. If no matches found → print `s`
4. Otherwise → return the smallest string lexicographically

---

## 🧾 Pseudocode
```
read s 
read n

minPage = empty found = false

for each page: 
	if page starts with s: 
		if not found OR page < minPage: 
			minPage = page found = true

if found: 
	print minPage
else: 
	print s
```
---

## ⏱ Complexity
```
- Time: O(n * m)
  - n = number of pages
  - m = length of strings
- Space: O(1) (optimized approach without extra storage)
```
---