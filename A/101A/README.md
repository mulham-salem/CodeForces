# Problem 101A – Homework

## 🧠 Overview
You are given a string `s` of lowercase English letters and an integer `k`.

You can delete **at most `k` characters** (from any positions).  
Your goal is to **minimize the number of distinct characters** remaining in the string.

Finally, output:
- The **minimum number of distinct characters** (`m`)
- A **valid subsequence** of the original string that contains exactly `m` distinct characters

---

## 💡 Key Idea
To minimize the number of distinct characters:
- Remove **entire character types** (all occurrences of a character)
- Always remove the character with the **smallest frequency first** (greedy)

> Partial deletion of a character does NOT reduce the number of distinct characters.

---

## 📥 Input
- A string `s` (1 ≤ |s| ≤ 100000)
- An integer `k` (0 ≤ k ≤ 100000)

---

## 📤 Output
- An integer `m`: minimum number of distinct characters remaining
- A string: any valid subsequence with exactly `m` distinct characters

---

## 🧪 Examples

### Example 1

Input: aaaaa 4

Output: 1 aaaaa

**Explanation:**
- Only one character (`a`)
- You cannot delete all 5 characters (limit is 4)
- So at least one `a` remains → 1 distinct character

---

### Example 2

Input: abacaba 4

Output: 1 aaaa

**Explanation:**
- Frequencies: a=4, b=2, c=1
- Remove `c` (cost=1), then `b` (cost=2)
- Total cost = 3 ≤ 4
- Only `a` remains → 1 distinct character

---

### Example 3

Input: abcdefgh 10

Output: 0

**Explanation:**
- You can delete all characters (k ≥ length)
- Result is empty → 0 distinct characters

---

## ⚙️ Approach

1. Count frequency of each character
2. Sort characters by frequency (ascending)
3. Remove characters while `k` allows:
   - If `freq <= k`, remove it completely
   - Decrease `k`
4. Keep remaining characters
5. Build result as a subsequence from the original string

---

## 🧩 Pseudocode
```
read string s read k

count frequency of each character (size 26 array)

create list of (frequency, character) sort list ascending by frequency

mark all characters as NOT removed

for each (freq, char) in sorted list: if freq <= k: mark char as removed k -= freq else: break

result = empty string

for each character c in s: if c is NOT removed: append c to result

m = number of distinct characters in result

print m print result
```
---

## ⏱ Complexity
- Time: **O(n + 26 log 26)** ≈ **O(n)**
- Space: **O(26)**

---

## 📝 Notes
- You are NOT required to use all `k`
- The result must preserve original order (subsequence)
- Multiple valid answers may exist

---