# Problem 224A – Parallelepiped

## Requirement
You are given:

- Three integers `S1`, `S2`, `S3`
- These integers represent the areas of three different faces of a rectangular box (parallelepiped)

Each face area is the product of two dimensions of the box.

---

## Input
```

S1 S2 S3

```

Where:
```

S1 = a × b
S2 = a × c
S3 = b × c

```

---

## Output
One integer — the sum of lengths of all edges of the parallelepiped.

---

## Explanation
A parallelepiped (rectangular box) has three dimensions:

- `a` — length
- `b` — width
- `c` — height

Each dimension appears in **4 edges**, so the total edge length is:
```

4 × (a + b + c)

```

---

## How to Find the Dimensions
From the given face areas:

```

a = sqrt((S1 × S2) / S3)
b = sqrt((S1 × S3) / S2)
c = sqrt((S2 × S3) / S1)

```

---

## Example

### Input
```

4 6 9

```

### Calculation
```

a = 2
b = 3
c = 4

```

### Output
```

36

```

---

## Solution Idea
1. Read the three face areas.
2. Extract the three dimensions using square roots.
3. Compute `4 × (a + b + c)`.
4. Print the result.

---

## Important Notes
- All dimensions are guaranteed to be integers.
- The input always forms a valid parallelepiped.
- No loops or arrays are needed.

---

## Complexity
- **Time Complexity:** O(1)
- **Space Complexity:** O(1)

---

## Key Insight
Each face area contains two dimensions.
By combining two face areas and dividing by the third, one dimension can be isolated.
Once all dimensions are known, the answer is straightforward.
