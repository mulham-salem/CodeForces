# Problem 287A – IQ Test

## 🧩 Problem Summary
You are given a **4×4 grid** where each cell is either:

- `#` (black)
- `.` (white)

Your task is to determine whether there exists **at least one 2×2 square** in the grid where **at least 3 cells have the same color**.

---

## 📌 Rules
- The grid size is always **4 rows × 4 columns**
- You must check all possible **2×2 subgrids**
- A valid 2×2 square contains:
  - at least **3 black cells (`#`)**, or
  - at least **3 white cells (`.`)**

---

## ✅ Output
- Print `"YES"` if such a 2×2 square exists
- Print `"NO"` otherwise

---

## ✨ Examples

### Example 1
**Input**
```

####

#..#
#..#

####

```

**Explanation**  
There are multiple 2×2 squares with at least 3 `#` characters.

**Output**
```

YES

```

---

### Example 2
**Input**
```

#.#.
.#.#
#.#.
.#.#

```

**Explanation**  
Every 2×2 square contains exactly 2 black and 2 white cells.

**Output**
```

NO

```

---

### Example 3
**Input**
```

##..
##..
....
....

```

**Explanation**  
The top-left 2×2 square contains 4 black cells.

**Output**
```

YES

```

---

## 🎯 Key Idea
The problem requires scanning all **2×2 subgrids** and checking if any of them contains **at least three identical characters**, regardless of their positions inside the square.

---