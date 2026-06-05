# Problem 140A – New Year Table

## Overview

You are given a circular table with radius **R**, and **n** identical circular plates, each with radius **r**.

You need to determine whether it is possible to place all plates on the table such that:

- Each plate lies completely inside the table  
- Each plate touches the border of the table  
- Plates do not overlap (touching is allowed)

---

## Key Idea

Because every plate must touch the border of the table, the center of each plate must lie on a circle with radius:

### d = R - r

So instead of placing circles inside a circle, we are effectively placing **n points on a circle of radius d**.

---

## Geometry Insight

When we place **n points evenly spaced on a circle**, the angle between two adjacent points is:

### θ = 2π / n

The distance between two adjacent centers is the chord length:

### distance = 2d · sin(π / n)

---

## Valid Condition

Each plate has radius **r**, so two plates do not overlap if:

### 2r ≤ 2d · sin(π / n)

---

## Input

n R r

- n → number of plates  
- R → radius of table  
- r → radius of each plate  

Constraints:

1 ≤ n ≤ 100 1 ≤ r, R ≤ 1000

---

## Output

Print:

- YES → if all plates can be placed  
- NO → otherwise  

---

## Examples

### Example 1

Input: 4 10 4

Output: YES

Explanation:  
4 plates can be evenly placed around the table without overlapping.

---

### Example 2

Input: 5 10 4

Output: NO

Explanation:  
5 plates are too many, so they become too close and overlap.

---

### Example 3

Input: 1 10 10

Output: YES

Explanation:  
Only one plate fills the table exactly and touches the border.

---

## Summary

- Plate centers lie on a circle with radius (R − r)
- We check spacing between adjacent centers
- If spacing is enough → YES  
- Otherwise → NO

---