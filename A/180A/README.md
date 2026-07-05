# Problem 180A – Defragmentation

## 🧠 Problem Idea

You are given a disk of `n` clusters and `m` files.

Each file is split into multiple parts stored in different clusters (not necessarily contiguous).

Your goal is to **defragment the disk** so that:

- Each file becomes stored in a contiguous segment.
- Files are placed one after another starting from the beginning of the disk.
- The internal order of file fragments must be preserved.
- All free clusters must be moved to the end.

You are allowed to perform only one operation:
```
copy(i, j)
```
Which copies the content of cluster `i` into cluster `j` (overwriting it).

---

## 📥 Input

- `n, m` → number of clusters and files
- Next `m` lines describe each file:
  - First number = number of fragments
  - Followed by cluster indices containing these fragments in correct order

---

## 📤 Output

Print:
- Number of operations
- List of operations `(i, j)` meaning copy from `i` to `j`

You must not exceed `2n` operations.

---

## 💡 Key Idea

We maintain:

- A mapping of which cluster belongs to which file and position.
- A single **free cluster** used as temporary buffer.
- We move fragments into their correct final positions step by step.

The algorithm ensures that:
- No data is lost
- Each swap is simulated using a safe temporary buffer

---

## ⚙️ Algorithm (High-Level Pseudocode)
```
find one free cluster

for each file in order: for each fragment in file order: let expected_position = next correct global position

if fragment is not already in correct place:
        
        if expected_position is occupied:
            move it to free cluster

        move current fragment to expected_position
        update free cluster
```
---

## 🧪 Example

### Input

7 2 2 1 3 3 2 4 5

### Meaning
- File 1 → clusters [1, 3]
- File 2 → clusters [2, 4, 5]

Disk initially:

1: file1 2: file2 3: file1 4: file2 5: file2 6: free 7: free

### Output (example valid sequence)

3 2 6 3 2 6 3

---

## 🚀 Complexity

- Time: `O(n)`
- Memory: `O(n)`
- Operations: ≤ `2n`

---

## 📌 Summary

This problem is solved using:
- One temporary free buffer
- Greedy placement of correct fragments
- In-place simulation using copy operations

---