# Problem 677A – Vanya and Fence

## Requirement
You are given:

- Two integers:
  - `n` — the number of friends
  - `h` — the height of the fence
- An array of `n` integers — heights of the friends

Each friend must go through the fence:

- If a friend's height ≤ `h` → he walks normally (width = 1)
- If a friend's height > `h` → he bends to pass (width = 2)

Your task is to determine the **total minimum width** of the road required for all friends to pass.

---

## Input
```

n h
a1 a2 a3 ... an

```

Where:
- `ai` = height of friend i

---

## Output
One integer — total width required.

---

## Explanation
- Each friend contributes:
```

width = (height > h ? 2 : 1)

```
- Sum the widths of all friends.

---

## Example 1

### Input
```

3 7
4 5 14

```

### Output
```

4

```

Explanation:
- Friend 1 → 4 ≤ 7 → width 1  
- Friend 2 → 5 ≤ 7 → width 1  
- Friend 3 → 14 > 7 → width 2  
- Total = 1 + 1 + 2 = 4

---

## Solution Idea
1. Read `n` and `h`  
2. Read heights of friends  
3. For each friend:
   - Add 1 if `height ≤ h`  
   - Add 2 if `height > h`  
4. Output sum

---

## Important Notes
- No sorting needed  
- Simple iteration  
- Only two cases for width

---

## Complexity
- **Time Complexity:** O(n)  
- **Space Complexity:** O(1)

---

## Key Insight
Each friend's width depends **only on comparison with h**.  
Sum these widths for the answer.
