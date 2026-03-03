# Problem 28A – Bender Problem

## 📌 Problem Overview

Bender wants to build a closed polyline using given nails and metal rods.

- There are **n nails** placed in a given order.
- The nails form a **closed shape**.
- Each segment between consecutive nails is **parallel to the X or Y axis**.
- There are **m rods** with different lengths.
- A rod can be:
  - Bent **exactly once** at a 90° angle.
  - Attached at the bending point to one nail.
  - Its two ends connect to two adjacent nails.
- Each rod can be used **at most once**.
- Each nail can hold **at most one rod**.

The goal is to determine whether it is possible to assign rods to some nails so that:

- Exactly `n / 2` nails are used for rods.
- Rod lengths match the required length at that nail.
- No adjacent nails both use rods.
- All constraints are satisfied.

---

## 🔎 Key Observations

- Since the shape is closed and `n` is even, we must select **n/2 nails**.
- Selected nails must not be adjacent.
- This means there are only **two possible selections**:
  - All odd-indexed nails.
  - All even-indexed nails.
- For each selected nail `i`, we compute:

```

required_length[i] = length(prev_edge) + length(next_edge)

```

- We try to match each required length with an available rod.

---

## ✅ Input

```

n m
x1 y1
x2 y2
...
xn yn
r1 r2 ... rm

```

Where:

- `(xi, yi)` → Coordinates of nails.
- `ri` → Length of rods.

---

## ✅ Output

- Print `NO` if impossible.
- Otherwise:

```

YES
a1 a2 a3 ... an

```

Where:

- `ai` = index of rod used at nail `i`
- `ai = -1` if no rod is used at that nail.

---

## 💡 Example

### Input

```

4 2
0 0
0 2
2 2
2 0
4 4

```

### Output

```

YES
1 -1 2 -1

```

### Explanation

- The shape is a square.
- Each required length is 4.
- Two rods of length 4 are used.
- They are placed at alternating nails.

---

## ⚙ Solution Idea (Algorithm)

1. Read input.
2. Compute all edge lengths.
3. Compute required rod length for each nail.
4. Try two configurations:
   - Select odd-indexed nails.
   - Select even-indexed nails.
5. For each selected nail:
   - Find a rod with matching length.
   - Assign it and remove it from available rods.
6. If one configuration succeeds → Print result.
7. Otherwise → Print `NO`.

---

## ⏱ Complexity

- `O(n + m log m)`
- Works efficiently since:
  - `n ≤ 500`
  - `m ≤ 500`

---

## 🚀 Implementation

You can implement the solution using:

- `multiset` for rod matching
- Greedy matching
- Two configuration attempts

---