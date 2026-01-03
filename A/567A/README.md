# Problem 567A – Lineland Mail

## Requirement
You are given:

- An integer `n` — number of cities.
- An array of `n` integers — positions of the cities on a straight line.

Each city lies on a line, and you need to calculate for **each city**:
- The **minimum distance** to any other city.
- The **maximum distance** to any other city.

---

## Input
```

n
x1 x2 x3 ... xn

```

Where:
- `xi` represents the position of city `i` on the line.

---

## Output
For each city `i`, print two integers:
```

minDistance maxDistance

```

One line per city.

---

## Explanation
All cities lie on a **single straight line**.

Distances are calculated as **absolute differences** between positions.

---

## Key Observations

1. After sorting the city positions:
   - The **closest city** to city `i` is either:
     - city `i - 1`
     - or city `i + 1`

2. The **farthest city** from city `i` is always:
   - the **first city**
   - or the **last city** in the sorted list

---

## How to Compute Distances

After sorting positions:

### Minimum Distance
```

min(|xi - x(i-1)|, |x(i+1) - xi|)

```

Edge cases:
- First city → only check city 2
- Last city → only check city n-1

---

### Maximum Distance
```

max(|xi - x1|, |xn - xi|)

```

---

## Example

### Input
```

4
-5 -2 2 7

```

### Output
```

3 12
3 9
4 7
5 12

```

---

## Solution Idea
1. Read `n` and the city positions.
2. Sort the positions.
3. For each city:
   - Compute minimum distance from adjacent cities.
   - Compute maximum distance from first and last city.
4. Print the results.

---

## Important Notes
- The input positions may be negative.
- Sorting is required.
- No need to check all cities for each one.

---

## Complexity
- **Time Complexity:** O(n log n) (due to sorting)
- **Space Complexity:** O(1) extra space (excluding input array)

---

## Key Insight
On a line, the nearest city must be adjacent after sorting.
The farthest city must be one of the extremes.
