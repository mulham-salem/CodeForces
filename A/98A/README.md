# Problem 98A – Help Victoria the Wise

## 📌 Problem Overview

We are given 6 gems represented by colors (`R, O, Y, G, B, V`) that must be placed on the 6 faces of a perfect cube.

The cube has **rotational symmetry**, meaning two arrangements are considered the same if one can be rotated to match the other.

👉 The task is to count how many **distinct ways** exist to decorate the cube, considering all rotations as identical configurations.

---

## 🧠 Key Idea

This is a **combinatorics problem with symmetry (cube rotations)**.

Instead of counting all permutations directly, we must:

- Generate all possible placements of the 6 gems
- Eliminate duplicates caused by cube rotations
- Treat two configurations as identical if one can be rotated into the other

A cube has **24 possible rotations**, which define its symmetry group.

---

## 🔄 Approach

1. Read the 6-character string representing gem colors.
2. Generate all permutations of the 6 positions.
3. For each permutation:
   - Apply all 24 cube rotations
   - Convert it into a **canonical form** (lexicographically smallest representation)
4. Store canonical forms in a set to avoid duplicates.
5. Output the size of the set.

---

## 🧩 Pseudocode

```
read string s
sort s

set unique_configurations

for each permutation p of s:
    best = "maximum_string"
    
    for each rotation r in 24 cube rotations:
        rotated = apply_rotation(p, r)
        best = min(best, rotated)
    
    add best to unique_configurations

print size of unique_configurations
```

---

## 📊 Examples

### Example 1

Input:
YYYYYY

Output:
1

All gems are identical → every rotation looks the same.


---

### Example 2

Input:
BOOOOB

Output:
2

Only two distinct rotational patterns exist.


---

### Example 3

Input:
ROYGBV

Output:
30

All colors are different → many permutations, but rotations reduce duplicates.


---

## ⏱ Complexity

Permutations: 6! = 720

Rotations per permutation: 24

Total operations ≈ 17280


✔ Efficient and easily accepted.


---

## 📌 Summary

We count permutations of cube face assignments

We remove duplicates using cube rotational symmetry

We normalize each configuration using canonical representation

Final answer is the number of unique normalized states

---