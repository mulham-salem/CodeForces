# Problem 32A – Reconnaissance

## Problem Summary
Captain Bob has **n soldiers**, each with a certain height.  
A reconnaissance unit must consist of **exactly two soldiers**.

The difference between their heights must **not exceed `d` centimeters**.

Important rule:
- The pairs **(i, j)** and **(j, i)** are considered **different ways**.

Your task is to count the **number of ordered pairs of soldiers** whose height difference is **≤ d**.

---

## Key Idea

Two soldiers `i` and `j` can form a valid reconnaissance unit if:

```

|height[i] - height[j]| ≤ d

```

Since **order matters**, every valid unordered pair produces **two valid ways**:
```

(i, j)
(j, i)

```

To simplify comparison, we **sort the heights** first.  
After sorting, the difference becomes:

```

height[j] - height[i]

```

for `j > i`.

Then we check all pairs and count the valid ones.

---

## Example

### Example 1

Input
```

n = 5
d = 10
heights = [10, 20, 50, 60, 65]

```

Valid pairs with difference ≤ 10:

```

(10,20)
(50,60)
(60,65)

```

Each pair counts as **two ways**:

```

(10,20) (20,10)
(50,60) (60,50)
(60,65) (65,60)

```

Total:

```

6

```

---

### Example 2

Input
```

n = 5
d = 1
heights = [55, 30, 29, 31, 55]

```

After sorting:

```

[29, 30, 31, 55, 55]

```

Valid pairs:

```

(29,30)
(30,31)
(55,55)

```

Each produces **two ordered pairs**, so the answer is:

```

6

```

---

## Algorithm

1. Read `n` and `d`.
2. Store the heights in an array.
3. Sort the array.
4. Check every pair `(i, j)` where `j > i`.
5. If the difference is ≤ `d`, add **2** to the answer.
6. Print the result.

---

## Pseudocode

```
read n, d
read array heights

sort heights

count = 0

for i from 0 to n-1
	for j from i+1 to n-1
		diff = heights[j] - heights[i]

			if diff ≤ d
				count = count + 2

print count

```

---

## Complexity Analysis

Time Complexity:

```

O(n log n)   for sorting
O(n²)        for checking pairs

```

Overall:

```

O(n²)

```

Space Complexity:

```

O(n)

```
