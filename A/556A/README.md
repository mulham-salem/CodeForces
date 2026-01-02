# Problem 556A – Case of Zeroes and Ones

## Requirement
You are given:

- An integer **n** — the length of a binary string.
- A string **s** consisting only of characters `'0'` and `'1'`.

You may repeatedly remove **one pair of adjacent characters** `"01"` or `"10"` from the string.

Your task is to determine the **minimum possible length** of the string after performing
any number of such operations.

---

## Input
- Integer **n**
- Binary string **s**

---

## Output
- One integer — the minimum length of the string after all possible removals

---

## Examples

### Example 1
**Input**
```

4
1100

```

**Output**
```

0

```

**Explanation**

Possible removals:
- `1100 → 100 → 00 → ""`
All characters can be removed.

---

### Example 2
**Input**
```

5
01010

```

**Output**
```

1

```

**Explanation**

Each removal deletes one `'0'` and one `'1'`.
If counts differ by 1, one character remains.

---

## Solution Idea
1. Count the number of `'0'` characters.
2. Count the number of `'1'` characters.
3. Each removal eliminates **one zero and one one**.
4. The remaining length is:
```

abs(count_0 - count_1)

```

---

## Important Notes
- The order of characters does **not** matter.
- Only the **difference** between counts remains.
- Simulation is unnecessary.

---

## Complexity
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

---

## Key Insight
Every valid removal deletes exactly one `'0'` and one `'1'`.
So the final string length depends only on the **difference in counts**.
