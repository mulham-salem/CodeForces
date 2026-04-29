# Problem 95A – Hockey

## 🧩 Problem Summary
You are given:
- A string `w`
- `n` forbidden substrings
- A target lowercase letter `letter`

Your task is to:
1. Find all occurrences of forbidden substrings inside `w` (**case-insensitive**).
2. Mark all positions covered by these occurrences.
3. Replace only those marked characters:
   - Keep the **same case** (uppercase/lowercase)
   - Replace with **any other letter**
4. Maximize the number of occurrences of `letter`
5. If multiple answers exist → return the **lexicographically smallest**

---

## ⚠️ Key Observations

- Matching is **case-insensitive**
- Replacement is done **only once**
- You **must change** every covered character
- Case must stay the same
- You **cannot modify** uncovered characters

---

## 🧠 Strategy

For each position in `w`:

| character case | decision |
|----------|--------|
| Not covered | Keep it as is |
| Covered & NOT equal to `letter` | Replace with `letter` (same case) |
| Covered & already equal to `letter` | Replace with smallest possible letter ≠ `letter` |

---

## 📥 Input Format

n s1 s2 ... sn w letter

- `n`: number of forbidden substrings
- `s1...sn`: forbidden strings
- `w`: original string
- `letter`: target character

---

## 📤 Output

- Final string after replacements:
  - Maximum occurrences of `letter`
  - Lexicographically smallest among valid answers

---

## 🔍 Example 1

### Input

3 bers ucky elu PetrLoveLuckyNumbers t

### Output

PetrLovtTttttNumtttt

---

## 🔍 Example 2

### Input

4 hello party abefglghjdhfgj IVan petrsmatchwin a

### Output

petrsmatchwin

👉 No forbidden substrings found → no changes allowed

---

## 🔍 Example 3

### Input

2 aCa cba abAcaba c

### Output

abCacba

---

## 🧾 Pseudocode
```
read n read forbidden strings read w read letter

convert all forbidden strings to lowercase convert w to lowercase → w_lower

create covered array of size |w| = false

for each forbidden string f: for each position i in w: if substring matches (case-insensitive): mark all positions in covered

for each position i: if not covered: continue

if w[i] is NOT equal to letter (case-insensitive):
    replace with letter (same case)

else:
    replace with smallest letter ≠ letter (same case)

print result
```
---

## 💡 Complexity

- Time: `O(n * |w| * max_length)`
- Space: `O(|w|)`

---

## 🚀 Key Insight

- Covered positions are **forced to change**
- Maximize `letter` wherever possible
- If already `letter`, replace with smallest valid alternative to keep lexicographically minimal result

---