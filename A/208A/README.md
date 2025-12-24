# Problem 208A – Dubstep

## Requirement

You are given a string representing a song remix.

In the remix, the substring `"WUB"` is inserted **one or more times**:
- At the beginning of the song
- At the end of the song
- Between words

**Goal:**  
Restore the **original song** by:
- Removing all occurrences of `"WUB"`
- Replacing them with **single spaces**
- Making sure there are **no extra spaces** at the beginning or end

---

## Input

- One string `s`
  - Consists only of uppercase English letters
  - Length is at most 200 characters

---

## Output

- Print the restored original song

---

## Examples

### Example 1

**Input**
```

WUBWUBABCWUB

```

**Output**
```

ABC

```

**Explanation**
```

"WUB" appears before and after the word.
After removing it, only "ABC" remains.

```

---

### Example 2

**Input**
```

WUBWEWUBAREWUBTHEWUBCHAMPIONSWUB

```

**Output**
```

WE ARE THE CHAMPIONS

```

**Explanation**
```

"WUB" separates the words.
Each group of one or more "WUB" is replaced by a single space.

```

---

## Solution Idea

1. Scan the string from left to right.
2. Whenever `"WUB"` appears:
   - Treat it as a **word separator**.
3. Extract all valid words.
4. Join the words using a **single space**.
5. Print the final restored song.

---

## Key Notes

- Multiple consecutive `"WUB"` should produce **only one space**.
- No leading or trailing spaces are allowed in the output.

---

## Complexity

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

---