# Problem 20A – BerOS File System

## 🗂 Overview

The BerOS operating system allows using multiple consecutive `/` characters as path separators.  
For example:

```

//usr///local//nginx/sbin//

```

is equivalent to:

```

/usr/local/nginx/sbin

```

A path is considered **normalized** if it contains the **minimum possible number of `/` characters**.

Your task is to transform a given path into its normalized form.

---

## 📥 Input

A single line representing a path:

- Contains only lowercase Latin letters and `/`
- Always starts with at least one `/`
- Length ≤ 100

---

## 📤 Output

Print the normalized version of the given path.

---

## 📌 Normalization Rules

1. Replace every sequence of consecutive `/` characters with a single `/`.
2. Remove the trailing `/` **unless** the path is the root directory.
3. The root directory must be represented as:
```

/

```

---

## 🧠 Key Idea

While iterating through the string:

- Add `/` only if the previous character in the result is not `/`.
- Always add non-slash characters.
- After processing, remove the trailing `/` if:
- The result length is greater than 1.

---

## 🧩 Examples

### Example 1

**Input**
```

//usr///local//nginx/sbin//

```

**Output**
```

/usr/local/nginx/sbin

```

---

### Example 2

**Input**
```

////

```

**Output**
```

/

```

(Represents the root directory.)

---

### Example 3

**Input**
```

/home///

```

**Output**
```

/home

````

---

## 💻 Pseudocode

```text
read path

result = empty string

for each character c in path:
    if c == '/':
        if result is empty OR last character of result is not '/':
            append '/' to result
    else:
        append c to result

if length of result > 1 AND last character is '/':
    remove last character

print result
````

---

## ⏱ Complexity

* Time Complexity: **O(n)**
* Space Complexity: **O(n)**
* Where `n ≤ 100`

---

## ✅ Notes

* No need for regex.
* No need for string splitting.
* A single linear pass over the string is sufficient.
* Be careful with handling the root case (`"/"`).