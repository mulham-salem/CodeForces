# Problem 96A – Football

## 🧩 Problem Summary
You are given a string consisting only of `0`s and `1`s:
- `0` represents players from one team
- `1` represents players from another team

A situation is considered **dangerous** if there are **at least 7 consecutive identical characters** in the string.

Your task is to determine whether the given situation is dangerous or not.

---

## 📥 Input
- A single string `s` (1 ≤ |s| ≤ 100)
- Contains only characters `0` and `1`

---

## 📤 Output
- Print `YES` if the situation is dangerous
- Otherwise, print `NO`

---

## 🧠 Approach
We scan the string and count consecutive identical characters.

- Initialize a counter `count = 1`
- Traverse the string from left to right
- If the current character equals the previous one → increment `count`
- Otherwise → reset `count = 1`
- If `count` reaches 7 → immediately return `YES`

If we finish the loop without reaching 7 → return `NO`

---

## 🔍 Examples

| Input              | Output | Explanation                          |
|--------------------|--------|--------------------------------------|
| `001001`           | NO     | No 7 consecutive identical digits    |
| `1000000001`       | YES    | Contains 8 consecutive `0`s           |
| `11110111011101`   | NO     | Max consecutive is less than 7        |
| `1111111`          | YES    | Exactly 7 consecutive `1`s            |

---

## ⚙️ Pseudo Code

```
read string s
count = 1

for i from 1 to length(s) - 1:
    if s[i] == s[i - 1]:
        count = count + 1
    else:
        count = 1

    if count >= 7:
        print "YES"
        exit

print "NO"
```

---

⏱ Complexity

Type	Value

Time	O(n)
Space	O(1)

---

✅ Key Idea

The problem reduces to finding the maximum length of consecutive identical characters in the string.
If it is ≥ 7 → YES, otherwise → NO.

---