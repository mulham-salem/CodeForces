# Problem 732A – Buy a Shovel

## Requirement
You want to buy some shovels.

You are given:
- An integer **k** — the price of one shovel
- An integer **r** — the coin value you already have

You want to buy **some positive number of shovels** such that:
- The total price ends with digit **0**  
  **or**
- The total price ends with digit **r**

Your task is to find the **minimum number of shovels** you need to buy.

---

## Input
- Two integers **k** and **r**

---

## Output
- One integer — the minimum number of shovels.

---

## Examples

### Example 1
**Input**
```

117 3

```

**Output**
```

9

```

**Explanation**

Multiples of 117:
- 117 × 1 = 117 → ends with 7 ❌
- 117 × 2 = 234 → ends with 4 ❌
- 117 × 3 = 351 → ends with 1 ❌
- …
- 117 × 9 = 1053 → ends with **3** ✅

So the answer is **9**.

---

### Example 2
**Input**
```

15 2

```

**Output**
```

2

```

**Explanation**

- 15 × 1 = 15 → ends with 5 ❌
- 15 × 2 = 30 → ends with **0** ✅

So the answer is **2**.

---

## Solution Idea
- Try buying `1, 2, 3, ...` shovels.
- For each `x`, compute `k × x`.
- Check the last digit:
  - If `(k × x) % 10 == 0`
  - Or `(k × x) % 10 == r`
- The first `x` that satisfies the condition is the answer.

---

## Important Notes
- The answer is guaranteed to exist within `1` to `10`
  (because last digits repeat every 10 multiples).
- You only care about the **last digit**, not the full price.

---

## Complexity
- **Time Complexity:** `O(1)` (at most 10 checks)
- **Space Complexity:** `O(1)`

---

## Key Insight
Because only the last digit matters and digits repeat modulo 10,
checking at most 10 multiples is enough to find the minimum answer.