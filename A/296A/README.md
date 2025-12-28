# Problem 296A – Yaroslav and Time

## Requirement

You are given an array of `n` integers.

You need to determine whether it is possible to **rearrange the array** such that  
**no two equal numbers are adjacent**.

---

**Goal:**  
Print `"YES"` if such a rearrangement is possible, otherwise print `"NO"`.

---

## Input

- First line: integer `n` – number of elements
- Second line: `n` integers – the array elements

---

## Output

- Print `"YES"` or `"NO"`

---

## Examples

### Example 1

**Input**

```

5
1 1 2 2 3

```

**Output**

```

YES

```

**Explanation**

```

One possible rearrangement:
1 2 1 3 2
No two equal numbers are adjacent

```

---

### Example 2

**Input**

```

3
1 1 1

```

**Output**

```

NO

```

**Explanation**

```

Any rearrangement will have two adjacent equal elements

```

---

## Solution Idea

1. Count the frequency of each number.
2. Let `maxFreq` be the maximum frequency of any number.
3. If `maxFreq` is greater than `(n + 1) / 2`, then it is **impossible**.
4. Otherwise, it is **possible**.

---

## Explanation

To avoid having two equal adjacent elements:

- The most frequent number must be separated by other numbers.
- Between `maxFreq` identical elements, there must be enough different elements.
- This condition is satisfied only if:

```

maxFreq ≤ (n + 1) / 2

```

---

## Formula

```

max_frequency ≤ (n + 1) / 2

```

---

## Implementation Notes

- Sorting the array and counting consecutive elements is sufficient.
- Using a map or array for frequency counting also works.
- Time complexity is `O(n)`.