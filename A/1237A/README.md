# Problem 1237A – Balanced Rating Changes

## Requirement
You are given:

- An integer **n** — number of contests  
- An array of integers **a** of length n — rating changes for each contest  

Each rating change is either **+1** (increase) or **-1** (decrease).  

Your task is to determine whether it is possible to **arrange the contests in some order** such that **the cumulative rating never becomes negative** at any point.

---

## Input
- Integer **n** — number of contests  
- Array of integers `a1 a2 ... an` (each ai = +1 or -1)

---

## Output
- Print `"YES"` if a valid arrangement exists  
- Print `"NO"` otherwise

---

## Example 1
**Input**
```

3
1 -1 1

```

**Output**
```

YES

```

**Explanation**

One valid arrangement: `1 1 -1`  
Cumulative rating: 1 → 2 → 1 → never negative

---

## Example 2
**Input**
```

2
-1 -1

```

**Output**
```

NO

```

**Explanation**

All rating changes are negative → impossible to avoid negative cumulative rating.

---

## Solution Idea

- Count the number of `+1` and `-1` rating changes  
- If the number of `-1` changes is **greater than +1**, it may be impossible to avoid negative cumulative rating  
- Arrange all `+1` first, then `-1` → this ensures cumulative rating never negative if possible

---

## Algorithm

1. Count `count_plus = number of +1`  
2. Count `count_minus = number of -1`  
3. If `count_minus > count_plus`, print `"NO"`  
4. Otherwise, print `"YES"`

---

## Complexity
- **Time Complexity:** O(n)  
- **Space Complexity:** O(1)

---

## Key Insight
- Placing all positive changes first guarantees the cumulative rating is always non-negative  
- If negative changes outnumber positives, no valid arrangement exists.