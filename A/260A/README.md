# Problem 260A – Adding Digits

## Problem Summary

Vasya has a number `a`, but he considers it too short.  
He wants to apply a *lengthening operation* exactly `n` times.

A single lengthening operation:
- Adds **exactly one digit** (0–9) to the **right** of the current number.
- The resulting number **must be divisible by `b`**.
- If no digit (0–9) makes the number divisible by `b`, the process fails.

Your task is to output the number obtained after `n` successful operations.  
If it is impossible, output `-1`.

If multiple answers exist, **any one of them is acceptable**.

---

## Key Observations

- After each step, the number grows by **one digit**.
- The final length is `len(a) + n`.
- Storing the full number as an integer is not feasible for large `n`.
- We only need to track the number **modulo `b`**.

---

## Mathematical Insight

Let the current number be `x`.

When we append a digit `d`:
```

new_number = x * 10 + d

```

Divisibility condition:
```

(x * 10 + d) % b == 0

```

Using modular arithmetic:
```

(x * 10 + d) % b == ((x % b) * 10 + d) % b

```

This allows us to:
- Track only the remainder (`mod`) instead of the full number.
- Avoid overflow while handling very large numbers.

---

## Algorithm (High-Level)

1. Convert `a` to a string (to store the result).
2. Compute `mod = a % b`.
3. Repeat `n` times:
   - Try all digits from `0` to `9`.
   - For each digit, check if appending it makes the number divisible by `b`.
   - If a valid digit is found:
     - Append it to the result string.
     - Update `mod`.
   - If no digit works, output `-1` and stop.
4. Output the final string.

---

## Pseudocode

```

result ← string representation of a
mod ← a % b

repeat n times:
found ← false
for digit from 0 to 9:
new_mod ← (mod * 10 + digit) % b
if new_mod == 0:
append digit to result
mod ← new_mod
found ← true
break
if not found:
output -1
exit

output result

```

---

## Example 1

**Input**
```

a = 5, b = 4, n = 1

```

**Process**
- Try: 50 ❌, 51 ❌, 52 ✅

**Output**
```

52

```

---

## Example 2

**Input**
```

a = 7, b = 3, n = 2

```

**Process**
- 72 is divisible by 3
- 720 is divisible by 3

**Output**
```

720

```

---

## Example 3

**Input**
```

a = 260, b = 150, n = 10

```

**Process**
- No digit can be appended to make the number divisible by 150.

**Output**
```

-1

```

---

## Complexity Analysis

- Time Complexity: **O(n × 10)** → linear in `n`
- Space Complexity: **O(n)** for storing the result string

---

## Notes

- The solution relies on modular arithmetic to handle very large numbers safely.
- Greedy digit selection works because only divisibility matters, not the numeric value.