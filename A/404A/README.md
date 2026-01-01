# Problem 404A – Triangle

## Requirement
You are given:

- An integer **n** — the size of a square matrix.
- An **n × n** matrix of characters.

Your task is to determine whether the matrix forms a **valid X-shaped pattern**.

The matrix is valid if:
- All characters on the **main diagonal** are the same.
- All characters on the **secondary diagonal** are the same.
- The character on the diagonals is **different** from the character on all other positions.
- All non-diagonal positions contain the **same character**.

If all conditions are satisfied, print **YES**, otherwise print **NO**.

---

## Input
- Integer **n**
- **n** lines, each containing **n** characters

---

## Output
- `YES` if the matrix is valid  
- `NO` otherwise

---

## Examples

### Example 1
**Input**
```

3
xox
oxo
xox

```

**Output**
```

YES

```

**Explanation**

Matrix:
```

x o x
o x o
x o x

```

- Main diagonal: all `x`
- Secondary diagonal: all `x`
- All other positions: `o`
- Diagonal character (`x`) ≠ other character (`o`)

✔ Valid pattern

---

### Example 2
**Input**
```

3
xxx
xxx
xxx

```

**Output**
```

NO

```

**Explanation**

All characters are the same.
Diagonal and non-diagonal characters must be different.

✘ Invalid pattern

---

### Example 3
**Input**
```

4
abba
baab
baab
abba

```

**Output**
```

YES

```

**Explanation**

- Both diagonals contain the same character.
- All non-diagonal positions contain another single character.
- Characters are consistent and different.

✔ Valid pattern

---

## How to Identify Diagonal Cells

For a cell at position **(i, j)**:
- It is on the **main diagonal** if `i == j`
- It is on the **secondary diagonal** if `i + j == n - 1`

If either condition is true → diagonal cell.

---

## Solution Idea
1. Store the character at position `(0,0)` as the **diagonal character**.
2. Store the character at position `(0,1)` as the **non-diagonal character**.
3. Traverse the entire matrix:
   - If the cell is on a diagonal:
     - It must match the diagonal character.
   - Otherwise:
     - It must match the non-diagonal character.
4. If any rule is violated → print `NO`.

---

## Important Notes
- Diagonal and non-diagonal characters must be **different**.
- All diagonal positions must be identical.
- All non-diagonal positions must be identical.

---

## Complexity
- **Time Complexity:** O(n²)
- **Space Complexity:** O(1)

---

## Key Insight
The matrix is valid if it contains **exactly two distinct characters**:
- one used only on both diagonals,
- one used everywhere else.