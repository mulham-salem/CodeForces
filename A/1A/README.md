# Problem 1A – Theatre Square

## Requirement
You are given a rectangular **theatre square** with dimensions `n` × `m` meters,  
and you have **1 × 1 meter flagstones**.  
You need to cover the square **completely with flagstones**.  

**Goal:** Find the **minimum number of flagstones** needed to cover the square completely.  
- Flagstones cannot be broken.
- They can cover the square partially outside the borders (if needed).

**Input**
- Three integers: `n`, `m`, `a`
  - `n` – length of the square
  - `m` – width of the square
  - `a` – side of the square flagstone

**Output**
- One integer: minimum number of flagstones needed

---

## Examples

### Example 1
**Input**
```

6 6 4

```
**Output**
```

4

```

**Explanation**
```

Square size: 6x6
Flagstone size: 4x4
We need 2 flagstones along length (ceil(6/4) = 2)
We need 2 flagstones along width  (ceil(6/4) = 2)
Total = 2 * 2 = 4 flagstones

```

### Example 2
**Input**
```

6 5 4

```
**Output**
```

4

```

**Explanation**
```

Length: ceil(6/4) = 2
Width:  ceil(5/4) = 2
Total = 2 * 2 = 4 flagstones

```

---

## Solution Idea
1. Divide the square dimensions by flagstone size `a`.
2. Use **ceiling division** because partially covered areas still need a full flagstone.
3. Multiply the number of flagstones along length and width.
4. Output the result.

**Mathematical formula:**
```

tiles_needed = ceil(n / a) * ceil(m / a)

````

**Implementation note:**  
- In C++: `(n + a - 1) / a` is equivalent to `ceil(n / a)` for integers.

---
