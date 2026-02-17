# Problem 13A – Numbers

## Problem Statement

Little Petya likes numbers a lot. He wants to find the **average sum of digits** of a given number \(A\) when it is written in all bases from 2 to \(A-1\).  

Formally:

- Input: a single integer \(A\) (3 ≤ A ≤ 1000)
- Output: the average sum of digits in all bases from 2 to \(A-1\), expressed as an irreducible fraction `X/Y`.

**Note:** All computations are done in base 10.

---

## Example

### Input
```

5

```

### Output
```

7/3

```

### Explanation

- Convert 5 to bases 2, 3, 4:
  | Base | Representation | Sum of digits |
  |------|----------------|---------------|
  | 2    | 101            | 2             |
  | 3    | 12             | 3             |
  | 4    | 11             | 2             |

- Total sum = 2 + 3 + 2 = 7  
- Number of bases = 5 - 2 = 3  
- Average = 7 / 3 → `7/3`  

---

## Approach / Pseudocode

```

read A
total_sum = 0

for base from 2 to A-1:
temp = A
digit_sum = 0

```
while temp > 0:
    digit_sum += temp % base  # get remainder as digit
    temp = temp // base        # divide by base

total_sum += digit_sum
```

denominator = A - 2
g = gcd(total_sum, denominator)  # simplify fraction

print total_sum / g "/" denominator / g

```

### Steps

1. Loop through all bases from 2 to A-1.
2. Convert the number A to the current base using division and remainder.
3. Sum the digits of the number in that base.
4. Accumulate all sums.
5. Compute the average as a fraction and simplify using GCD.

---

## Notes

- The key part is **base conversion** using remainder (`%`) and integer division (`//`).
- Simplifying the fraction ensures the output is in **irreducible form**.
- Works efficiently for all values up to the maximum \(A = 1000\).

---