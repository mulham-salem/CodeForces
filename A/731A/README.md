# Problem 731A – Night at the Museum

## Requirement
You are given a string **s** consisting of lowercase English letters.

There is a circular dial with the letters:
`a b c ... z`
- The dial starts at letter **'a'**
- You can rotate the dial **clockwise or counter-clockwise**
- Each move by one letter costs **1 unit of time**

Your task is to calculate the **minimum total time**
required to type the entire string **s**.

---

## Input
- A string **s** (only lowercase letters)

---

## Output
- One integer — the minimum time required.

---

## Examples

### Example 1
**Input**
```

zeus

```

**Output**
```

18

```

**Explanation**

Start at **'a'**

- a → z : min(|a−z| = 25, 26−25 = 1) → 1  
- z → e : min(21, 5) → 5  
- e → u : min(16, 10) → 10  
- u → s : min(2, 24) → 2  

Total time = **1 + 5 + 10 + 2 = 18**

---

### Example 2
**Input**
```

abc

```

**Output**
```

2

```

**Explanation**

- a → a = 0  
- a → b = 1  
- b → c = 1  

Total time = **2**

---

## Solution Idea
- Keep track of the current letter (start with `'a'`)
- For each character in the string:
  - Compute the absolute distance between the current letter and the target letter
  - Because the dial is circular, the cost is:
    - `min(distance, 26 - distance)`
  - Add this cost to the total time
  - Update the current letter

---

## Important Notes
- The alphabet is circular (after `z` comes `a`)
- You can rotate in either direction; always choose the shorter one

---

## Complexity
- **Time Complexity:** `O(n)` where n is the length of the string
- **Space Complexity:** `O(1)`

---

## Key Insight
At each step, choosing the shorter rotation on the circular alphabet
guarantees the minimum total time.
