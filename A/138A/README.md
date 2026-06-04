# Problem 138A – Literature Lesson

## 🧠 Problem Summary

You are given a poem made of **n quatrains**, each quatrain contains **4 lines**.

Each line has a rhyme defined as follows:
- Find the **k-th vowel from the end** (`a, e, i, o, u`)
- Take the suffix starting from that vowel to the end of the word
- This suffix is the line’s rhyme key

Two lines rhyme if their rhyme keys are identical.

Each quatrain must fit one of these patterns:
- `aabb` → (1=2 and 3=4)
- `abab` → (1=3 and 2=4)
- `abba` → (1=4 and 2=3)
- `aaaa` → all 4 lines rhyme

Goal: determine if the whole poem can follow **one common rhyme scheme**.

---

## 📥 Input

n k

Then follow `4 × n` lines representing the poem.

- `n`: number of quatrains
- `k`: vowel index from the end used to extract rhyme

---

## 📤 Output

Print one of:

aabb abab abba aaaa NO

---

## 💡 Key Idea

1. Convert each line into its rhyme suffix (based on k-th vowel from end).
2. For each quatrain, check which rhyme patterns are valid:
   - `aabb`
   - `abab`
   - `abba`
   - `aaaa`
3. Track which patterns remain valid across all quatrains.
4. If no pattern works → print `NO`
5. Special case:
   - If all quatrains are `aaaa`, print `aaaa`

---

## 📌 Example

### Input

1 1 day may sun fun

### Rhyme extraction

day → ay may → ay sun → un fun → un

### Pattern

aabb

### Output

aabb

---

## ⚙️ Algorithm (Pseudo Code)
```
for each line: find k-th vowel from end extract rhyme suffix

for each quatrain: check: aabb condition abab condition abba condition aaaa condition

if none valid:
    print NO

update global flags:
    canAABB &= aabb
    canABAB &= abab
    canABBA &= abba
    allAAAA &= aaaa

if allAAAA: print "aaaa" 
else if canAABB: print "aabb" 
else if canABAB: print "abab" 
else if canABBA: print "abba" 
else: print "NO"
```
---

## 🚀 Complexity

- Time: O(n × L)
- Memory: O(1) extra (besides input processing)

---

## 🧾 Summary

We reduce each line to a rhyme signature, then check 
which rhyme pattern is consistently valid across all quatrains. 
If multiple patterns conflict → output `NO`.

---