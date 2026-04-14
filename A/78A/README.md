# Problem 78A – Haiku

## 🧩 Problem Overview
You are given **three lines**, each representing a phrase of a poem.  
Your task is to check whether the poem follows the **haiku structure**.

A valid haiku must follow this vowel pattern:
- First line → **5 vowels**
- Second line → **7 vowels**
- Third line → **5 vowels**

> In this problem, the number of **syllables = number of vowels**.

---

## 🔤 Vowels Definition
Only the following characters are considered vowels:

a, e, i, o, u

---

## 📥 Input
- Exactly **3 lines**
- Each line:
  - Contains lowercase English letters and spaces
  - May include leading/trailing spaces
  - Words are separated by one or more spaces

---

## 📤 Output
- Print `"YES"` if the poem follows the **5-7-5** rule  
- Otherwise, print `"NO"`

---

## 🧠 Approach
- Read the three lines using a method that preserves spaces
- Count the number of vowels in each line
- Compare the counts with `[5, 7, 5]`

---

## 🪜 Pseudocode

```
define function countVowels(line): 
	count = 0 
	for each character c in line: 
		if c is in ['a', 'e', 'i', 'o', 'u']: 
			count++ 
	return count

expected = [5, 7, 5]

for i from 0 to 2: 
	read line 
	if countVowels(line) != expected[i]: 
		print "NO" 
		exit

print "YES"
```

---

## ✅ Example 1

### Input
```
on  codeforces 
beta round is running 
	a rustling of keys
```
### Output
```
YES
```
---

## ❌ Example 2

### Input
```
how many gallons 
of edo s rain did you drink 
							cuckoo
```
### Output
```
NO
```
---

## ⚡ Notes
- Spaces do **not** affect the result
- Only vowel counting matters
- Stop early if any line does not match the expected count

---