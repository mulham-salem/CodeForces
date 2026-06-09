# Problem 147A – Punctuation

## Overview

You are given a text containing lowercase English letters, spaces, and punctuation marks (`.`, `,`, `!`, `?`).

Your task is to reformat the text so that:

- Words are separated by exactly one space.
- There are no spaces before punctuation marks.
- There is exactly one space after each punctuation mark.

---

## Input

A single non-empty line representing the text.

### Constraints

- Text length ≤ 10000 characters.
- The text starts and ends with a letter.
- There is always at least one word between any two punctuation marks.

---

## Output

Print the corrected text following all formatting rules.

---

## Example 1

### Input

```text
galileo galilei was an   italian physicist  ,mathematician,astronomer
```

### Output

```text
galileo galilei was an italian physicist, mathematician, astronomer
```

### Explanation

- Multiple spaces between words become a single space.
- Spaces before commas are removed.
- A single space is added after each comma.

---

## Example 2

### Input

```text
galileo  was  born  in  pisa
```

### Output

```text
galileo was born in pisa
```

### Explanation

Since there is no punctuation, only consecutive spaces need to be reduced to a single space.

---

## Key Idea

Process the text character by character while building a new string:

1. Ignore extra spaces.
2. Remove spaces before punctuation marks.
3. Add exactly one space after punctuation marks.
4. Keep exactly one space between consecutive words.

---

## Pseudocode

```text
read text

result = empty string
pendingSpace = false

for each character c in text

    if c is a space
        pendingSpace = true

    else if c is a punctuation mark

        remove trailing spaces from result

        append c to result
        append one space to result

        pendingSpace = false

    else

        if pendingSpace and result is not empty
           and last character of result is not a space

            append one space

        append c to result
        pendingSpace = false

if result ends with a space
    remove it

print result
```

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

Where `n` is the length of the input text.

---