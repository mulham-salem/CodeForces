# Problem 352A – Jeff and Digits

## Problem Summary
Jeff has `n` cards. Each card contains either digit `0` or digit `5`.
He can choose some of these cards and arrange them to form a number.

The task is to construct the **largest possible number** that is **divisible by 90**.
- The number must not have leading zeros (except the number `0` itself).
- Jeff does not have to use all the cards.

---

## Divisibility Rules for 90
A number is divisible by **90** if and only if:
1. It is divisible by **10** → the last digit must be `0`
2. It is divisible by **9** → the sum of its digits must be divisible by `9`

---

## Key Observations
- The cards contain only digits `0` and `5`
- Digit `0` does not affect divisibility by `9`
- Each digit `5` contributes `5` to the digit sum
- Therefore, the number of `5`s must be a multiple of `9`

---

## Solution Strategy
1. Count how many `0`s and `5`s exist
2. If there is **no `0`**, it is impossible to form a number divisible by `10` → print `-1`
3. Take the **maximum number of `5`s that is divisible by `9`**
4. If no such `5`s can be used, print `0`
5. Otherwise:
   - Print all selected `5`s first
   - Then print all `0`s at the end

This produces the **largest possible valid number**.

---

## Examples

### Example 1
**Input**
```

4
5 0 5 0

```

**Output**
```

0

```

**Explanation**
- Not enough `5`s to make the sum divisible by `9`
- At least one `0` exists, so the largest valid number is `0`

---

### Example 2
**Input**
```

11
5 5 5 5 5 5 5 5 0 5 5

```

**Output**
```

5555555550

```

**Explanation**
- `9` digits of `5` make the sum divisible by `9`
- The number ends with `0`, so it is divisible by `10`
- The result is divisible by `90`

---

## Final Notes
- Use as many `5`s as possible (in multiples of `9`)
- Use all `0`s to maximize the number
- If no valid number can be formed, handle edge cases correctly