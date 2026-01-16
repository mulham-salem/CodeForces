# Problem 337A – Puzzles

## 🧩 Problem Overview
You are given:
- `n`: the number of students  
- `m`: the number of available puzzles  
- An array of `m` integers, where each integer represents the number of pieces in a puzzle  

Each student should receive **exactly one puzzle**.  
Your goal is to choose **`n` puzzles out of the `m` available ones** such that the **difference between the maximum and minimum number of pieces** among the chosen puzzles is **as small as possible**.

---

## 🎯 Objective
Minimize the following value:
```

max(pieces) - min(pieces)

```
for any selection of `n` puzzles.

---

## 💡 Key Insight
After sorting the puzzle sizes:
- The minimum possible difference will always occur when choosing **`n` consecutive puzzles**.
- There is no need to check all combinations (which would be inefficient).

This approach is **Greedy + Implementation**.

---

## 🛠️ Solution Strategy
1. Read the input values.
2. Sort the array of puzzle sizes.
3. Consider every consecutive group of `n` puzzles.
4. For each group, compute the difference between:
   - the first element (minimum)
   - the last element (maximum)
5. Keep track of the smallest difference found.

---

## ✨ Example

### Input
```

n = 3
m = 5
puzzles = [10, 12, 10, 7, 5]

```

### After Sorting
```

[5, 7, 10, 10, 12]

```

### Groups of size `n`
| Selected Puzzles | Difference |
|------------------|------------|
| [5, 7, 10]       | 10 - 5 = 5 |
| [7, 10, 10]      | 10 - 7 = 3 |
| [10, 10, 12]     | 12 - 10 = 2 |

### Result
```

2

```

---

## 🧠 Pseudocode

```

read n, m
read array puzzles of size m

sort puzzles in ascending order

answer = very large number

for i from 0 to m - n:
current_difference = puzzles[i + n - 1] - puzzles[i]
answer = min(answer, current_difference)

print answer

```

---

## 📌 Complexity Analysis
- Sorting: `O(m log m)`
- Single pass through the array: `O(m)`
- Total complexity: `O(m log m)`

---

## ✅ Conclusion
By sorting the puzzles and checking only consecutive groups of size `n`, we efficiently find the minimum possible difference.  
This avoids brute force and guarantees the optimal solution.
