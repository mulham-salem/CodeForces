# Problem 61A – Ultra-Fast Mathematician

## Problem Description
You are given two binary strings of equal length.  
Each string consists only of characters `0` and `1`.

Your task is to generate a new binary string by applying the **XOR operation** to each corresponding pair of bits.

---

## XOR Operation
The XOR (exclusive OR) operation works as follows:

| Bit A | Bit B | A XOR B |
|------|------|---------|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

**Rule:**
- If the two bits are the same → result is `0`
- If the two bits are different → result is `1`

---

## How the Solution Works
1. Read the two binary strings.
2. Loop through each position.
3. Compare the characters at the same index.
4. Output `1` if they are different, otherwise output `0`.

---

## Example

### Input
```

10101
00101

```

### Step-by-step Comparison

| Position | First String | Second String | Result |
|---------|-------------|---------------|--------|
| 1 | 1 | 0 | 1 |
| 2 | 0 | 0 | 0 |
| 3 | 1 | 1 | 0 |
| 4 | 0 | 0 | 0 |
| 5 | 1 | 1 | 0 |

### Output
```

10000

```

---

## Key Notes
- Both strings always have the same length.
- No spaces should be printed in the output.
- The result is a single binary string.

This problem is a straightforward implementation of bitwise XOR using string comparison.