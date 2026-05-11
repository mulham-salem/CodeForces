# Problem 108A – Palindromic Times

## 📌 Problem Summary

Given a time in the format `HH:MM`, find the next time that forms a palindrome.

A time is considered palindromic when it reads the same forward and backward after removing the colon `:`.

For example:

- `12:21` → palindrome
- `13:31` → palindrome
- `15:45` → not palindrome

If the given time is already palindromic, you must find the next one after it.

---

## 📥 Input

A single string representing the time:

```text
HH:MM
```

Where:

- `00 ≤ HH ≤ 23`
- `00 ≤ MM ≤ 59`

---

## 📤 Output

Print the nearest palindromic time strictly after the given time.

---

## 🧠 Idea

Simulate the clock minute by minute:

1. Increase the current time by one minute.
2. Check whether the new time is a palindrome.
3. Stop when the first valid palindromic time is found.

---

## ✅ Palindrome Condition

For a time:

```text
HH:MM
```

It is palindromic if:

```text
H1 == M2
H2 == M1
```

Example:

```text
13:31
```

Because:

- `1 == 1`
- `3 == 3`

---

## 📝 Example 1

### Input

```text
12:21
```

### Output

```text
13:31
```

### Explanation

`12:21` is already a palindrome, but we need the next one after it.

---

## 📝 Example 2

### Input

```text
23:59
```

### Output

```text
00:00
```

### Explanation

After `23:59`, the clock resets to `00:00`, which is palindromic.

---

## 💻 Pseudocode

```
read time

while true:
    move to next minute

    if minutes become 60:
        reset minutes to 0
        increase hour

    if hours become 24:
        reset hours to 0

    if current time is palindrome:
        print it
        stop
```

---