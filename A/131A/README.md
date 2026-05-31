# Problem 131A - cAPS lOCK

## Idea

Sometimes a word is typed with the **Caps Lock** key accidentally enabled.

We should change the case of all letters if:

- The whole word is uppercase.
- All letters except the first one are uppercase.

Otherwise, keep the word unchanged.

---

## Examples

| Input | Output |
|---|---|
| `cAPS` | `Caps` |
| `LOCK` | `lock` |
| `Lock` | `Lock` |
| `z` | `Z` |

---

## Explanation

For the word `cAPS`:

- All characters except the first one are uppercase.
- So we invert the case of every character.

Result:

- `c` → `C`
- `A` → `a`
- `P` → `p`
- `S` → `s`

Final word: `Caps`

---

## Algorithm

1. Check if every character after the first one is uppercase.
2. If true:
   - Change lowercase letters to uppercase.
   - Change uppercase letters to lowercase.
3. Otherwise:
   - Print the word unchanged.

---

## Pseudocode

```text
read word

valid = true

for each character from index 1 to end:
    if character is lowercase:
        valid = false

if valid:
    for each character in word:
        invert its case

print word
```

---

## Complexity

| Complexity | Value |
|---|---|
| Time | `O(n)` |
| Memory | `O(1)` |

---