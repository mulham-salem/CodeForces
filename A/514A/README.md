# Problem 514A – Chewbaсca and Number

## Requirement
You are given:

- A number **n** represented as a string.

Chewbacca applies the following operation:
- For every digit `d` in the number, you may replace it with `9 - d`.
- You should do this **only if it makes the number smaller**.
- The resulting number **must not start with zero**.

Your task is to output the **minimum possible number** after applying the operation optimally.

---

## Input
- A string **n** (the number, without leading zeros)

---

## Output
- The transformed number after applying Chewbacca’s rule

---

## Examples

### Example 1
**Input**
```

4545

```

**Output**
```

4444

```

**Explanation**

Digit-by-digit:
- `4 → min(4, 9−4=5) = 4`
- `5 → min(5, 9−5=4) = 4`

Result: `4444`

---

### Example 2
**Input**
```

9

```

**Output**
```

9

```

**Explanation**

- `9 → 9−9 = 0`, but this would create a leading zero.
- So the digit remains unchanged.

---

### Example 3
**Input**
```

123

```

**Output**
```

123`

```

**Explanation**

- `1 → min(1, 8) = 1`
- `2 → min(2, 7) = 2`
- `3 → min(3, 6) = 3`

No change needed.

---

## Solution Idea
1. Traverse the number digit by digit.
2. For each digit `d`:
   - Compute `9 - d`.
   - Replace `d` with `min(d, 9 - d)`.
3. **Exception**:
   - If the digit is the **first digit** and `9 - d == 0`,
     do **not** replace it.
4. Print the resulting number.

---

## Important Notes
- The number must not start with `0`.
- Each digit is handled independently.
- The length of the number never changes.

---

## Complexity
- **Time Complexity:** O(length of n)
- **Space Complexity:** O(1)

---

## Key Insight
To minimize the number:
- Replace each digit with its complement to 9 **only if it becomes smaller**.
- Never allow the first digit to become zero.
