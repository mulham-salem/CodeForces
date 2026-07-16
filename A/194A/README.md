# Problem 194A – Exams

## Idea

To minimize the number of failed exams (mark **2**), start by assuming every exam has the maximum mark **5**.

The current total is:

```
5 × n
```

If this total is larger than the required sum `k`, we must decrease it.

- Changing **5 → 3** decreases the total by **2** without creating a failed exam, so perform these reductions first.
- If more reduction is still needed, the only remaining option is changing **3 → 2**.
- Each **3 → 2** decreases the total by **1** and adds exactly **one failed exam**.

The remaining required decrease after all free reductions is the minimum number of failed exams.

---

## Algorithm

1. Assume every exam has mark **5**.
2. Compute the required decrease:
   - `need = 5 × n − k`
3. Use as many **5 → 3** reductions as possible.
4. Any remaining decrease must come from **3 → 2** conversions.
5. Output the number of these conversions.

---

## Pseudocode

```text
need = 5 * n - k

freeDecrease = min(need, 2 * n)
need = need - freeDecrease

answer = need

print answer
```

---

## Example 1

**Input**

```text
4 8
```

Initial marks:

```text
5 5 5 5
```

Need to decrease the total by **12**.

- Free reductions (5 → 3): decrease **8**
- Remaining decrease: **4**

So four exams must become **2**.

**Output**

```text
4
```

---

## Example 2

**Input**

```text
4 10
```

Need to decrease the total by **10**.

- Free reductions (5 → 3): decrease **8**
- Remaining decrease: **2**

Only two exams need mark **2**.

**Output**

```text
2
```

---

## Complexity

- **Time Complexity:** `O(1)`
- **Space Complexity:** `O(1)`

---