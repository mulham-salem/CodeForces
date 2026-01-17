# Problem 58A – Chat room

## 🧠 Problem Overview
You are given a string `s` representing a chat message.  
Your task is to determine whether it is possible to obtain the word **`hello`** by deleting some characters from `s` **without changing the order** of the remaining characters.

In other words, you need to check if `"hello"` is a **subsequence** of the given string.

---

## ✅ Key Idea
- Characters of `"hello"` **do not need to be consecutive**
- The **order must be preserved**
- Extra characters in between are allowed

We scan the string from left to right and try to match the characters of `"hello"` one by one.

---

## 📝 Examples

### Example 1
```

Input:
ahhellllloou

Output:
YES

```

Explanation:  
We can find `h → e → l → l → o` in order, even though there are extra characters in between.

---

### Example 2
```

Input:
hlelo

Output:
NO

```

Explanation:  
The characters exist, but the required order for `"hello"` is not preserved.

---

### Example 3
```

Input:
hello

Output:
YES

```

Explanation:  
The string already matches `"hello"` directly.

---

## 🧩 Approach (High Level)
1. Store the target word `"hello"`
2. Keep a pointer to track the current character we want to match
3. Traverse the input string character by character
4. When a character matches the current target character, move the pointer forward
5. If all characters of `"hello"` are matched → print `YES`, otherwise `NO`

---

## 🔁 Pseudocode
```

target = "hello"
index = 0

for each character c in input_string:
if c == target[index]:
index = index + 1

```
if index == length of target:
    break
```

if index == length of target:
print "YES"
else:
print "NO"

```

---

## 📌 Notes
- This problem checks understanding of **subsequence**, not substring
- Time complexity is linear: **O(n)**
- Very common pattern in competitive programming

---

Happy coding 🚀