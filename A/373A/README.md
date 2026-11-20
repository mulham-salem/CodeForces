# Problem 373A – Collecting Beats is Fun

## Problem Explanation

Kyubeat is a rhythm game with a **4×4 grid** of panels. Some panels light up at specific timings (digit `1`–`9`), and `.` means no panel.

Cucumber boy uses **two hands**, and each hand can press at most **k panels at the same time**.  
So in any given timing (same digit), he can press at most **2 × k** panels.

He wants to press **every panel exactly at its preferred time**.  
We need to check if this is possible.

---

### Key Idea
- Count how many times each digit `1`–`9` appears in the grid.
- For each digit, if its count is greater than `2 × k`, then he cannot press them all at the same moment → answer is `NO`.
- Otherwise → `YES`.

---

### Example 1
```

k = 1
.135
1247
3468
5789

```
Frequencies: 1→2, 2→2, 3→2, 4→2, 5→2, 6→1, 7→2, 8→2, 9→1  
Max capacity = 2 × 1 = 2  
All frequencies ≤ 2 → **YES**

---

### Example 2
```

k = 5
..1.
1111
..1.
..1.

```
Digit `1` appears 7 times. Capacity = 10. 7 ≤ 10 → **YES**

---

### Example 3
```

k = 1
....
12.1
.2..
.2..

```
Digit `2` appears 3 times. Capacity = 2. 3 > 2 → **NO**

---

## Pseudocode

```

READ k
INITIALIZE freq[10] = {0}

FOR each of 4 rows:
	READ string s
	
	FOR each character c in s:
		IF c != '.':
			freq[c - '0'] += 1

capacity = 2 * k

FOR i from 1 to 9:
	IF freq[i] > capacity:
		PRINT "NO"
		EXIT

PRINT "YES"

```

---

## Complexity

- **Time Complexity:** `O(1)`  
  The grid is always fixed at 4×4 = 16 cells, and we loop over 9 digits. Both are constant, so the runtime does not depend on input size.

- **Space Complexity:** `O(1)`  
  We only use a fixed-size array of 10 integers (`freq[10]`) regardless of input.