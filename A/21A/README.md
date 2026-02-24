# Problem 21A – Jabber ID

## 📌 Problem Overview

You are given a string and must determine whether it is a valid **Jabber ID**.

A Jabber ID has the following format:

```

<username>@<hostname>[/resource]

```

The `/resource` part is optional.

Your task is to validate the string according to the given rules and print:

```

YES

```

if it is valid, otherwise:

```

NO

```

---

## 🔎 Validation Rules

### 1️⃣ Username

- Length: **1 to 16**
- Allowed characters:
  - Letters (uppercase or lowercase)
  - Digits
  - Underscore `_`

---

### 2️⃣ Hostname

- Length: **1 to 32**
- Consists of words separated by dots `.`  
- Each word:
  - Length: **1 to 16**
  - Allowed characters:
    - Letters
    - Digits
    - Underscore `_`
- Empty words are NOT allowed  
  (Examples of invalid: `code..forces`, `.domain`, `domain.`)

---

### 3️⃣ Resource (Optional)

If present:

- Appears after `/`
- Length: **1 to 16**
- Allowed characters:
  - Letters
  - Digits
  - Underscore `_`

---

## 🧠 Key Idea

Validation should be done step-by-step:

1. Check that there is exactly one `@`.
2. Split string into:
   - Username
   - Remaining part
3. If `/` exists:
   - Split into hostname and resource
   - Ensure there is at most one `/`
4. Validate hostname by splitting it using `.` and checking each word.
5. Validate resource if it exists.

---

## 🧩 Examples

### Example 1

Input:
```

[mike@codeforces.com](mailto:mike@codeforces.com)

```

Output:
```

YES

```

Valid because:
- Username valid
- Hostname valid
- No resource (optional)

---

### Example 2

Input:
```

[007@en.codeforces.com](mailto:007@en.codeforces.com)/contest

```

Output:
```

YES

```

Valid because:
- Username valid
- Hostname valid
- Resource valid

---

### Example 3

Input:
```

[john.smith@codeforces.ru](mailto:john.smith@codeforces.ru)/contest.icpc/12

```

Output:
```

NO

````

Invalid because:
- More than one `/`
- Structure breaks the required format

---

## 💻 Pseudocode

```text
read input string

if number of '@' ≠ 1:
    print NO

split string into username and rest using '@'

validate username:
    - length in [1,16]
    - allowed characters only

check for '/':
    if more than one '/' → NO
    if one '/' → split into hostname and resource
    else:
        hostname = rest

validate hostname:
    - length in [1,32]
    - split by '.'
    - each word:
        - length in [1,16]
        - valid characters only

if resource exists:
    - validate length in [1,16]
    - validate allowed characters

if all checks passed:
    print YES
else:
    print NO
````

---

## ⏱ Complexity

* Time Complexity: **O(n)**
* Space Complexity: **O(n)**
* Where `n ≤ 100`

---

## ✅ Important Notes

* Do not allow multiple `@`
* Do not allow multiple `/`
* Do not allow empty hostname words
* Always validate lengths before character validation
* String parsing carefully is the key to solving it correctly
