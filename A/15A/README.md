# Problem 15A – Cottage Village

## 🧩 Problem Summary

We are given **n square houses** built along the x-axis.  
Each house:

- Has its center at position `x_i`
- Has side length `a_i`
- Sides are parallel to the axes
- Houses do not overlap (but may touch)

We want to place a **new square house**:

- Center must also lie on the x-axis
- Side length = `t`
- Must **touch at least one existing house**
- Must **not overlap any house**

We must compute the number of valid positions.

---

## 🔎 Key Observation

Since all houses are centered on the x-axis and aligned with it,  
the problem reduces to a **1D segment problem**.

Each house occupies an interval:

```

[x_i - a_i/2 , x_i + a_i/2]

```

The new house will also occupy an interval of length `t`.

Instead of dealing with fractions, we multiply everything by `2`:

```

left  = 2*x_i - a_i
right = 2*x_i + a_i

```

Now all calculations can be done using integers.

---

## 💡 Core Idea

1. Sort houses by their center.
2. Compute the gap between every two adjacent houses.
3. Let:

```

gap = next.left - current.right

```

Compare this gap with `2*t`.

### Cases:

- If `gap > 2*t` → 2 possible positions
- If `gap == 2*t` → 1 possible position
- If `gap < 2*t` → 0 positions

Additionally:

- There is always 1 valid position to the far left.
- There is always 1 valid position to the far right.

So we start with:

```

answer = 2

```

and add based on the gaps.

---

## 📘 Example 1

```

Input:
2 2
0 4
6 2

```

Intervals:

- House 1 → [-2, 2]
- House 2 → [5, 7]

Gap:

```

5 - 2 = 3

```

Since `3 > 2`, we add 2 positions between them.

Total:

```

2 (edges) + 2 (middle) = 4

```

---

## 📘 Example 2

```

Input:
2 2
0 4
5 2

```

Intervals:

- House 1 → [-2, 2]
- House 2 → [4, 6]

Gap:

```

4 - 2 = 2

```

Since `2 == t`, we add 1 position.

Total:

```

2 (edges) + 1 = 3

```

---

## 📘 Example 3

```

Input:
2 3
0 4
5 2

```

Gap:

```

4 - 2 = 2

```

Now `t = 3`, and `2 < 3`.

No position between houses.

Total:

```

2 (edges only)

```

---

## 🧠 Pseudocode

```

read n, t
houses = []

for i in 1..n:
read x, a
houses.push( (x, a) )

sort houses by x

segments = []

for each house:
left  = 2*x - a
right = 2*x + a
segments.push( (left, right) )

answer = 2
T = 2*t

for i in 0..n-2:
gap = segments[i+1].left - segments[i].right

```
if gap > T:
    answer += 2
else if gap == T:
    answer += 1
```

print answer

```

---

## ✅ Complexity

- Sorting: `O(n log n)`
- Single pass for gaps: `O(n)`

Overall complexity:

```

O(n log n)

```
