# Problem 49A – Sleuth

## 🧠 Problem Summary

Vasya asks questions, and his friends answer based on a hidden rule:

- If the last letter of the question is a vowel, the answer is "YES"
- If it is a consonant, the answer is "NO"

## ⚠️ Important:

- Ignore spaces and the question mark "?"
- Only the last letter matters
- Case does not matter ("A" = "a")

---

## 🔤 Vowels

A, E, I, O, U, Y

All other letters are consonants.

---

## 💡 Approach

- Read the full line
- Traverse from the end of the string
- Find the first alphabetic character
- Convert it to lowercase
- Check whether it is a vowel or consonant

---

## 🧪 Examples

### Example 1

Input:
```
Is it a melon?
```

Output:
```
NO
```

Explanation: last letter = "n" → consonant

---

### Example 2

Input:
```
Is it an apple?
```
Output:
```
YES
```

Explanation: last letter = "e" → vowel

---

### Example 3

Input:
```
  Is     it a banana ?
```

Output:
```
YES
```

Explanation: last letter = "a" → vowel

---

### Example 4

Input:
```
Is   it an apple  and a  banana   simultaneouSLY?
```

Output:
```
YES
```

Explanation: last letter = "Y" → vowel

---

## 🧩 Pseudocode

```
read input string s

for i from end of s to beginning:
    if s[i] is a letter:
        c = lowercase(s[i])

        if c is in {a, e, i, o, u, y}:
            print "YES"
        else:
            print "NO"

        break
```

---

## ⏱ Complexity

```
- Time: O(n)
- Space: O(1)If you want
```

---