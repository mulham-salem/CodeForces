# Problem 71A – Way Too Long Words

## Requirement

You are given several words.  
Some words are **too long** and need to be abbreviated.

A word is considered **too long** if its length is **more than 10 characters**.

**Abbreviation rule:**
- Keep the **first character**
- Replace the middle characters with their **count**
- Keep the **last character**

---

## Input

- The first line contains one integer `t` — the number of words.
- The next `t` lines each contain one word.

---

## Output

- Print the processed version of each word:
  - If the word length is **≤ 10**, print it as is.
  - If the word length is **> 10**, print its abbreviated form.

---

## Examples

### Example 1

**Input**
```

4
word
localization
internationalization
hi

```

**Output**
```

word
l10n
i18n
hi

```

---

## Explanation

```

word
Length = 4 → not longer than 10 → print as is

localization
Length = 12
Abbreviation: l + 10 + n → l10n

internationalization
Length = 20
Abbreviation: i + 18 + n → i18n

hi
Length = 2 → print as is

```

---

## Solution Idea

1. Read the number of words `t`.
2. For each word:
   - If its length is **≤ 10**, print it directly.
   - Otherwise:
     - Print the first character.
     - Print `(length - 2)`.
     - Print the last character.
3. Move to the next word.

---

## Abbreviation Formula

```

abbreviated_word =
first_letter + (word_length - 2) + last_letter

```

---

## Complexity

- **Time Complexity:** `O(total characters)`
- **Space Complexity:** `O(1)` per word

---
