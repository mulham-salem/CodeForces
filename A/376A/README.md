# Problem 376A – Lever

## Problem Statement

You are given a string `s` representing a lever. The lever is a horizontal bar of length `|s| - 1`, and each character describes what is at that coordinate:

- `^` — the pivot (fulcrum) is at this position.
- `=` — nothing is on the bar at this position.
- `1`–`9` — a weight of that mass is placed at this position.

The bar itself is weightless. All weights are placed simultaneously. Determine whether the lever will tilt **left**, **right**, or stay in **balance**.

The lever is in balance when the total torque on the left side equals the total torque on the right side. Torque for a weight = `mass × distance from pivot`.

**Input:** A non-empty string `s` (`3 ≤ |s| ≤ 10^6`) with exactly one `^`, and the pivot is never at either end.

**Output:** Print `left`, `right`, or `balance`.

---

### Examples

| Input | Output | Explanation |
|-------|--------|-------------|
| `=^==` | `balance` | No weights on either side. |
| `9===^==1` | `left` | Left torque = 9×4 = 36, right torque = 1×2 = 2 → left wins. |
| `2==^7==` | `right` | Left torque = 2×3 = 6, right torque = 7×1 = 7 → right wins. |
| `41^52==` | `balance` | Left = 4×2 + 1×1 = 9, right = 5×1 + 2×2 = 9 → equal. |

---

### Constraints

- Use **64-bit integers** (`long long`) for torque values — distances can be up to `10^6` and masses up to `9`, so torque can exceed 32-bit range.

---

## Pseudocode

```

START

INPUT s

pivot = position of '^' in s

left = 0
right = 0

FOR i = 0 TO length(s) - 1

    IF s[i] is a digit

        weight = numeric value of s[i]

        IF i < pivot

            distance = pivot - i
            left = left + (weight * distance)

        ELSE IF i > pivot

            distance = i - pivot
            right = right + (weight * distance)

        END IF

    END IF

END FOR

IF left > right

    PRINT "left"

ELSE IF right > left

    PRINT "right"

ELSE

    PRINT "balance"

END IF

END

```

---

## Complexity 

**Time Complexity:** `O(|s|)`

The algorithm performs a single pass over the string, visiting each character exactly once. For every character, it does a constant amount of work: a digit check, a comparison against the pivot index, and at most one multiplication and addition. Therefore the total running time grows linearly with the length of the string.

**Space Complexity:** `O(1)` extra space

Apart from the input string itself, the algorithm only keeps a fixed number of scalar variables: `pivot`, `left`, `right`, `weight`, `distance`, and the loop counter `i`. None of these scale with the input size, so the auxiliary memory usage is constant.
