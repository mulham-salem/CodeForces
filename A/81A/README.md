# Problem 81A – Plug-in

## 🧩 Overview
Given a string consisting of lowercase letters, your task is to repeatedly remove **pairs of consecutive identical characters**.

Whenever a pair like `aa`, `bb`, etc. appears, delete it.  
After deletion, new adjacent pairs may form — these should also be removed.

The process continues until no more such pairs exist.

---

## 💡 Key Idea
Instead of repeatedly scanning the string, we can simulate the process efficiently using a **stack-like approach**.

We build the final string step by step:
- If the current character matches the last added character → remove the last one (pair disappears)
- Otherwise → add the current character

This naturally handles cascading removals.

---

## ✏️ Examples

### Example 1
**Input**
```
hhoowaaaareyyoouu
```
**Output**
```
wre
```
---

### Example 2
**Input**
```
reallazy
```
**Output**
```
rezy
```
---

### Example 3
**Input**
```
abacabaabacabaa
```
**Output**
```
a
```
---

## ⚙️ Pseudocode
```
initialize empty result

for each character c in input string: 
	if result is not empty AND last character of result == c:
		remove last character from result 
	else: 
		add c to result

print result
```
---

## 🚀 Complexity
- **Time Complexity:** O(n)
- **Space Complexity:** O(n)

Efficient for large inputs (up to 2 × 10⁵ characters).

---

## 🧠 Notes
- The order of removals does not matter — the final result is always the same.
- This problem is a classic example of using a **stack to simulate pair cancellation**.

---