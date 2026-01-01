# Problem 474A – Keyboard

## Requirement
You are given:

- A string **s** representing a keyboard layout.  
- Some letters on the keyboard may be **broken**.  

You need to type a **word**.  
Your task is to determine whether you can type it using only the **working keys**.

---

## Input
- String **s** — the word to type  
- String **t** — letters that are working on the keyboard  

Both strings consist of lowercase English letters.

---

## Output
- Print `YES` if the word can be typed  
- Print `NO` if at least one letter is missing

---

## Examples

### Example 1
**Input**
```

hello
helo

```

**Output**
```

YES

```

**Explanation**

All letters in "hello" (`h`, `e`, `l`, `l`, `o`) are in the set of working keys `helo`.

---

### Example 2
**Input**
```

world
wrd

```

**Output**
```

NO

```

**Explanation**

Letter `o` and `l` are missing in the working keys → cannot type the word.

---

## Solution Idea
1. Store all working keys in a set.
2. Traverse the word to type:
   - If any letter is not in the set → print `NO`.
3. If all letters are present → print `YES`.

---

## Important Notes
- Repeated letters in the word are allowed.
- Only lowercase English letters appear.
- The order of letters in working keys does not matter.

---

## Complexity
- **Time Complexity:** O(|s| + |t|)
- **Space Complexity:** O(26) → constant

---

## Key Insight
Checking membership in a set is fast.
If all letters in the word exist in the set of working keys → typing is possible.
