# Problem 144A – Arrival of the General

## Problem Summary
You are given a line of soldiers, each with a height.

Your goal is to:
1. Move the **tallest soldier** to the **front** of the line.
2. Move the **shortest soldier** to the **end** of the line.

### Rules
- You may only swap **adjacent** soldiers.
- You must find the **minimum number of swaps**.

---

## Key Observations
- For the **tallest soldier**, use the **first occurrence** (leftmost).
- For the **shortest soldier**, use the **last occurrence** (rightmost).
- Swapping the tallest soldier to the front may shift the shortest soldier by one position.

---

## How to Calculate the Moves

Let:
- `max_index` = index of the **first tallest** soldier
- `min_index` = index of the **last shortest** soldier
- `n` = number of soldiers

### Formula
```text
moves = max_index + (n - 1 - min_index)

if max_index > min_index:
    moves -= 1
````

---

## Example 1

**Input**

```
4
33 44 11 22
```

**Explanation**

* Tallest = 44 → index 1 → 1 move to the front
* Shortest = 11 → index 2 → 1 move to the end
* Total moves = 1 + 1 = 2

**Output**

```
2
```

---

## Example 2

**Input**

```
7
10 10 58 31 63 40 76
```

**Explanation**

* Tallest = 76 → index 6 → 6 moves
* Shortest = 10 (last one) → index 1 → 5 moves
* Initial total = 6 + 5 = 11
* Tallest is before shortest → subtract 1

**Output**

```
10
```

---

## Final Notes

* Always choose:

  * **Leftmost tallest**
  * **Rightmost shortest**
* This guarantees the minimum number of swaps.

✔️ Efficient solution
✔️ Works for all edge cases
