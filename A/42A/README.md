# Problem 42A – Guilty — to the kitchen!

## Problem Description
Volodya has to cook **borscht** according to a recipe with `n` ingredients.  
Each ingredient `i` must be used in proportion `a[i]` litres per unit of soup.  
Volodya has `b[i]` litres of each ingredient available, and a pan of maximum volume `V`.  

Your task is to determine the **maximum amount of soup** Volodya can cook, respecting both the ingredient limits and the pan volume.

---

## Input
- First line: two integers `n` and `V` — number of ingredients and maximum pan volume.  
- Second line: `n` integers `a[i]` — proportion of each ingredient.  
- Third line: `n` integers `b[i]` — available amount of each ingredient.

### Constraints
- \(1 <= n <= 20\)  
- \(1 <= V <= 10000\)  
- \(1 <= a[i] <= 100\)  
- \(0 <= b[i] <= 100\)

---

## Output
- One real number: the maximum volume of soup Volodya can cook.  
- The answer must have **relative or absolute error less than \(10^{-4}\)**.

---

## Examples

### Example 1

**Input**

```
1 100 1 40
```

**Output**

```
40.0
```

### Example 2

**Input**

```
2 100 1 1 25 30
```

**Output**

```
50.0
```

### Example 3

**Input**

```
2 100 1 1 60 60
```

**Output**

```
100.0
```

---

## Solution Idea

1. Let `x` be the number of "units of soup" to cook.  
   - Each ingredient `i` will need `a[i] * x` litres.  
   - We must have `a[i] * x <= b[i]` for all `i`.
2. Compute the maximum `x` allowed by the available ingredients:

x_max = min(b[i] / a[i]) for all i

3. Compute total soup volume:

total_volume = x_max * sum(a[i])

4. Respect pan volume:

answer = min(total_volume, V)

---

## Pseudocode

```
read n, V read array a[0..n-1] read array b[0..n-1]

x_max = infinity for i = 0 to n-1: x_max = min(x_max, b[i] / a[i])

total_volume = x_max * sum(a[i] for i = 0..n-1) answer = min(total_volume, V)

print answer with high precision
```
---