# Problem 456A – Laptops

## Requirement
You are given:

- An integer **n** — the number of laptops.
- **n** pairs of integers **(price, quality)** for each laptop.

If there exists **at least one pair of laptops** such that:
- one laptop is **more expensive**, and
- has **worse quality** than a cheaper laptop,

then the situation is considered **Happy Alex**.

Your task is to determine whether such a pair exists.

---

## Input
- Integer **n**
- Next **n** lines: two integers **price quality**

---

## Output
- Print `Happy Alex` if such a pair exists  
- Print `Poor Alex` otherwise

---

## Examples

### Example 1
**Input**
```

3
100 10
200 5
150 8

```

**Output**
```

Happy Alex

```

**Explanation**

- Laptop A: price 100, quality 10  
- Laptop B: price 200, quality 5  

More expensive but worse quality → condition satisfied.

---

### Example 2
**Input**
```

2
100 5
200 10

```

**Output**
```

Poor Alex

```

**Explanation**

The more expensive laptop has better quality.
No contradiction exists.

---

## Solution Idea
1. Sort all laptops by **price ascending**.
2. Traverse the sorted list:
   - Keep track of the **maximum quality** seen so far.
3. If a laptop with a **higher price** has **lower quality**
   than a previous one → print `Happy Alex`.

---

## Important Notes
- Only **one valid contradictory pair** is enough.
- Equal prices do not cause a problem.
- Sorting simplifies comparisons.

---

## Complexity
- **Time Complexity:** O(n log n)
- **Space Complexity:** O(1) or O(n)

---

## Key Insight
After sorting by price,
quality should **never decrease**.
If it does, Alex becomes happy 😄.
