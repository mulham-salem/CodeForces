# Problem 707A – Brain's Photos

## Requirement
You are given a photo represented as a grid.

- Two integers **n** and **m** — the number of rows and columns.
- A grid of size **n × m**, where each cell contains a character
  representing a pixel color.

Possible colors:
- **'C'**, **'M'**, **'Y'** → color photo
- **'W'**, **'B'**, **'G'** → black & white photo

Your task is to determine whether the photo is **color** or **black & white**.

---

## Input
- Two integers **n** and **m**
- **n** lines, each containing **m characters**

---

## Output
- Print `"#Color"` if the photo is color  
- Print `"#Black&White"` if the photo is black & white

---

## Examples

### Example 1
**Input**
```

2 3
W B W
B W B

```

**Output**
```

#Black&White

```

**Explanation**

All pixels are either:
- **W** (white)
- **B** (black)

So the photo is black & white.

---

### Example 2
**Input**
```

2 2
C M
Y W

```

**Output**
```

#Color

```

**Explanation**

The photo contains:
- **C**, **M**, **Y** → color pixels

So the photo is a color photo.

---

## Solution Idea
- Read each pixel in the grid.
- If **any** pixel is one of: **C, M, Y**
  → the photo is color.
- Otherwise, it is black & white.

---

## Important Notes
- You can stop checking as soon as a color pixel is found.
- Input characters may be separated by spaces.

---

## Complexity
- **Time Complexity:** `O(n × m)`
- **Space Complexity:** `O(1)`

---

## Key Insight
The presence of **at least one color pixel** (C, M, or Y)
is enough to classify the entire photo as a color photo.
Otherwise, it is black & white.
