# Problem 88A – Chord

## 🧩 Problem Summary
You are given **three musical notes**. Your task is to determine whether they form:

- a **major chord**
- a **minor chord**
- or a **strange chord**

The notes are part of a **cyclic scale of 12 notes**, meaning after the last note, it wraps back to the first.

---

## 🎼 Notes Mapping
To simplify the problem, map each note to a number:

C  = 0 C# = 1 D  = 2 D# = 3 E  = 4 F  = 5 F# = 6 G  = 7 G# = 8 A  = 9 B  = 10 H  = 11

---

## 🔁 Key Idea
Since the notes are **unordered**, you must try **all possible permutations (6 total)** of the three notes.

For each ordering `(a, b, c)`, compute:

d1 = (b - a + 12) % 12 d2 = (c - b + 12) % 12

This ensures correct **cyclic distance**.

---

## 🎯 Classification Rules

| Condition        | Result  |
|------------------|--------|
| d1 = 4 and d2 = 3 | major  |
| d1 = 3 and d2 = 4 | minor  |
| otherwise         | strange |

---

## 🧠 Examples

### Example 1

Input: C E G

Mapping:

0 4 7

Check:

0 → 4 = 4 4 → 7 = 3

✅ Result: **major**

---

### Example 2

Input: C# B F

Mapping:

1 10 5

Try ordering `(B, C#, F)`:

10 → 1 = 3 1 → 5 = 4

✅ Result: **minor**

---

### Example 3

Input: A B H

Mapping:

9 10 11

No permutation satisfies the conditions.

❌ Result: **strange**

---

## ⚙️ Pseudocode
```
read s1, s2, s3

convert each note to its numeric value

store them in array A

generate all 6 permutations of A

for each permutation (a, b, c): 
	d1 = (b - a + 12) % 12 
	d2 = (c - b + 12) % 12

if d1 == 4 and d2 == 3:
    print "major"
    exit

if d1 == 3 and d2 == 4:
    print "minor"
    exit

print "strange"
```
---

## 💡 Notes
- The order of input does **not** matter.
- Always consider **cyclic distance**.
- Only one valid answer will exist.

---