# Problem 132A – Turing Tape

## Problem Summary

You are given a string `text` that was generated using a special encoding process called **Turing Tape**.

Each character in the string was produced from an array of integers (0–255) using bit manipulation and modular arithmetic.

Your task is to **reconstruct the original array** that produced the given string.

---

## How the Encoding Works (Reversed Logic)

For each character in the string:

1. Take the ASCII value of the current character.
2. Reverse its 8-bit binary representation.
3. Use the previous reversed value (starting from 0 for the first character).
4. The original array value is computed using:

```text
a_i = (prev - reversed(current) + 256) mod 256
```

5. Update `prev` with the reversed value of the current character.

---

## Input

- A single string `text`
- Length: `1 ≤ |text| ≤ 100`
- Each character is a printable ASCII character (32–126)

---

## Output

Print the reconstructed array:
- One integer per line
- Each value in range `[0, 255]`

---

## Key Idea

We simulate the process in reverse:

- Convert character → ASCII
- Reverse its bits
- Apply modular subtraction to recover the original array values

---

## Example

### Input
```
Hello, World!
```
### Output
```
238 108 112 0 64 194 48 26 244 168 24 16 162
```
---

## Intuition

The encoding uses:
- Bit reversal (to scramble values)
- Modular subtraction (to depend on previous state)

So decoding requires carefully tracking the previous reversed value.

---

## Complexity

- Time: **O(n)** (each character processed once)
- Memory: **O(1)**

---

## Pseudocode
```
prev = 0

for each character c in text: 
	cur = reverseBits(ASCII(c)) 
	value = (prev - cur + 256) % 256 
	print value 
	prev = cur
```
---

## Notes

- Bit reversal is done on 8-bit binary representation.
- Modular arithmetic ensures values stay in range [0, 255].

---